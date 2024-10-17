#include <iostream>
#include <string>
using namespace std;

class Employee {
    int id;
    string name;
    string department;
    float salary;

public:
    void createEmployee() {
        cout << "\tEnter Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "\tEnter Employee Name: ";
        getline(cin, name);
        cout << "\tEnter Employee Department: ";
        getline(cin, department);
        cout << "\tEnter Employee Salary: ";
        cin >> salary;
        cout << "\tEmployee record created successfully!\n";
    }

    void displayEmployee() {
        cout << "\n\tEmployee ID: " << id;
        cout << "\n\tName: " << name;
        cout << "\n\tDepartment: " << department;
        cout << "\n\tSalary: " << salary << endl;
    }

    int getEmployeeID() {
        return id;
    }

    void modifyEmployee() {
        cout << "\tEnter new Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\tEnter new Employee Department: ";
        getline(cin, department);
        cout << "\tEnter new Employee Salary: ";
        cin >> salary;
        cout << "\tEmployee record updated successfully!\n";
    }
};

class EmployeeManagementSystem {
    Employee employees[100]; // Supports up to 100 employees.
    int employeeCount = 0;

public:
    void addEmployee() {
        if (employeeCount < 100) {
            employees[employeeCount].createEmployee();
            employeeCount++;
        } else {
            cout << "\tEmployee list is full.\n";
        }
    }

    void displayAllEmployees() {
        if (employeeCount == 0) {
            cout << "\tNo employee records available.\n";
        } else {
            for (int i = 0; i < employeeCount; i++) {
                employees[i].displayEmployee();
            }
        }
    }

    void searchEmployee() {
        int id;
        cout << "\tEnter Employee ID to search: ";
        cin >> id;
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].getEmployeeID() == id) {
                employees[i].displayEmployee();
                return;
            }
        }
        cout << "\tEmployee with ID " << id << " not found.\n";
    }

    void modifyEmployee() {
        int id;
        cout << "\tEnter Employee ID to modify: ";
        cin >> id;
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].getEmployeeID() == id) {
                employees[i].modifyEmployee();
                return;
            }
        }
        cout << "\tEmployee with ID " << id << " not found.\n";
    }

    void deleteEmployee() {
        int id;
        cout << "\tEnter Employee ID to delete: ";
        cin >> id;
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].getEmployeeID() == id) {
                for (int j = i; j < employeeCount - 1; j++) {
                    employees[j] = employees[j + 1];
                }
                employeeCount--;
                cout << "\tEmployee record deleted successfully!\n";
                return;
            }
        }
        cout << "\tEmployee with ID " << id << " not found.\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n\tEmployee Management System\n";
            cout << "\t1. Add Employee\n";
            cout << "\t2. Display All Employees\n";
            cout << "\t3. Search Employee\n";
            cout << "\t4. Modify Employee\n";
            cout << "\t5. Delete Employee\n";
            cout << "\t6. Exit\n";
            cout << "\tEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    displayAllEmployees();
                    break;
                case 3:
                    searchEmployee();
                    break;
                case 4:
                    modifyEmployee();
                    break;
                case 5:
                    deleteEmployee();
                    break;
                case 6:
                    cout << "\tExiting system...\n";
                    break;
                default:
                    cout << "\tInvalid choice. Try again.\n";
                    break;
            }
        } while (choice != 6);
    }
};

int main() {
    EmployeeManagementSystem ems;
    ems.menu();
    return 0;
}

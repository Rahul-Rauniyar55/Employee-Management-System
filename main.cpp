#include <bits/stdc++.h>
using namespace std;

// Employee class definition
class Employee
{
public:
    string name;
    int id;
    double salary;

    Employee(string name, int id, double salary)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
    }
};

// Function to add an employee to the system
void addEmployee(vector<Employee> &employees)
{
    string name;
    int id;
    double salary;

    cout << "Enter employee name: ";
    cin >> name;

    cout << "Enter employee ID: ";
    cin >> id;

    cout << "Enter employee salary: ";
    cin >> salary;

    Employee newEmployee(name, id, salary);
    employees.push_back(newEmployee);

    cout << "Employee added successfully!" << endl;
}

// Function to display all employees in the system
void displayEmployees(const vector<Employee> &employees)
{
    cout << "Employee List:" << endl;
    for (const auto &employee : employees)
    {
        cout << "Name: " << employee.name << endl;
        cout << "ID: " << employee.id << endl;
        cout << "Salary: " << employee.salary << endl;
        cout << "---------------------------" << endl;
    }
}

// Function to remove an employee from the system
void removeEmployee(vector<Employee> &employees)
{
    int id;
    cout << "Enter employee ID to remove: ";
    cin >> id;
    auto it = find_if(employees.begin(), employees.end(), [id](const Employee &e)
                      { return e.id == id; });

    if (it != employees.end())
    {
        employees.erase(it);
        cout << "Employee removed successfully!" << endl;
    }
    else
    {
        cout << "Employee not found!" << endl;
    }
}

int main()
{
    vector<Employee> employees;
    int choice;

    while (true)
    {
        cout << "Employee Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Remove Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee(employees);
            break;
        case 2:
            displayEmployees(employees);
            break;
        case 3:
            removeEmployee(employees);
            break;
        case 4:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

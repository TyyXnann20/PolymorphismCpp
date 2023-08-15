#include <iostream>
#include <string>
using namespace std;
const int MAX_EMPLOYEES = 100;

class Employee {
	protected:
		string name;
		int id;
		string sex;
		static int GenId;
	public:
		Employee() : id(GenId++) {}
		virtual void input() {
			cout << "Enter name: ";
			cin >> name;
			cout <<"Enter Sex :";cin>>sex;
		}
		virtual void output() {
			cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
		}
		virtual void display() = 0;
};
int Employee::GenId = 1001;

class WagedEmployee : public virtual Employee {
protected:
    float amount;
    int rate;
public:
    virtual void input() {
        Employee::input();
        cout << "Enter wage: ";
        cin >> amount;
        cout << "Enter hours: ";
        cin >> rate;
    }
    virtual void output() {
        Employee::output();
        cout << "Wage: " << amount << endl;
        cout << "Hours: " << rate << endl;
        cout << "Total: " << amount * rate << endl;
    }
    virtual void display() {
        cout << "===== Waged Employee =====" << endl;
        output();
    }
};

class SalariedEmployee : public virtual Employee {
protected:
    float salary;
public:
    virtual void input() {
        Employee::input();
        cout << "Enter salary: ";
        cin >> salary;
    }
    virtual void output() {
        Employee::output();
        cout << "Salary: " << salary << endl;
    }
    virtual void display() {
        cout << "===== Salaried Employee =====" << endl;
        output();
    }
};

class SalaryWagedEmployee : public SalariedEmployee, public WagedEmployee {
public:
    virtual void input() {
        SalariedEmployee::input();
        WagedEmployee::input();
    }

    virtual void output() {
        SalariedEmployee::output();
        WagedEmployee::output();
    }
    
    virtual void display() {
        cout << "===== Salary-Waged Employee ======" << endl;
        output();
    }
};


int main() {
    Employee* employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    while (true) {
        cout << "1. Add waged employee" << endl;
        cout << "2. Add salaried employee" << endl;
        cout << "3. Add salary-waged employee" << endl;
        cout << "4. Display employees by salary type" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                if (numEmployees < MAX_EMPLOYEES) {
                    WagedEmployee* emp = new WagedEmployee();
                    emp->input();
                    employees[numEmployees++] = emp;
                }
                else {
                    cout << "The array is full. Cannot add more employees." << endl;
                }
                break;
            }
            case 2: {
                if (numEmployees < MAX_EMPLOYEES) {
                    SalariedEmployee* emp = new SalariedEmployee();
                    emp->input();
                    employees[numEmployees++] = emp;
                }
                else {
                    cout << "The array is full. Cannot add more employees." << endl;
                }
                break;
            }
            case 3: {
                if (numEmployees < MAX_EMPLOYEES) {
                    SalaryWagedEmployee* emp = new SalaryWagedEmployee();
                    emp->input();
                    employees[numEmployees++] = emp;
                }
                else {
                    cout << "The array is full. Cannot add more employees." << endl;
                }
                break;
            }
            case 4: {
                cout << "1. Waged Employees" << endl;
                cout << "2. Salaried Employees" << endl;
                cout << "3. Salary-Waged Employees" << endl;
                cout << "Enter your choice: ";
                int salaryTypeChoice;
                cin >> salaryTypeChoice;
                for (int i = 0; i < numEmployees; i++) {
                    if ((salaryTypeChoice == 1 && dynamic_cast<WagedEmployee*>(employees[i]) != 0 && dynamic_cast<SalaryWagedEmployee*>(employees[i]) == 0) ||
                        (salaryTypeChoice == 2 && dynamic_cast<SalariedEmployee*>(employees[i]) != 0 && dynamic_cast<SalaryWagedEmployee*>(employees[i]) == 0) ||
                        (salaryTypeChoice == 3 && dynamic_cast<SalaryWagedEmployee*>(employees[i]) != 0)) {
                        employees[i]->display();
                        cout << "------------------" << endl;
                    }
                }

                break;
            }
            case 5: {
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
}



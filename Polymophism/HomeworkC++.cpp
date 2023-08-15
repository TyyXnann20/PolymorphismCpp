#include<iostream>
#include<conio.h>
using namespace std;
class Employee{
	private:
		int id;
		string name;
		string sex;
		static int genID;
	public:
		int type;
		Employee()
		{
			id = genID++;
		}
		virtual void getData() = 0;
		virtual void display()= 0;
		virtual void input();
		virtual void output() 
		{
			cout<<id<<"\t"<<name<<"\t"<<sex<<"\t";	
		} 
};
int Employee::genID = 1;
void Employee::getData(){}
void Employee::display(){}
void Employee::input(){
	cout<<"Input Employee Name     : "; cin>>name;
	cout<<"Input Employee Gender   : "; cin>>sex;
}
class Salary_Employee: public virtual Employee{
	protected:
		float salary;
	public:
		void getData()
		{
			Employee::input();
			cout<<"Input Salary = "; cin>>salary;
			type = 1;
		}
		void display()
		{
			Employee::output();
			cout<<salary;
		}
};
class Waged_Salary: public virtual Employee,public virtual Salary_Employee{
	protected:
		float amount;
		float rate;
	public:
		void getData()
		{
			Employee::input();
			cout<<"Input Amount = "; cin>>amount;
			cout<<"Input Rate   = "; cin>>rate;
			type = 2;
		}
		void display() 
		{
			Employee::output();
			cout<<salary<<"\t"<<amount<<"\t"<<rate<<"\t"<<amount*rate;
		}
		
};
class Salary_Waged_Employee: public virtual Salary_Employee,public virtual Waged_Salary{
	protected:
		float total;
	public:
		void getData()
		{
			cout<<"==========Input Salary Part=========="<<endl;
			Salary_Employee::getData();
			cout<<"==========Input Waged  Part==========="<<endl;
			Waged_Salary::getData();
			total = amount * rate;
			type = 3;	
		}	
		void display() 	
		{
			Waged_Salary::display();
			cout<<total<<endl;
		}
};

int main()
{
	int n,i;
	int type;
	cout<<"Input Number of Employee : "; cin>>n;
	
	Employee **employees = new Employee*[n];
	
	for(i=0 ; i<n ; i++)
	{
		cout<<"===================Menu=================="<<endl;
		cout<<"\t1.Employee Salary "<<endl;
		cout<<"\t2.Employee Waged  "<<endl;
		cout<<"\t3.Salary and Waged"<<endl;
		cout<<"Please choose your choice = "; cin>>type;
		switch(type)
		{
			case 1:
			{
				employees[i] = new Salary_Employee();
				employees[i]->getData();
			}break;
			case 2:
			{
				employees[i] = new Waged_Salary();
				employees[i]->getData();
			}break;
			case 3:
			{
				employees[i]  = new Salary_Waged_Employee();
				employees[i]->getData(); 
			}break;
		}
	}
	do
	{
		char op;
		cout<<"=================Output Data=============="<<endl;
		cout<<"A.Output Salaried Employee"<<endl;
		cout<<"B.Output Waged Employee "<<endl;
		cout<<"C.Output Salaried_waged Employee"<<endl;
		cout<<"D.Output All type"<<endl;
		cout<<"Choose Your choice = "; cin>>op;
		switch(op)
		{
			case 'a':
			{
				cout<<"ID\tName\tGender\tSalary\n"<<endl;
				for(int i=0 ; i<n ; i++)
				{
					employees[i]->display();
					cout<<endl;	
				}
			}break;
			case 'b':
			{
				cout<<"ID\tName\tGender\tSalary\tAmount\tRate\tIncome"<<endl;
				for(int i=0 ; i<n ; i++)
				{
					if(employees[i]->type == 2)
					{
						employees[i]->display();
						cout<<endl;
					}
				}
			}break;
			case 'c':
			{
				cout<<"ID\tName\tGender\tSalary\tAmount\tRate\tIncome"<<endl;
				for(int i=0 ; i<n ;i++)
				{
					if(employees[i]->type == 3)
					{
						employees[i]->display();
						cout<<endl;
					}
				}
			}break;
			case 'd':
			{
				cout<<"ID\tName\tGender\tSalary\tAmount\tRate\tIncome"<<endl;
				for(int i=0 ;i<n ; i++)
				{
					employees[i]->display();
				}
			}break;
		}
	}while(getch()==13);
	
	
	
	return 0;
}

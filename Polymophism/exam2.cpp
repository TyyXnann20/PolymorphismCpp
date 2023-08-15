#include <iostream>
#include <cstring>
using namespace std;
class Worker
{
private:
    int code;
    char name[25];
    float salary;
    static float rate;
    int hour;

public:
    Worker(int code = 0, char *name = "Som Dara", float salary = 0.0, int hour = 0)
    {
        this->code = code;
        strcpy(this->name, name);
        this->salary = salary;
        this->hour = hour;
    }
    // Other member functions
    double Income()
    {
        return salary + rate * hour;
    }

    static void setRate(float r)
    {
        rate = r;
    }

    friend istream &operator>>(istream &in, Worker &obj);
    friend ostream &operator<<(ostream &out, Worker &obj);
    friend Worker operator+(Worker &obj, float amount);
    friend int operator>(Worker &obj1, Worker &obj2);
    friend void updateIncome(Worker &obj);
};

float Worker::rate = 1;

istream &operator>>(istream &in, Worker &obj)
{
    cout << "Enter code: ";
    in >> obj.code;
    cout << "Enter name: ";
    in >> obj.name;
    cout << "Enter salary: ";
    in >> obj.salary;
    cout << "Enter hour: ";
    in >> obj.hour;
    return in;
}

ostream &operator<<(ostream &out, Worker &obj)
{
    out << "Code: " << obj.code << endl;
    out << "Name: " << obj.name << endl;
    out << "Salary: " << obj.salary << endl;
    out << "Hour: " << obj.hour << endl;
    
    return out;
}

Worker operator+(Worker &obj, float amount)
{
    obj.salary += amount;
    return obj;
}

int operator>(Worker &obj1, Worker &obj2)
{
    return obj1.Income() > obj2.Income();
}

void updateIncome(Worker &obj)
{
    if (obj.Income() < 120)
    {
        obj.salary = obj.salary * 1.15; // Increase salary by 15%
        obj.hour = obj.hour * 1.15; // Increase hour by 15%
    }
}

int main()
{
    Worker w1;
    cin >> w1;
    // Using the setRate static function
    //Worker::setRate(10.0);
    cout << w1;
	cout << "Income Before: " << w1.Income() << endl;

    // Using the + operator && the > operator
    Worker w2 = w1 + 100.0;
    int isGreater = w1 > w2;
    cout << "w1 is greater than w2: " << isGreater << endl;
    // Using the updateIncome function
    updateIncome(w1);
	cout << "Income After: " << w1.Income() << endl;
    cout<<w1;
    return 0;
}

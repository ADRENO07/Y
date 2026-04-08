Perfect 👍 this is a full exam-level assignment. I’ll give you a simple, clean, beginner-style solution using:

inheritance ✔️

multilevel inheritance ✔️

static (auto id) ✔️

menu-driven ✔️

no over-smart code ✔️



---

✅ employee.h

#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
protected:
    int emp_id;
    char name[20];
    static int count;

public:
    Employee();
    Employee(char[]);

    virtual void accept();
    virtual void display();
};


---

✅ employee.cpp

#include "employee.h"

int Employee::count = 0;

Employee::Employee()
{
    emp_id = ++count;
    strcpy(name, "NA");
}

Employee::Employee(char n[])
{
    emp_id = ++count;
    strcpy(name, n);
}

void Employee::accept()
{
    cout << "Enter name: ";
    cin >> name;
}

void Employee::display()
{
    cout << "ID: " << emp_id << endl;
    cout << "Name: " << name << endl;
}


---

✅ wageemp.h

#include "employee.h"

class WageEmployee : public Employee
{
protected:
    int hours, rate;

public:
    WageEmployee();

    void accept();
    void display();
};


---

✅ wageemp.cpp

#include "wageemp.h"

WageEmployee::WageEmployee()
{
    hours = rate = 0;
}

void WageEmployee::accept()
{
    Employee::accept();
    cout << "Enter hours and rate: ";
    cin >> hours >> rate;
}

void WageEmployee::display()
{
    Employee::display();
    cout << "Salary: " << hours * rate << endl;
}


---

✅ salesperson.h

#include "wageemp.h"

class SalesPerson : public WageEmployee
{
    int sales, commission;

public:
    SalesPerson();

    void accept();
    void display();
};


---

✅ salesperson.cpp

#include "salesperson.h"

SalesPerson::SalesPerson()
{
    sales = commission = 0;
}

void SalesPerson::accept()
{
    WageEmployee::accept();
    cout << "Enter sales and commission: ";
    cin >> sales >> commission;
}

void SalesPerson::display()
{
    WageEmployee::display();
    cout << "Extra Salary: " << sales * commission << endl;
}


---

✅ manager.h

#include "employee.h"

class Manager : public Employee
{
    int allowance;

public:
    Manager();

    void accept();
    void display();
};


---

✅ manager.cpp

#include "manager.h"

Manager::Manager()
{
    allowance = 0;
}

void Manager::accept()
{
    Employee::accept();
    cout << "Enter allowance: ";
    cin >> allowance;
}

void Manager::display()
{
    Employee::display();
    cout << "Allowance: " << allowance << endl;
}


---

✅ client.cpp (MENU DRIVEN)

#include "wageemp.h"
#include "salesperson.h"
#include "manager.h"

int main()
{
    int choice;

    do
    {
        cout << "\n1. Wage Employee";
        cout << "\n2. Sales Person";
        cout << "\n3. Manager";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            WageEmployee w;
            w.accept();
            w.display();
        }
        else if(choice == 2)
        {
            SalesPerson s;
            s.accept();
            s.display();
        }
        else if(choice == 3)
        {
            Manager m;
            m.accept();
            m.display();
        }

    } while(choice != 0);

    return 0;
}


---

🔥 What your teacher wants to see

✅ Auto ID

static int count;
emp_id = ++count;


---

✅ Multilevel inheritance

Employee → WageEmployee → SalesPerson


---

✅ Separate inheritance

Employee → Manager


---

✅ Menu-driven logic

✔ simple if-else
✔ object created inside case


---

🎯 VIVA QUESTIONS (VERY IMPORTANT)

👉 Why static count?

> To generate unique employee id automatically.




---

👉 What type of inheritance used?

> Multilevel and hierarchical.




---

👉 Why virtual?

> To allow overriding.




---

👉 Difference Manager vs WageEmployee?

> Manager directly inherits Employee, WageEmployee adds salary logic.




---

🚀 FINAL RESULT

✔ covers full assignment
✔ simple code
✔ matches teacher style
✔ no advanced tricks
✔ safe for submission


---

If you want next: 👉 I can add polymorphism (pointer-based version)
👉 or give expected output + sample run

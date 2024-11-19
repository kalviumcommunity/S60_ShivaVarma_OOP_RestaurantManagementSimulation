#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

class MenuItem
{
private:
    string name;
    string category;
    double price;

public:
    void setMenuItem(string n, string c, double p)
    {
        this->name = n;
        this->category = c;
        this->price = p;
    }

    void display()
    {
        cout << "Item: " << this->name << endl
             << "  Category: " << this->category << endl
             << "  Price: " << this->price << endl;
    }
};

class Employee
{
private:
    string name;
    string role;
    double salary;

public:
    Employee(string n, string r, double s)
    {
        this->name = n;
        this->role = r;
        this->salary = s;
    }

    void display()
    {
        cout << "Employee: " << this->name << endl
             << "  Role: " << this->role << endl
             << "  Salary: " << this->salary << endl;
    }
};

class Restaurant
{
private:
    string name;
    vector<MenuItem *> menu;
    vector<Employee *> employees;
    static int restaurantCount;

public:
    Restaurant()
    {
        restaurantCount++;
    }

    void setRestaurantName(string n)
    {
        this->name = n;
    }

    void addMenuItem(MenuItem *item)
    {
        menu.push_back(item);
    }

    void addEmployee(Employee *emp)
    {
        employees.push_back(emp);
    }

    void displayRestaurant()
    {
        cout << "Restaurant Name: " << this->name << endl;
        cout << "Menu: " << endl;
        for (int i = 0; i < menu.size(); i++)
        {
            cout << i + 1 << ".";
            menu[i]->display();
        }
        cout << "Employees: " << endl;
        for (int i = 0; i < employees.size(); i++)
        {
            cout << i + 1 << ".";
            employees[i]->display();
        }
    }

    static int getRestaurantCount()
    {
        return restaurantCount;
    }
};

int Restaurant::restaurantCount = 0;

int main()
{
    int numRestaurants;

    cout << "Enter the number of restaurants to create: ";
    cin >> numRestaurants;
    cin.ignore();

    for (int r = 0; r < numRestaurants; r++)
    {
        Restaurant *myRestaurant = new Restaurant();

        string restaurantName;
        int numMenuItems, numEmployees;

        cout << "Enter Restaurant Name: ";
        getline(cin, restaurantName);
        myRestaurant->setRestaurantName(restaurantName);

        cout << "Enter the number of menu items: ";
        cin >> numMenuItems;

        for (int i = 0; i < numMenuItems; i++)
        {
            string name;
            string category;
            double price;
            cout << "Enter details for Menu Item " << i + 1 << ":" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Category: ";
            getline(cin, category);
            cout << "Price: ";
            cin >> price;

            MenuItem *item = new MenuItem();
            item->setMenuItem(name, category, price);
            myRestaurant->addMenuItem(item);
        }

        cout << "Enter the number of employees: ";
        cin >> numEmployees;
        for (int i = 0; i < numEmployees; i++)
        {
            string name;
            string role;
            double salary;
            cout << "Enter details for Employee " << i + 1 << ":" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Role: ";
            getline(cin, role);
            cout << "Salary: ";
            cin >> salary;

            Employee *emp = new Employee(name, role, salary);
            myRestaurant->addEmployee(emp);
        }

        myRestaurant->displayRestaurant();

        delete myRestaurant;
    }

    cout << "Total number of restaurants created: " << Restaurant::getRestaurantCount() << endl;

    return 0;
}
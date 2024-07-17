/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Lab Assessment: 2
  Author: Tran Thanh Tu
  ID: S3957386
  Compiler used: 8.1.0
  Created  date: 24/12/2022
  Acknowledgement: List the resources that you use to complete this assessment (write 'None' if you don't use any).
*/
#include <iostream>
using std::cin;
using std::cout;
using std::string;

class Customer
{
private:
    string name;
    int expense;
    int bonus;
    Customer *nextCustomer;

public:
    Customer(string nameVal = "", int expenseVal = 0)
        : name(nameVal), expense(expenseVal), bonus(0), nextCustomer(nullptr) {}
    // get private value
    string getName()
    {
        return name;
    }
    int getExpense()
    {
        return expense;
    }
    Customer *getNext()
    {
        return nextCustomer;
    }
    int getBonus()
    {
        return bonus;
    }
    // set private values
    void setBonus(int bonusVal)
    {
        bonus = bonusVal;
    }
    void setName(string nameVal)
    {
        name = nameVal;
    }
    void setExpense(int expenseVal)
    {
        expense = expenseVal;
    }
    void setNext_customer(Customer *next)
    {
        nextCustomer = next;
    }
};
void links(Customer *head)
{
    Customer *temp = head;
    while (temp != nullptr)
    {
        {
            cout << temp->getName() << "(" << temp->getExpense() << ") -->";
            temp = temp->getNext();
        }
    }
}
void largest_Expense(Customer *head) // finding the one who has largest expense
{
    Customer *temp = head;
    string Max_Expense = "";
    int largest_expense = 0;
    while (temp != nullptr)
    {

        if (temp->getExpense() > largest_expense)
        {
            largest_expense = temp->getExpense();
            Max_Expense = temp->getName();
        }
        temp = temp->getNext();
    }
    cout << "customer with largest expense is: " << Max_Expense << std::endl;
}
void Bonus(Customer *head)
{ // calculating bonus
    Customer *temp = head;
    while (temp != nullptr)
    {
        int bonus = 0;
        Customer *temp2 = temp->getNext();
        while (temp2 != nullptr)
        {
            bonus += temp2->getExpense() * 0.02;
            temp2 = temp2->getNext();
        }
        temp->setBonus(temp->getExpense() * 0.05 + bonus);
        temp = temp->getNext();
    }
}
int main()
{
    // declare function using HEAP
    Customer *peter = new Customer("Peter", 1000);
    Customer *john = new Customer("John", 200);
    Customer *harry = new Customer("Harry", 1200);
    Customer *luna = new Customer("Luna", 400);
    peter->setNext_customer(john);
    john->setNext_customer(harry);
    harry->setNext_customer(luna);
    largest_Expense(peter); // call function largest expense in main function
    Bonus(peter);
    Customer *temp = peter;
    while (temp != nullptr)
    {
        cout << temp->getName() << " : " << temp->getBonus() << std::endl;
        temp = temp->getNext();
    }
    return 0;
}
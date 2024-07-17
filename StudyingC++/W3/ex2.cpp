/*Define a class namely Student with attributes are name (string) and score (integer). Both of them are public.
a.	Write a constructor for the class to initialize attributes’ values.
b.	Create two student objects and initialize values for them using class constructor. Print out all information of the two students.
c.	Create an array of three students and initialize values for all of them using class constructor. Print out information of the student with highest score.
Additional: modify the program so that score is private, and make a method namely get_score() to provide reading access to it.*/

#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::string;
class Student
{
private:
    int score;

public:
    std::string name;

    Student(string nameVal = "", int scoreVal = 0)
        : name(nameVal), score(scoreVal) {}
    int getScore()
    {
        return score;
    }

    void studentif()
    {
        cout << "Student name is: " << name << std::endl;
        cout << "Student score is: " << score << std::endl;
    }
};

int main()
{
    int max = 0, maxnum = 0;
    // Student st1("Tu", 10);
    // st1.studentif();

    // Student st2("Ning", 9);
    // st2.studentif();

    Student lstud[3] = {Student("Quy Nguyen", 7),
                        Student("Duy Huynh", 8),
                        Student("Lini", 9)};
    for (int i = 0; i < 3; i++)
    {
        cout << "student " << i + 1 << std::endl
             << "Name: " << lstud[i].name << std::endl
             << "Score: " << lstud[i].getScore() << std::endl;
        if (lstud[i].getScore() > max)
        {
            max = lstud[i].getScore();
            maxnum = i;
        }
    }
    cout << "Student have the highest score is " << lstud[maxnum].name << " with " << lstud[maxnum].getScore();
    return 0;
}
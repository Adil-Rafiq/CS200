#include <iostream>
#include <fstream>
using namespace std;

class Students
{
private:
    string name;
    int roll_num;
    double marks;
    char grade;

public:
    void
    inputStudentInfo(Students[], int);
    void sort(Students[], int);
    void assignGrade(Students[], int);
    void writeToFile(Students[], int);
    void print();
};

void swap(Students[], int, int);

int main()
{
    // to find the file size
    int size = 0;
    string s;
    ifstream file("students_info.txt");
    while (file.eof() == 0)
    {
        getline(file, s);
        size++;
    }
    file.close();

    Students students[size], info;
    students->inputStudentInfo(students, size);
    students->sort(students, size);
    students->assignGrade(students, size);
    students->writeToFile(students, size);

    return 0;
}

void Students::inputStudentInfo(Students students[], int size)
{
    ifstream file("students_info.txt");
    for (int i = 0; i < size; i++)
    {
        file >> students[i].name;
        file >> students[i].roll_num;
        file >> students[i].marks;
    }

    file.close();
}

void Students::sort(Students students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int smallest = i;
        for (int j = i; j < size; j++)
        {
            if (students[j].marks < students[smallest].marks)
            {
                smallest = j;
            }
        }

        swap(students, i, smallest);
    }
}

void Students::assignGrade(Students students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (students[i].marks >= 85)
            students[i].grade = 'A';
        else if (students[i].marks >= 75 && students[i].marks < 85)
            students[i].grade = 'B';
        else if (students[i].marks >= 65 && students[i].marks < 75)
            students[i].grade = 'C';
        else if (students[i].marks >= 50 && students[i].marks < 65)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

void Students::writeToFile(Students students[], int size)
{
    ofstream grades("grades.txt");
    for (int i = 0; i < size; i++)
    {
        grades << students[i].name << " "
               << students[i].roll_num << " "
               << students[i].marks << " "
               << students[i].grade << endl;
    }

    grades.close();
}

void Students::print()
{
    cout << "Name: " << name << endl;
    cout << "Roll number: " << roll_num << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << grade << endl;
}

void swap(Students students[], int i, int smallest)
{
    Students temp = students[i];
    students[i] = students[smallest];
    students[smallest] = temp;
}


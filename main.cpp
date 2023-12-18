/*                                                               ***
 * ***     This program manages student data by calculating the average test score and assigning
          letter grades based on user-inputted information. It offers flexibility in handling varying
          class sizes and test criteria. The program prompts for student details, including names,
          ID numbers, and test scores, and displays the results in an organized format. It utilizes dynamic
          memory allocation and modular functions for efficient data processing and readability.1
 * ***                                                                ***
 * *********************************************************************/



#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    string name;
    string idNum;
    int numTests;
    int* scores;
    double average;
    char grade;
};

// Function to calculate the average test score for a student
void computeAverage(Student& student) {
    double total = 0;
    for (int i = 0; i < student.numTests; i++) {
        total += student.scores[i];
    }
    student.average = total / student.numTests;
}


// Function to calculate the course grade for each student
void CalGrade(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        computeAverage(students[i]);

        // Assigning letter grades based on the average score
        char grade;
        if (students[i].average >= 91) {
            grade = 'A';
        } else if (students[i].average >= 81) {
            grade = 'B';
        } else if (students[i].average >= 71) {
            grade = 'C';
        } else if (students[i].average >= 61) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        students[i].grade = grade;
    }
}


// Function to print the details of a student
void printStudentDetails(Student& student) {
    cout << "Name: " << student.name << endl;
    cout << "ID Number: " << student.idNum << endl;
    cout << "Average Test Score: " << student.average << endl;
    cout << "Course Grade: " << student.grade << endl;
    cout << endl;
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Dynamically allocate an array of structs to store student information
    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> students[i].name;

        cout << "Enter the ID number of " << students[i].name << ": ";
        cin >> students[i].idNum;

        cout << "Enter the number of tests for " << students[i].name << ": ";
        cin >> students[i].numTests;

        // Dynamically allocate an array of integers for each student to store test scores
        students[i].scores = new int[students[i].numTests];

        cout << "Enter the test scores for " << students[i].name << ":" << endl;
        for (int j = 0; j < students[i].numTests; j++) {
            cout << "Score " << j + 1 << ": ";
            cin >> students[i].scores[j];
        }
        cout << endl;
    }

    CalGrade(students, numStudents);

    for (int i = 0; i < numStudents; i++) {
        printStudentDetails(students[i]);
    }

    // Clean up memory
    for (int i = 0; i < numStudents; i++) {
        delete[] students[i].scores;
    }
    delete[] students;

    return 0;
}


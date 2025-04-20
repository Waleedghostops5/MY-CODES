#include <iostream>
#include <fstream>
#include<string>
using namespace std;

// A CODE BY MUHAMMAD WALEED REHAN

void addstudent() {
    ofstream file("record.txt", ios::app);
    string name, roll, depart;
    float gpa;

    cin.ignore();
    cout << "STUDENT NAME: ";
    getline(cin, name);
    cout << "ROLL NO: ";
    getline(cin, roll);
    cout << "DESIRED DEPARTMENT: ";
    getline(cin, depart);
    cout << "CURRENT GPA: ";
    cin >> gpa;

    file << name << "," << roll << "," << depart << "," << gpa << endl;
    file.close();
    cout << "STUDENT ENROLLED.\n";
}

void viewstudents() {
    ifstream file("record.txt");
    string name, roll, dept;
    float gpa;

    cout << "\nNAME\tROLL\tDEPARTMENT\tGPA\n";
    cout << "-----------------------------\n";

    while (getline(file, name, ',') &&
        getline(file, roll, ',') &&
        getline(file, dept, ',') &&
        file >> gpa) {
        file.ignore();
        cout << name << "\t" << roll << "\t" << dept << "\t" << gpa << endl;
    }

    file.close();
}

void searchstudent() {
    ifstream file("record.txt");
    string name, roll, dept, searchroll;
    float gpa;
    bool found = false;

    cout << "ENTER ROLL NO: ";
    cin >> searchroll;

    while (getline(file, name, ',') &&
        getline(file, roll, ',') &&
        getline(file, dept, ',') &&
        file >> gpa) {
        file.ignore();
        if (roll == searchroll) {
            cout << "RECORD FOUND: " << name << " " << roll << " " << dept << " " << gpa << endl;
            found = true;
            break;
        }
    }

    file.close();
    if (!found)
        cout << "STUDENT RECORD NOT FOUND.\n";
}

void updategpa() {
    ifstream file("record.txt");
    ofstream temp("temp.txt");
    string name, roll, dept, searchroll;
    float gpa;
    bool found = false;

    cout << "ENTER ROLL NO: ";
    cin >> searchroll;

    while (getline(file, name, ',') &&
        getline(file, roll, ',') &&
        getline(file, dept, ',') &&
        file >> gpa) {
        file.ignore();
        if (roll == searchroll) {
            cout << "KINDLY ENTER UPDATED GPA: ";
            cin >> gpa;
            found = true;
        }
        temp << name << "," << roll << "," << dept << "," << gpa << endl;
    }

    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "gpa updated.\n";
    else
        cout << "student not found.\n";
}

void deletestudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    string name, roll, dept, searchroll;
    float gpa;
    bool found = false;

    cout << "enter roll number to delete: ";
    cin >> searchroll;

    while (getline(file, name, ',') &&
        getline(file, roll, ',') &&
        getline(file, dept, ',') &&
        file >> gpa) {
        file.ignore();
        if (roll != searchroll)
            temp << name << "," << roll << "," << dept << "," << gpa << endl;
        else
            found = true;
    }

    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "student deleted.\n";
    else
        cout << "student not found.\n";
}

int main() {
    int choice;

    cout << "\t\t\t\t\t\tSTUDENT MANAGEMENT SYSTEM"<<endl;
    cout << "\t\t\t\t\t    A PROJECT BY MUHAMMAD WALEED REHAN" << endl;

    do {
        cout << "I.   ADD NEW STUDENT" << endl;
        cout << "II.  VIEW STUDENTS" << endl;
        cout << "III. SEARCH RECORD" << endl;
        cout << "IV.  NEW GPA" << endl;
        cout << "V.   DELETE RECORD" << endl;
        cout << "VI.  CLOSE" << endl;
        cout << "PLEASE ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
        case 1: addstudent(); break;
        case 2: viewstudents(); break;
        case 3: searchstudent(); break;
        case 4: updategpa(); break;
        case 5: deletestudent(); break;
        case 6: cout << "goodbye!\n"; break;
        default: cout << "invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
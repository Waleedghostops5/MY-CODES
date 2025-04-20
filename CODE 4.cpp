#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void saveToFile(const string& s, const string& filename = "output.txt");

int main() {
    string userInput;
    cout << "Enter string: ";
    getline(cin, userInput);

    saveToFile(userInput); 
    return 0;
}

void saveToFile(const string& s, const string& filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        outputFile << s << endl; 
        outputFile.close();      
        cout << "String successfully saved to " << filename << endl;
    }
    else {
        cout << "Error opening file " << filename << endl;
    }
}
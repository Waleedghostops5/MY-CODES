#include <iostream>
#include <string> 

// A CODE BY MUHAMMAD WALEED REHAN
using namespace std;

void myfunction(const char x[]) {
    for (int i = 0; x[i] != '\0'; ++i) {
        cout << x[i];
    }
    cout << endl;
}

int main() {
    const int SIZE = 10;
    char arr[SIZE];
    cout << "Enter a string (up to " << SIZE - 1 << " characters): ";
    cin.getline(arr, SIZE);

    myfunction(arr);

    return 0;
}
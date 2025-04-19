#include <iostream>
using namespace std;

int myfunction(char x[8]);

int main()
{
    char a[8];
    for (int i = 0; i < 8; i++)  
    {
        cin >> a[i];
    }
    int number = myfunction(a);
    cout << "TOTAL NUMBER OF VOWELS ARE: " << number;
    return 0;
}

int myfunction(char a[8])
{
    int num = 0;
    for (int i = 0; i < 8; i++)  
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ||
            a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U') {
            num++;
        }
    }
    return num;
}

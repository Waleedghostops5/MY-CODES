#include <iostream>
using namespace std;

// A CODE BY MUHAMMAD WALEED REHAN

int myfunction(char x[8]);
int main() 
{
	char a[8];
	for (int i = 0; i <= 7; i++)
	{
		cin >> a[i];
	}
	int number = myfunction(a);
	cout << "TOTAL NUMBER OF VOVELS ARE: " << number;
	return 0;
}
int myfunction(char a[8])
{
	int num = 0;
	for (int i = 0; i <= 7; i++) 
	{
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
			num++;
		}
	}
	return num;
}

#include<iostream>

using namespace std;

// A CODE BY MUHAMMAD WALEED REHAN

int main()
{
	string str[10];
	cout << "Enter a string " << endl;
	for (int i = 0;i < 10;i++)
	{
		cin >> str[i];
	}
	
	cout << "Reversed Array is"  ;
	revarray(str, 10);


}
void revarray(string arr[], int size)
{
	for (int i = 9;i >= 0;i--)
	{
		cout << arr[i];
	}
	
}
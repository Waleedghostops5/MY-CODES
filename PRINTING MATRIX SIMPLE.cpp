#include<iostream>
using namespace std;

int main()
{
	const int row = 2;
	const int coloumn = 2;
	int array[row][coloumn] = { {1,2},{3,4} };
	cout << array[0][0];
	cout << array[0][1] << endl;
	cout << array[1][0];
	cout << array[1][1];
	return 0;
}
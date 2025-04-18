#include<iostream>
using namespace std;

// A CODE BY MUHAMMAD WALEED REHAN

int myfunction(int a[5])
{
	int sum = 0;
	
	for (int k = 0;k < 5;k++)
	{
		sum += a[k];
	}
	return sum;
}

int main()
{
	int arr[5] = { 2,4,6,8,10 },result;
	
	result=myfunction(arr);
	
	cout << "SUM OF ALL ELEMENTS: " << result;
	
}
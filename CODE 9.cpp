#include<iostream>
using namespace std;

// A CODE BY MUHAMMAD WALEED REHAN 

void copyfun(int arr[],int str1[]);
int main()
{
	int y;
	int str[10];
	int x;
	cout << "Enter elements of array ";
	for (int i = 0;i < 10;i++)
	{
		
		cin >> str[i];
	
	}
	int arr2[10];
	copyfun(str, arr2);
	cout << "Copied array "<<endl;
	for (int i = 0;i < 10;i++)
	{
		 cout<< arr2[i] << endl;	
	}
}
void copyfun(int arr[],int str1[])
{
	 
	for (int i = 0;i < 10;i++)
	{
		  str1[i]=arr[i];
	}
}
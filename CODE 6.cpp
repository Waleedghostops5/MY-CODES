#include<iostream>
using  namespace std;

// A CODE BY MUHAMMAD WALEED REHAN
int main()
{
	int arr[10];
	cout << "Enter the elements of array";
	for (int i = 0; i < 10; i++)
		
	{
		cin >> arr[i];
	}

	cout << "Maximum number is ";
	int x = largest(arr,10);
	cout << "Maximum number is " << x<<endl;

}
int  largest( int arr[], int size)
{
	size = 10;
	int max = arr[0];
	for (int i = 0;i < size;i++)
	{

		if (arr[i] > max)
		{
			max = arr[i];
			

		}
	}
	return max;
}
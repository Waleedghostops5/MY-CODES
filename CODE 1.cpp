#include <iostream>
using namespace std;

// A CODE BY MUHAMMAD WALEED REHAN

void myfunction(char str[]) 
{
	cout << "RESULT: " << str << endl;
}

int main() 
{
	char input[100];

	cout << "KINDLY ENTER A WORD: ";
	cin.getline(input,100);


	myfunction(input);

	return 0;
}


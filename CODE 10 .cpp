#include<iostream>
#include<string>
using namespace std;

// A CODE BY MUHAMMAD WALEED REHAN

void ispalindrome(char str[])
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;

	}

	cout << "Lenght is " << len << endl;

	for (int i = 0;i < len / 2;i++)
	{
		if (str[i] != str[len - i - 1])
		{
			cout << "Not Palindrome " << endl;



		}
		else
		{
			cout << "Palindrome  Array";
		}

	}




}
int main()
{
	char s[100];
	cout << "Enter a word";
	cin >> s;
	ispalindrome(s);




}
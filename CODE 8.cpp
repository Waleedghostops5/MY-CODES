#include<iostream>
#include<fstream>
#include<string>

// A CODE BY MUHAMMAD WALEED REHAN
using namespace std;
int main()
{
	string file = "file.txt";
	int tword = fun(file);
	cout << "TOTAL AMOUNT OF WORDS IN PARAGRAPH " << tword;


}
int  fun(const string & x )
{
	string words;
	int wc = 0;
	
	ifstream fin(x);
	if (fin.is_open())
	{
		while(fin>>words)
		{
		
			
				wc++;
			
		}
	}
	else
	{
		cout << "Error opening file ";
	}
	fin.close();
	return wc;

}
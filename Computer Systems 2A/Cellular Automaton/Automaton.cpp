#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int binaryToInt(string input)
{
	int out = 0;

	for (unsigned int i = input.size(); i > 0; i--)
	{
		if (input[i-1] == 'o')
		{
			out += pow(2,(input.size()-i));
		}
		else if (input[i-1] != ' ')
		{
			return -1;
		}
	}

	return out;
}

int main ()
{
	ofstream myfile;
	myfile.open ("example.txt");
 	myfile << "Writing this to a file.\n";
	int rule = 0b00011110;

	cout << "Rule = " << rule << endl;

	string output = "";
	string input = "                                                     o                                                   ";

	int heightLimit = 50;
	int height = 0;

	cout << input << endl;

	while (height < heightLimit)
	{
		height += 1;

		output += " ";

		for (unsigned int i = 0; i < input.size()-1; i++)
		{
			int currentRule = rule;


			int x = binaryToInt((string(1,input[i])) + (string(1,input[i+1])) + (string(1,input[i+2])));
			
			currentRule >>= x;

			//cout << currentRule << " ";

			if (currentRule % 2 == 0)
			{
				output += " ";
			}
			else output += "o";

		}
		//cout << endl;
		cout << output << endl;

		input = output;
		output = "";
	}

	/*
	int x = binaryToInt("10000001");
	
	if (x != -1)
	{
		cout << "x = " << x << endl;
	}
	else
	{
		cout << "not a valid binary value" << endl;
	}	

	*/


	myfile.close();
	return 0;
}
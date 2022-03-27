#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

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
		else if (input[i-1] != '-')
		{
			return -1;
		}
	}

	return out;
}


void run2D(int rule, int heightLimit, string input)
{
	cout << "Rule = " << rule << endl;

	string output = "";
	//string input = "                                                     o                                                   ";

	int height = 0;

	cout << input << endl;

	while (height < heightLimit)
	{
		height += 1;

		output += "-";

		for (unsigned int i = 0; i < input.size()-1; i++)
		{
			int currentRule = rule;


			int x = binaryToInt((string(1,input[i])) + (string(1,input[i+1])) + (string(1,input[i+2])));
			
			currentRule >>= x;

			//cout << currentRule << " ";

			if (currentRule % 2 == 0)
			{
				output += "-";
			}
			else output += "o";

		}
		//cout << endl;
		cout << output << endl;

		input = output;
		output = "";
	}
}

int main ()
{

	int welcomeLoop = 0;

	while (welcomeLoop == 0)
	{
		cout << "Cellular automaton" << endl;
		cout << "Select option:" << endl;
		cout << "1. 2D cellular automaton" << endl;
		cout << "2. Game of Life" << endl;
		cout << "3. Quit" << endl;

		int welcomeOption;


		try
		{
			cin >> welcomeOption;
			cin.clear();
			std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			
		}
		catch (...)
		{
			//cout << "invalid option, try again" << endl;
			//cin.clear();
			//std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

			welcomeOption = 0;
		}

		if (welcomeOption == 1)
		{
			int automatonLoop = 0;
			
			while (automatonLoop == 0)
			{
				cout << "Select rule:" << endl;
				cout << "1. Use the default rule (write in rule here)" << endl;
				cout << "2. Use your own rule" << endl;
				cout << "3. Use a random rule" << endl;
				cout << "4. Return to main menu" << endl;

				int automatonOption;
				try
				{
					cin >> automatonOption;
					cin.clear();
					std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			
				}
				catch (...)
				{
					automatonOption = 0;
					//cout << "invalid option, try again" << endl;
					//break;
				}

				switch (automatonOption)
				{
					case 1 : 
					{
						int rule = 0b00011110;
						int heightLimit;
						string input;

						cout << "Input a starting string ('-' for a dead cell and 'o' for a live cell):" << endl; /* DO DEFAULT RULE*/
						try
						{
							cin >> input;
							cin.clear();
							std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					
						}
						catch (...)
						{
							break;
							//cout << "invalid option, try again" << endl;
							//break;
						}
						cout << "How many generations?" << endl; /* DO DEFAULT RULE*/
						try
						{
							cin >> heightLimit;
							cin.clear();
							std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					
						}
						catch (...)
						{
							break;
							//cout << "invalid option, try again" << endl;
							//break;
						}					
						run2D(rule, heightLimit, input);		
						break;
					}

					case 2 : /* ALLOW USER TO INPUT RULE*/
					{
						int rule;
						string input;
						int heightLimit;

						cout << "Input a rule as an int (up to 255):" << endl; /* DO DEFAULT RULE*/
						try
						{

							cin >> rule;
							cin.clear();
							std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					
						}
						catch (...)
						{
							break;
							//cout << "invalid option, try again" << endl;
							//break;
						}	
						cout << "Input a starting string ('-' for a dead cell and 'o' for a live cell):" << endl; /* DO DEFAULT RULE*/
						try
						{
							cin >> input;
							cin.clear();
							std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					
						}
						catch (...)
						{
							break;
							//cout << "invalid option, try again" << endl;
							//break;
						}
						cout << "How many generations?" << endl; /* DO DEFAULT RULE*/
						try
						{
							cin >> heightLimit;
							cin.clear();
							std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					
						}
						catch (...)
						{
							break;
							//cout << "invalid option, try again" << endl;
							//break;
						}					
						run2D(rule, heightLimit, input);		
						break;
					}
					case 3 : /* MAKE RANDOM RULE*/
						//int rule = randomrule;
					{
						int rule = rand() % 256;
						string input;
						int heightLimit;
						cout << "Input a starting string ('-' for a dead cell and 'o' for a live cell):" << endl; /* DO DEFAULT RULE*/
						try
						{
							
							cin >> input;
							cin.clear();
							std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					
						}
						catch (...)
						{
							break;
							//cout << "invalid option, try again" << endl;
							//break;
						}
						cout << "How many generations?" << endl; /* DO DEFAULT RULE*/
						try
						{

							cin >> heightLimit;
							cin.clear();
							std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					
						}
						catch (...)
						{
							break;
							//cout << "invalid option, try again" << endl;
							//break;
						}					
						run2D(rule, heightLimit, input);		
						break;
					}
					case 4 : /* RETURN TO PREVIOUS MENU*/
					{
						cout << "Menu Selected" << endl;
						automatonLoop = 1;
						break;
					}
					default :
					cout << "invalid option, try agian" << endl;
				} 
			}	
		}
		else if (welcomeOption == 2)
		{
			int gameLoop = 0;

			while (gameLoop == 0)
			{
				cout << "Select rule" << endl;
				cout << "1. Conways Game of Life (Default rule)" << endl;
				cout << "2. Make your oun rule" << endl;
				cout << "3. Use a random rule" << endl;
				cout << "4. Return to main menu" << endl;

				int gameOption;
				
				try
				{
					cin >> gameOption;
					cin.clear();
					std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			
				}
				catch (...)
				{
					gameOption = 0;
					//cout << "invalid option, try again" << endl;
					//break;
				}	

				switch (gameOption)
				{
					case 1 : 
						cout << "1 Selected" << endl;/* DO DEFAULT RULE*/
						break;


					case 2 : /* ALLOW USER TO INPUT RULE*/
						cout << "2 Selected" << endl;
						break;

					case 3 : /* MAKE RANDOM RULE*/
						cout << "3 Selected" << endl;
						break;

					case 4 : /* RETURN TO PREVIOUS MENU*/
						cout << "Menu Selected" << endl;
						gameLoop = 1;
						break;

					default :
					cout << "invalid option, try agian" << endl;
				} 

			}
		}
		else if (welcomeOption == 3)
		{
			welcomeLoop = 1;
		}
		else 
		{
			cout << "invalid option, try again" << endl;
		}
	}
	return 0;
}
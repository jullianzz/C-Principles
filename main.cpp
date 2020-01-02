//updated
#include <iostream>
#include <string>
#include "pa2Functions.h"
#include <fstream>
#include <string>

using namespace std;
const int ENTRIES = 5;
ofstream userfile; 
ifstream userfileRead; 

void twoParameterFunctions (double First, double Last, int (*func)(int), string &introduction);

void threeParameterFunctions (double First, double Last, double Delta, double (*func)(double), string &introduction);

void threeParameterFunctions (double First, double Last, double Delta, double (*func)(double, char), string &introduction, char commandCode);


int main()
{

	initialize();

	char commandCode; 
	char commandCodeArray[32] = {'f','F','b','B','r','R','u','U','c','C','e',
		'E','k','K','s','S','n','N','x','X','l','L','y','Y','d','D','i','I','o','O','q','Q'} ;

	//bool reading = false;


	cout << endl;
	while (commandCode != 'q' || commandCode != 'Q')
	{

		cout << "Please enter command code: " ;
		cin >> commandCode ;

		if (commandCode == 'q' || commandCode == 'Q')
		{
			userfile.close();
			return 0;
		}


		if (checkCode(commandCode) == true)
			while (checkCode(commandCode) == true)
			{
				cout << "Invalid command code" << endl;
				cout << "Please enter command code: " ;
				cin >> commandCode ;
			}
	

		cout << "Please enter the arguments for the following parameters : " ;
		cout << endl;
		int n;
		int First_OE, Last_OE; 
		double First, Last, Delta; 

		if (commandCode == 'f' || commandCode == 'F' || commandCode == 'b' || commandCode == 'B' ||
			 commandCode == 'e' || commandCode == 'E' ||
			 commandCode == 'd' || commandCode == 'D' || commandCode == 'i' || commandCode == 'I' ||
			 commandCode == 'o' || commandCode == 'O' )
		{
			switch (commandCode)
			{
				case 'f' :
				case 'F' :
				{
					cout << "Enter a number greater than 0: " ;
					cin >> n;
					cout << n << " factorial is " << factorial(n) << endl; 
				
					userfile << factorial(n) << endl; 
					break; 
				}

				case 'i' :
				case 'I' :
				{
					cout << "Enter name of file you would like to read from: " ;
					char* filename = new char; //string name; 
					cin >> filename; 
					readDataFromFile(filename); 
					if (userfileRead.is_open()) {
						while (!userfileRead.eof()) {
							//reading = true; 
				 			string line;
				 			getline(userfileRead, line);
							}
							//reading = false;
					}
					break; 
				}


				case 'b' :
				case 'B' :
				{
					cout << "Enter a number greater than 0: " ;
					cin >> n;
					cout << "Fibonacci(" << n << ") is " << fibonacci(n) << endl; 

					userfile << fibonacci(n) << endl; 
					break;
				}

				case 'd' :
				case 'D' :
				{
					cout << endl << "Enter lower bound (First argument): " ;
					cin >> First_OE;
					cout << "Enter upper bound (Last argument): " ;
					cin >> Last_OE;
					string introduction = "odd";
					twoParameterFunctions(First_OE, Last_OE, findNextOddValue, introduction);
					break;
					}

				case 'e' :
				case 'E' :
				{
					cout << endl << "Enter lower bound (First argument): " ;
					cin >> First_OE;
					cout << "Enter upper bound (Last argument): " ;
					cin >> Last_OE;
					string introduction = "even";
					twoParameterFunctions(First_OE, Last_OE, findNextEvenValue, introduction);
					break;
				}

				// case 'i' :
				// case 'I' :
				// {
				// 	cout << "Enter name of file you would like to read from: " ;
				// 	char* filename = new char; //string name; 
				// 	cin >> filename; 
				// 	readDataFromFile(filename); 
				// 	if (userfileRead.is_open()) {
				// 		while (!userfileRead.eof()) {
				// 			reading = true; 
				//  			string line;
				//  			getline(userfileRead, line);
				// 			}
				// 			//reading = false;
				// 	}
				// 	break; 
				// }

				case 'o' :
				case 'O' :
				{
					cout << "Enter name of file you would like to write to: " ;
					char* filename = new char; //string name; 
					cin >> filename; 
					writeDataToFile(filename); 
					break; 
				}

				default:
					cout << "Something went wrong! There's no function to perform!" << endl; 
			}
		}



		else
		{
			cout << endl << "Enter lower bound (First argument): " ;
			cin >> First;
			cout << "Enter upper bound (Last argument): " ;
			cin >> Last;
			cout << "Enter step size (Delta argument): " ;
			cin >> Delta;

			switch (commandCode)
			{
				case 'r' :
				case 'R' :
				{
					string introduction = "Square root of "; 
					threeParameterFunctions(First, Last, Delta, findSqrtValue, introduction);
					break; 
				}

				case 'c' :
				case 'C':
				{
					string introduction = "The area of a circle with radius "; 
					threeParameterFunctions(First, Last, Delta, areaCircle, introduction);
					break; 
				}

				case 'u' :
				case 'U':
				{
					string introduction = "The area of a square with side length "; 
					threeParameterFunctions(First, Last, Delta, areaCircle, introduction);
					break; 
				}

				case 'k' :
				case 'K':
				{
					string introduction = "A random number in the range 0 to "; 
					threeParameterFunctions(First, Last, Delta, lucky, introduction);
					break; 
				}

				case 's' :
				case 'S':
				{
					string introduction = "Sin("; 
					threeParameterFunctions(First, Last, Delta, doMath, introduction, commandCode);
					break; 
				}

				case 'n' :
				case 'N':
				{
					string introduction = "Cos("; 
					threeParameterFunctions(First, Last, Delta, doMath, introduction, commandCode);
					break; 
				}

				case 'x' :
				case 'X':
				{
					string introduction = "Exp("; 
					threeParameterFunctions(First, Last, Delta, doMath, introduction, commandCode);
					break; 
				}

				case 'l' :
				case 'L' :
				{
					string introduction = "The natural log of "; 
					threeParameterFunctions(First, Last, Delta, naturalLog, introduction);
					break; 
				}

				case 'y' :
				case 'Y' :
				{
					string introduction = "NyanCat of "; 
					threeParameterFunctions(First, Last, Delta, areaCircle, introduction);
					break; 
				}

				default:
				cout << "Something went wrong! There's no function to perform!" << endl; 
			}
		}

	}


	return 0;

}


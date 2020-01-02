//updated
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include "pa2Functions.h"

using namespace std; 
extern ofstream userfile; 
extern ifstream userfileRead; 

const double PI = 3.14159;


void initialize()
{
	cout << "EC327 : Introduction to Software Engineering" << endl;
	cout << "Fall 2019" << endl;
	cout << "Programming Assignment 2" << endl ;
	cout << "Value of Entries is : " << ENTRIES << endl;
}


bool checkCode(char commandCode)
{

	char commandCodeArray[32] = {'f','F','b','B','r','R','u','U','c','C','e',
		'E','k','K','s','S','n','N','x','X','l','L','y','Y','d','D','i','I','o','O','q','Q'} ;

	if ( !((commandCode >= 65 && commandCode <= 90) || (commandCode >= 97 && commandCode <= 122)) )
		return true; 

	else 
	{
		for (int i = 0; i < 32 ; i++)
		{
			if (commandCodeArray[i] == commandCode)
			{
				return false; 
			}
		}
	}

	return true; 
}


void writeDataToFile(const char * filename)
{
	userfile.open(filename);
	if (userfile.is_open())
		cout << "Now writing to " << filename << endl;
}


void readDataFromFile(const char * readFile)
{
	userfileRead.open(readFile);
	// if (userfileRead.is_open()) {
	// 	cout << "reading rn" << endl;
   		
 // 	}
}


int factorial(int n)
{
	if (n == 1)
		return 1;
	else 
		return n * factorial(n-1); 
}


int fibonacci(int n)
{
	if (n == 1)
		return 1; 
	else if (n == 0)
		return 0; 
	else 
	{
		return fibonacci(n-1) + fibonacci(n-2); 
	}
}


double findSqrtValue(double n)
{
	return sqrt(n);
}


double naturalLog(double n)
{
	return log(n);
}


double areaCircle(double n)
{
	return PI*pow(n,2);
}


double areaSquare(double n)
{
	return pow(n,2);
}


int findNextOddValue(int n)
{
	if (n%2 == 1)
		return n;
	else 
		return n+1 ;
}


int findNextEvenValue(int n)
{
	if (n%2 == 0)
		return n;
	else 
		return n+1 ;
}


double findNyanCatValue(double n)
{
	return pow((4*n),n) + n + 10;
}


double doMath(double n, char commandCode)
{
	if (commandCode == 's' || commandCode == 'S')
		return sin(n);
	else if (commandCode == 'n' || commandCode == 'N')
		return cos(n);
	else // (commandCode == 'x' || commandCode == 'X')
		return exp(n);

}


double lucky(double n) // generates a random number in range [0,n]
{
	srand(time(0)); 
	return rand() % (static_cast<int>(n) + 1); 
}



/*HELPER FUNCTIONS START HERE */ /*HELPER FUNCTIONS START HERE */ /*HELPER FUNCTIONS START HERE */ /*HELPER FUNCTIONS START HERE */




void twoParameterFunctions (double First, double Last, int (*func)(int), string &introduction)
{
	if (First >= Last)
		cout << "Invalid entries. No computation performed." << endl; 
	else 
	{
		int j = 1; 
		cout << "Your " << introduction << " number list from " << First << " to " << Last << " is:" << endl;
		for (double i = First; i <= Last && j <= ENTRIES; i+=2, j++)
			if ((*func)(i) <= Last)
			{
				cout << (*func)(i) << " ";
				userfile << (*func)(i) << endl; 
			}
		cout << endl; 
	}
}

void threeParameterFunctions (double First, double Last, double Delta, double (*func)(double), string &introduction)
{
	if (Delta <= 0)
		cout << "No computation needed." << endl; 
	else if (First >= Last)
		cout << "Invalid entries. No computation performed." << endl; 
	else 
	{
		int j = 1; 
		for (double i = First; i <= Last && j <= ENTRIES; i+=Delta, j++)
		{
			cout << introduction << i << " is " << (*func)(i) << endl;
			userfile << (*func)(i) << endl; 
			double temp = i + Delta; 

			if ((temp > Last) && (i != Last))
			{
				cout <<  introduction << Last << " is " << (*func)(Last) << endl;
				userfile << (*func)(Last) << endl; 
			}
		}
	}
}

void threeParameterFunctions (double First, double Last, double Delta, double (*func)(double, char), string &introduction, char commandCode)
{
	if (Delta <= 0)
		cout << "No computation needed." << endl; 
	else if (First >= Last)
		cout << "Invalid entries. No computation performed." << endl; 
	else
	{
		int j = 1; 
		for (double i = First; i <= Last && j <= ENTRIES; i+=Delta, j++)
		{
			cout << introduction << i << ") is " << (*func)(i, commandCode) << endl;
			userfile << (*func)(i, commandCode) << endl; 
			double temp = i + Delta; 

			if ((temp > Last) && (i != Last))
			{
				cout <<  introduction << Last << ") is " << (*func)(Last, commandCode) << endl;
		    
				userfile << (*func)(Last, commandCode) << endl; 
			}
		}
	}
}

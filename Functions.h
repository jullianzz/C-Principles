//updated
#include <fstream>

using namespace std;

extern const int ENTRIES;

void initialize();

bool checkCode(char commandCode); 

int factorial(int n);

int fibonacci(int n);

double findSqrtValue(double n);

double naturalLog(double n);

double areaCircle(double n);

double areaSquare(double n);

double findNyanCatValue(double n);

double doMath(double n, char commandCode);

double lucky(double n);

int findNextOddValue(int n);

int findNextEvenValue(int n);

void writeDataToFile(const char * filename);

void readDataFromFile(const char * readFile);

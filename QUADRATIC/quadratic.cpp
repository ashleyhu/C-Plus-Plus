/*
A program to compute the solutions of a quadratic equation. 
The user will be prompted for the values of the
coefficients a, b, and c. Assuming that the values a, b, and c are all real, the program will
then compute and display the roots. It will also calculate and display
the roots whether or not they are real or complex. 
*/

#include <iostream>
#include <math.h>
using namespace std; 

struct Root
{
	double real;
	double ima;
};

void getCoefficients (double &a, double &b, double &c); // asks user for the values of a, b, c
void printCoefficients (double a, double b, double c); // displays the quadratic equation formulated by user
void calculateRoots (double a, double b, double c, Root &r1, Root &r2); // calculates the values of roots
void printRoot (Root r); // outputs roots

const double EPS = 0.000001;

int main() 
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	
	getCoefficients (a, b, c);
	printCoefficients (a, b, c);

	Root r1;
	Root r2;
	calculateRoots (a, b, c, r1, r2);

	cout << endl;
	cout << "Root 1: ";
	printRoot (r1);
	cout << endl;

	cout << "Root 2: ";
	printRoot (r2);
	cout << endl;
}

void getCoefficients (double &a, double &b, double &c)
{
	do {

		cout << "Enter coefficients a, b, and c.\n" << endl;
		cin >> a >> b >> c;
		cout << endl << "You entered coefficient a as " << a << ", coefficient b as " << b << ", and coefficient c as " << c << ".\n" << endl; 

		if (cin.good() == 0) // checks for valid input
		{
			cout << "Invalid input! Only number input allowed.\n";
			cin.clear();
			cin.ignore (80,'\n');
		}
		break;

	} while (true);

}

void printCoefficients (double a, double b, double c) // displays the quadratic equation formulated by user
{
	cout << "Your equation: ";

	if (b < 0 && c < 0) {
		cout << a << "x^2 " << b << "x " << c << endl;
	} else if (b < 0) {
		cout << a << "x^2 " << b << "x + " << c << endl;
	} else if (c < 0) {
		cout << a << "x^2 + " << b << "x " << c << endl;
	} else {
		cout << a << "x^2 + " << b << "x + " << c << endl;
	}
}

void calculateRoots (double a, double b, double c, Root& r1, Root& r2) 
{
	double discriminant = pow (b , 2) - (4 * a * c);

	if (discriminant > -EPS && discriminant < EPS) // calculates one real root (use a epsilon value close to 0, due to floating point approximation)
	{
		r1.real = r2.real = (-b) / (2 * a);
		r1.ima = r2.ima = 0;
	}
	else if (discriminant < 0) // calculates two complex root
	{ 
		r1.real = r2.real = - b / (2 * a);
		r1.ima = sqrt (-discriminant) / (2 * a);
		r2.ima = -sqrt (-discriminant) / (2 * a);
	}
	else // calculates two real roots
	{
		r1.real = (-b + sqrt (discriminant)) / (2 * a);
		r2.real = (-b - sqrt (discriminant)) / (2 * a);	
		r1.ima = r2.ima = 0;
	}
}

void printRoot (Root r)
{
	cout << r.real;
	
	if (r.ima != 0) {
		if (r.ima < 0) {
			cout << r.ima << "i";
		} else {
			cout << "+" << r.ima << "i";
		}
	}
}
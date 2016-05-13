// A program to calculate Pi approximation up to a set decimal.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
	int n = 1;
	double old_approx = 0.0;
	double new_approx = 0.0;
	int stop_condition = 0;
	int count = 0;
	
	do
	{
		cout << "The pi approximation calculation stops when the nth decimal place has settled to a consistent number after three iterations. Please enter a value for n between 1 to 6 inclusive." << endl;
		cin >> stop_condition;
		cout << "The value of n you entered is " << stop_condition << endl;
	} while ( stop_condition < 1 || stop_condition > 6 );
	
	do 
	{
		old_approx = new_approx;	
		new_approx =  old_approx + ( 4 * pow ( -1 , n + 1 ) ) / ( 2 * n - 1 );
		
		cout.setf(ios::fixed);
		cout.precision(12);
		
		cout << n << "\t" << new_approx << endl; //output the term number and the approximation to pi
		
		//convert variables to integers for comparison later
		int old_approx_int = static_cast<int>( floor ( old_approx * pow ( 10 , stop_condition ) ) ); 
		int new_approx_int = static_cast<int>( floor ( new_approx * pow ( 10 , stop_condition ) ) );
		
		if ( old_approx_int == new_approx_int ) 
			count++; //if they are equal, add one to the count
		
		n++;
	} while ( count < 2 ); //when count equals 1, there are already 2 values that are have the same decimal place chosen by user, so the count only checks one more time to see if the third value is also equal
	
	return 0;
}


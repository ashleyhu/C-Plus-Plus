// This program shows a sample salary calculator for businesses.

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	//declare variables
	int paycode = 0;	
	int numManager = 0;
	int numHourly = 0;
	int numCommission = 0;
	int numPiece = 0;
	
	double t_salManager = 0;
	double t_salHourly = 0;
	double t_salCommission = 0;
	double t_salPiece = 0;
	
	double salManager = 0.0;
	double hours = 0.0;
	double salHourly = 0.0;
	double weekSales = 0.0;
	double money = 0.0;
	int itemNum = 0;
	
	//paycode legend
	cout << "Paycodes for each type of employee: " << endl
		 << "Managers : 1 " << endl
		 << "Hourly Workers : 2" << endl
		 << "Commission Workers : 3" << endl
		 << "Pieceworkers : 4" << endl;
	cout << endl;
		 
	do //repeat option to enter paycode
	{
		 	do //repeat until valid input entered
			 { 
			 	cout<< endl;
		 		cout << "Enter the appropriate paycode for the type of employee" << endl
				 	 << "or enter -1 to finish entering paycodes: " << endl;
		 		cin >> paycode;
			 }	while ( (paycode < 1 && paycode != -1) || ( paycode > 4 && paycode != -1 ) );
		 	
		 	switch ( paycode )
		 	{
		 		case 1: //calculate manager's salary
		 			cout << "Input the fixed weekly salary of the manager."	<< endl;
					cin >> salManager;
					cout << "The fixed weekly salary of the manager is: " << salManager << endl;
					t_salManager = t_salManager + salManager;
					numManager ++;
					break;
					
				case 2: //calculate hourly worker's salary
					cout << "Input the number of hours worked a week by the hourly worker."	<< endl;
					cin >> hours;
					cout << "The number of hours worked a week by the hourly worker is: " << hours << endl;
					cout << "Input the fixed hourly wage of the hourly worker."	<< endl;
					cin >> salHourly;
					cout << "The fixed hourly wage of the hourly worker is: " << salHourly << endl;
					if ( hours >= 0 && hours <= 40 )
						t_salHourly = t_salHourly + ( salHourly * hours );
					else
						t_salHourly = t_salHourly + ( salHourly * ( 40 + ( 1.5 * ( hours - 40 ))));
					numHourly ++;
					break;
				
				case 3: //calculate commission worker's salary
					cout << "Input the gross weekly sales of the commission worker. " << endl;
					cin >> weekSales;
					cout << "The gross weekly sales of the commission worker is:  " << weekSales << endl;
					t_salCommission = t_salCommission + ( 200 + ( 0.066 * weekSales ));
					numCommission++;
					break;
					
				case 4: //calculate pieceworker's salary
					cout << "Input the fixed amount of money for the pieceworker's item." << endl;
					cin >> money;
					cout << "The fixed amount of money for the pieceworker's item is: " << money << endl;
					cout << "Input the number of items the pieceworker produced in a week."	<< endl;
					cin >> itemNum;
					cout << "The number of items the pieceworker produced in a week is: " << itemNum << endl;
					t_salPiece = t_salPiece + ( money * itemNum );
					numPiece++;
					break;
		 	}
		 	
  	} while ( paycode !=-1 );
  	
  	//output table
  	cout.setf(ios::fixed);
	cout.precision(2);	
  	cout << " Table 1 : Total number of employees and salary per type of employee;" << endl;
  	cout << "|\tType of Employees\t|\tNumber of Employees\t|\t Salary ($)\t|" << endl;	
	cout << "|\tManagers\t\t|\t\t\t" << setw(6) << numManager << "\t|\t\t" << setw(6) << t_salManager << "\t|" << endl;
	cout << "|\tHourly Workers\t\t|\t\t\t" << setw(6) << numHourly << "\t|\t\t" << setw(6) << t_salHourly << "\t|" << endl;
	cout << "|\tCommission Workers\t|\t\t\t" << setw(6) << numCommission << "\t|\t\t" << setw(6) << t_salCommission << "\t|" << endl;
	cout << "|\tPieceworkers\t\t|\t\t\t" << setw(6) << numPiece << "\t|\t\t" << setw(6) << t_salPiece << "\t|" << endl;
	cout << "|\tTotal\t\t\t|\t\t\t" << setw(6) << numManager + numHourly + numCommission + numPiece << "\t|\t\t" << setw(6) << t_salManager + t_salHourly + t_salCommission + t_salPiece << "\t|" << endl;
	
	return 0;
}

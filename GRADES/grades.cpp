/*
A program which reads a list of final student grades input by the
user and outputs the class average and a histogram showing the grade distribution for
the class, using the bins mentioned above. The program will include two
functions, one to populate the histogram bins, and one to output the histogram.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double gradeInput(int* bin); // takes the array as the input for the bins
void printHistogram(int* bin); // displays the histogram from input grades

int main()
{
    int bin[6] = {0, 0, 0, 0, 0, 0}; // have a bin for each of the 6 categories of grades
    double average = gradeInput(bin);

    cout << "Average: " << average << endl << endl; // outputs the class average

    printHistogram(bin);
}

double gradeInput(int* bin) 

{
    double sum = 0; // records the total of all grades entered
    int totalnum = 0; // records the number of grades entered

    cout << "Enter students' grades. Input -1 when you are done entering.\n" << endl;
    
    while (true) 
    {
        
        int grade = 0; // asks user to input list of grades
        
        do 
        {
            cin >> grade;
            cout << "You entered: " << grade << endl << endl;

            if (cin.good() == 0) 
            {
                cout << "Invalid input! Only number input allowed.\n" << endl; // if a non-number input is entered, program asks user to re-enter
                cin.clear();
                cin.ignore(80,'\n');
                continue;
            } else if (grade < -1 || grade > 100) {
                cout << "Please enter a grade between 0 - 100 inclusive.\n" << endl; // if an invalid number is entered, program asks user to re-enter
                continue;
            }
            break;

        } while (true);
        
        if (grade == -1) 
        {
            break;
        }

        sum += grade;
        totalnum++;

        if ((grade < 50) && (grade >= 0))
            bin[0]++;
        else if (grade < 60)
            bin[1]++;
        else if (grade < 70)
            bin[2]++;
        else if (grade < 80)
            bin[3]++;
        else if (grade < 90)
            bin[4]++;
        else if (grade <= 100)
            bin[5]++;
    }
    return (sum / totalnum);
}

void printHistogram(int* bin) 
{
    string binName[] = {"0-49","50-59","60-69","70-79","80-89","90-100"};
    
    for (int i = 0; i < 6; i++) // iterates the same process for each of the 6 bins
    {
        cout << setw(9) << binName[i] << ": ";
        for (int j = 0; j < bin[i]; j++) // counter for the number of grades entered per bin
        {
            cout << "*"; // uses asterisks to represent the grades that fall into each bin
        }
        cout << endl;
    }
}
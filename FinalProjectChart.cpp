//Calculate monthly payments into investment vehicle
//Creared by <Dan Carlson> on <21 September 2016>

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{

//Declare variables
double rate = 0.0;
double amt = 0.0;
int x = 0;
double prin = 0.0;
double j = 2;
//int months = 0;
//Create file object and open the file
ofstream outFile;  //outInterest ??
outFile.open("FinalProjectChart.txt", ios::app);


cout << fixed << setprecision(2);
cout << "Enter a yearly amount: $";
cin >> amt;

//Determine if the file was opened
if (outFile.is_open())
{//Declare and initialize array
	double payOut[39][9] = {0};
	
	outFile << "Enter a yearly amount: $" << amt << "\n";
	
		for (int i = 2; i <= 12; i += 1) //interest rose
			{

				rate = j / 100;
				cout << i << "\% Interest: " ;
				outFile << i << "\% Interest: " ;
				//cout << "rate" << rate;
					for (int a = 1; a <= 40; a += 1)   //years
						{
						prin += amt;
						//cout << "prin" << prin <<endl;
						payOut[i][a] = prin;
						prin = prin * (1 + (rate/1));
							if (a %5 == 0)
								{
								cout << " " << payOut[i][a];
								outFile << " " << payOut[i][a];							}
						}
					prin = 0;
					j++;
					cout << endl;
					outFile << "\n";			
			}
cout << endl << "Interest displayed at 5 year increments. Year 5 through 40.";
outFile << "\n Interest displayed at 5 year increments. Year 5 through 40. \n \n \n";
outFile.close();
}
else   {
	cout <<"The file could not be opened." << endl;
	}
}

// INSERT YOUR PROGRAM COMMENTS HERE
//
// Name: Akaash Kapoor
// Student Number: 101112895

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { 
	return value * value; 
}

double computeSolidity(double B1, double B2){
	
	double LHS, lowLHS;
	double x, chosenX, z;
	
	for (z = 6 ; z <= 21 ; z++){
				x = z * 0.1;
				
			LHS = 33.5291 + B2 * (0.469188 + (0.0020961 * B2)) - B1 + log(1/x) * ((0.187148 * B2) - 15.2599) - (sqr((log(1/x)))* 0.677212);
				
				//Checking for the chosen value of the solidity
				if (z == 6 || fabs(LHS) < fabs(lowLHS)){
					
					lowLHS = LHS;
					chosenX = x;
					
				}//endif
				
					// Outputs values
				cout << fixed << showpoint << setprecision(1) << setw(10) << x 
				<< fixed << showpoint << setprecision(4) << setw(15) << LHS << endl;
				
    }// end for loop
    
    return chosenX;
}

double computeBladeExitAngle (double A1, double B2, double S){
	
	return (B2 - A1 * (0.23 + (B2/500)) * pow((1/S),0.5)) / (1 - (0.23 + (B2/500))* pow (1/S , 0.5));
	//returns the blade exit angle
	
}


int main (void) {

	double Beta1, Beta2, i;
	double Alpha1, Alpha2 , a;
	double Solidity;
	
	for (;;){
		
	//Getting user input
	cout << "Enter flow entry and exit angle, and incidence: " << endl;
	cin >> Beta1 >> Beta2 >> i;
	
		while (cin.fail()){
			
			cout << "Garbage data was entered - please try again" ;
			cin.clear();
			cin >> Beta1 >> Beta2 >> i;
			
		}
	
		//Checking sentinel value
		if ( Beta1 == -1 && Beta2 == -1 && i == -1 ){
			break;
		}
		
		//Factor calculated to evaluate condition
		a = (36 - (Beta2 * 0.45))/(Beta1 - Beta2);
		
		//Checking invaid inputs
		if (!(Beta2 >= -10 && Beta2 <= 50 && i >= -3 && i <= 3 && a >= 0.75 && a <= 1.25 && Beta1 != Beta2)) {
			
			cout << "Invalid values are ignored." << endl;
		
		} else {
			//Creating the tables
				cout << "     Solidity        LHS" << endl;
				cout << "--------------------------------" << endl;
				
			//Calls the solidity function and prints the values.
			Solidity = computeSolidity(Beta1, Beta2);
			
			//Evaluates the chosen solidity
			cout << "The chosen solidity is: "  << fixed << showpoint << setprecision(1) << Solidity << endl;
			cout << endl;
			
			//Calculating the blade entry and exit angles
			Alpha1 = Beta1 - i;
			Alpha2 = computeBladeExitAngle(Alpha1, Beta2, Solidity);
			
			//Output messages
			cout << "Blade entry angle: " << Alpha1 << endl;
			cout << "Solidity: " << Solidity << endl;
			cout << "Blade exit angle: " << Alpha2 << endl;
			cout << endl;
			
		}
	}//endforever

    system("PAUSE"); return 0;

}//End program


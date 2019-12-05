// Creating a simping Reading File using the "Fin" Object. 
//
// Name: Akaash Kapoor
// Student Number: 101112895

#include <iostream>
#include <cmath>
#include <fstream>//Must be included to import text files. 
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



int main (void) {
	
	double value;
	int count = 0;
	int total = 0;
	double largestSoFar;
	fstream fin; //The object used to read .txt files. 
	char filename [60]; //Array of characters to store the file name given by user input. 
	
	
		cout << "Enter name of file: ";
		cin >> filename;
		
		fin.open(filename);
		if (fin.fail()){
			
			cout << "Unable to open file" << endl;
			 system("PAUSE"); return 0;
			
		} 
		
			for (;;){
			
				fin >> value; //The variable "value" is the number inside the text file, and changes for every line has a new number. 
		
				if (fin.fail()){
			
				//This is used as opposed to a sentinel value (-999).
				if (fin.eof()){
				break;
				}
			
				cout << "Unable to read the input file" << endl;
				system("PAUSE"); return 0;
		
				}	
		
	
				count++;
				total += value; //Keeps track of total sum of the numbers
		
				if (count ==1 || value > largestSoFar){ //Keeps track of the largest number within the file. 
				largestSoFar = value;
				}
		
			}
	
			if (count == 0){
			cout << "The file does not contain any values" << endl;
			} else {
			cout << count << " values were read" << endl
			<< "The largest value is " << largestSoFar << endl
			<< "The average of the values is " << total / count << endl;
		
			}
		
    system("PAUSE"); return 0;

}




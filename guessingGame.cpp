/* Anthony Lahoud
Computer science
NDU_CSC212_SectionA
*/
#include<iostream>   
#include <iomanip>
#include <cstdlib> 
#include <ctime>
using namespace std;

void uniqueNumbers(int&, int&, int&);
int numberguessed(int, int, int, int, int, int);
int numberinorder(int, int, int, int, int, int);
// declaring 3 functions: uniqueNumbers,numberguessed and numberinorder.

int main() {
	srand ( time (0) );
	
	int num1, num2, num3, numinorder{ 0 }, numguessed{ 0 }; //declaring variables
	num1 = rand() % 7 + 3;
	num2 = rand() % 7 + 3;
	num3 = rand() % 7 + 3;
	// generate 3 random numbers
	uniqueNumbers(num1, num2, num3); // the three random variables are unique

	cout << num1 << setw(4) << num2 << setw (4) << num3 << endl; // output result
	cout << "Enter three numbers between 3 and 9." << endl;

	for (int i = 1; i <= 10; i++) { //loop 10 times
		int first_number, second_number, third_number; // declare variables

		cout << "Try " << i << ": "; // output number of current try
		cin >> first_number >> second_number >> third_number; //prompt user to guess the 3 random numbers

		numguessed = numberguessed(num1, num2, num3, first_number, second_number, third_number);
		numinorder = numberinorder(num1, num2, num3, first_number, second_number, third_number);

		cout << "---->   " << numguessed << " number(s) guessed.";
		cout << setw(4)<< numinorder << " number(s) in order." << endl;
		// output how many numbers were guessed and how many guessed were in order 
		if (numguessed == 3 && numinorder == 3)   //if all numbers were guessed and in all order
		{
			cout << endl;
			cout << setw(35) << "***YOU WIN***" << endl; //output result
			break; //break from the for loop
		}  
	}
	if (numguessed != 3 || numinorder != 3) // if numbers weren't guessed or weren't in order
	{
		cout << endl;
		cout << setw(35) << "***YOU LOSE***" << endl; //output result
	}
}

void uniqueNumbers(int &a, int &b, int &c) // function unique numbers
{
	
	while (a == b || a == c ) // while a is equal to either b or c
		{
		a =  rand() % 7 + 3;  // regenerate a
		}
	while (b == c || b == a) {  // while b is equal to either c or a
		b = rand() % 7 + 3; // regenerate b
	}
}


int numberinorder(int d, int e, int f, int g, int h, int j) {  //function numberinorder
	int k{ 0 };  // declare variable
	if (d == g)  //if d is equal to g
		k++;	 // incriment k
	if (e == h)  //if e is equal to h
		k++;	 // incriment k
	if (f == j)  //if f is equal to j
		k++;	 // incriment k
	return k;    //return variable
}

int numberguessed(int d, int e, int f, int g, int h, int j) { //function numberguessed
	int k{ 0 }; //declare variable
	if (d == g || d == h || d == j ) //if d is equal to either g, h or j
		k++;						// incriment k
	if (e == g || e == h || e == j ) //if e is equal to either g, h or j
		k++;						// incriment k
	if (f == g|| f == h || f == j) //if f is equal to either g, h or j
		k++;						// incriment k
	return k;  //return variable
}

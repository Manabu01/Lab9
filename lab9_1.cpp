#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

double Interest(double loan, double rate){
	return loan * rate / 100.0;
}
double NewBalance(double loan, double rate, double payment){
	return loan + Interest(loan, rate) - payment;
}

int main(){	
	double loan, rate, payment;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rate;
	cout << "Enter amount you can pay per year: ";
	cin >> payment;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#";
	cout << setw(13) << left << "PrevBalance";
	cout << setw(13) << left << "Interest";
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2);
	for(int year = 1; loan > 0; year++){
		cout << setw(13) << left << year; //Year
		if(loan < 0)
			loan = 0;
		cout << setw(13) << left << loan; //Remain
		cout << setw(13) << left << Interest(loan, rate); //Interest
		cout << setw(13) << left << loan + Interest(loan, rate); //Total
		if(payment > loan + Interest(loan, rate))
			payment = loan + Interest(loan, rate);
		cout << setw(13) << left << payment; //Payment
		loan = NewBalance(loan, rate, payment);
		cout << setw(13) << left << loan; //remain2
		cout << "\n";
		
	}
	
	
	return 0;
}

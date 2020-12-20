#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	// Declare variables to store input
	float initInv, monDep, anuInt, months, years;
	// Declare variables to store year end total amount, interest, and year end interest
	float totalAm, intAmt, yearTotInt;

	// Display menu to user
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;

	// Wait for input from user
	system("PAUSE");

	// Collect data from user
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initInv;
	cout << "Monthly Deposit: $";
	cin >> monDep;
	cout << "Annual Interest: %";
	cin >> anuInt;
	cout << "Number of years: ";
	cin >> years;
	months = years * 12;

	// Wait for input from user
	system("PAUSE");

	// Set total amount to initial investment to be updated
	totalAm = initInv;

	cout << endl;

	// Display year data without monthly deposits
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// For loop for each year
	for (int i = 0; i < years; i++) {

		// Calculate yearly interest
		intAmt = (totalAm) * ((anuInt / 100));

		// Calculate year end total
		totalAm = totalAm + intAmt;

		// Print results to table with only two decimal placess
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << endl;
	}

	// Set total amount to initial investment to be updated
	totalAm = initInv;

	cout << endl;

	// Display year data with monthly deposits
	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// For loop for each year
	for (int i = 0; i < years; i++) {

		// Set yearly interest to zero at the start of the year
		yearTotInt = 0;

		// For loop for each month
		for (int j = 0; j < 12; j++) {

			// Calculate monthly interest
			intAmt = (totalAm + monDep) * ((anuInt / 100) / 12);

			// Calculate month end interest
			yearTotInt = yearTotInt + intAmt;

			// Calculate month end total
			totalAm = totalAm + monDep + intAmt;
		}

		// Print results to table with only two decimal places
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << yearTotInt << endl;
	}
	return 0;
}
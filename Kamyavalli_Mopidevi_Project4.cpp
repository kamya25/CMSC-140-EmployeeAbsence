/*
 * Class: CMSC140 CRN
 * Instructor:Dr.Chwen-Huey Wu
 * Project4
 * Description:  Write a program that calculates the average number of days a company's employees are absent 
 during the year and outputs a report on a file named "employeeAbsences.txt".  
 * Due Date:11/16/2021
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Kamyavalli Mopidevi

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flowchart submitted in documentation)
  1.start 
  2. declare prototypes
  3. declare ofstream outputFile
  4.declare programmerName, number, employeeID, missedDays, employees
  5.openfile.txt
  6.display calculate the average number of days a company's employees are absent
  7.call the functions NumOfEmployees, TotDaysAbsent(employees);, AverageAbsent(employeees, missedDays);
  8.open int NumOfEmployees()
  9.Ask the user to enter the number of employees in the company
  10.save employees
  11.return employees
  12.open int TotDaysAbsent(int employees)
  13.Ask the user to enter the employeeID. save employeeID
  14. Ask the user to enter the number of days the employee was absent. save missedDays
  15. Assign total=total+missedDays
  16. Return total
  17. open double AverageAbsent(int employees, int missedDays)
  18. assign AverageAbsent=missedDays/employees
  19. return average absent. 
  20. in int main()
  21. Display the programmer name
  22. End the programm. 
  */
#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


//prototypes
int NumOfEmployees();
int TotDaysAbsent(int);
double AverageAbsent(int,int);


ofstream outputFile;
int main()
{
	
	string programmerName = "Kamyavalli Mopidevi.";
	
	int number = 4;
	int employeeID;
	int missedDays;
	int employees = 0;
	outputFile.open("employeeAbsences.txt");
	outputFile << "EMPLOYEE ABSENCE REPORT" << endl;
	outputFile << "employee ID\t" <<"days Absent" << endl;

	cout << " Calculate the average number of days a company's employees are absent." << endl;
	cout << endl;
	employees= NumOfEmployees();
	missedDays=TotDaysAbsent(employees);
	
	double average=AverageAbsent(employees, missedDays);
	outputFile << "The " << employees << " employees were absent a total of " << missedDays << " days." << endl;
	outputFile << setprecision(1) << fixed;
	outputFile<< "The average number of absent is " << average << " days" << endl;
	outputFile << "Thank you for testing my program!!" << endl;
	outputFile << "Programmer: " << programmerName << endl;
	
	outputFile.close();
	cout << " Programmer: " << programmerName << endl;
	return 0;
	
}

int NumOfEmployees()
{
	int employees;
	int employeeID;
	int missedDays;
	cout << " Please enter the number of employees in the company: ";
	cin >> employees;
	while (employees < 1)
	{
		cout << " The number of employees should not be less than 1!! ";
		cout << " Enter the number of employees: ";
		cin >> employees;
		
	}
	return employees;
}


int TotDaysAbsent(int employees)
{
	int total = 0;
	for (int count = 1; count <= employees; count++) {

		int employeeID;
		int missedDays;
		cout << " Please enter an employee ID: ";
		cin >> employeeID;
		
		outputFile << setw(8) << fixed << employeeID;
		cout << " Please enter the number of days this employee was absent: ";
		cin >> missedDays;
		if (missedDays < 0)
		{
			cout << " The number of days must not be negative. " << endl;
			cout << " Please re-enter the number of days absent: ";
			cin >> missedDays;
		}
		outputFile << setw(12) << fixed << missedDays<<"\n";
		
		total = total + missedDays;
		
	}
	
	return total;
}

double AverageAbsent(int employees, int missedDays)
{
	double averageAbsent = missedDays / employees;
	
	return averageAbsent;
}


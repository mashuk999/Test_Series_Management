// Test_Series_Management.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int rpin = 1234;

class TestSeries {
public:

	string question;
	string mcq1, mcq2, mcq3, mcq4;
	int answer;
};

int main()
{
	

    return 0;
}

int Welcome()
{
	int choice;
	int check=1;

	cout << "Welcome to Test Series management"<<endl;
	cout << "Enter (1) to take test"<<endl<<"Enter (2) for teachers login \n";
	cin >> choice;
	
	while (check)
	{
		if (choice == 1)
		{
			//Take the test

			check = 0;
		}
		else if (choice == 2)
		{
			//Teachers login

			Teacherslogin();

			check = 0;
		}
		else {
			cout << "Invalid Entry\n";
		}
	}
	

	return 0;
}

int Teacherslogin()
{
	int pin,check=1;
	
	while (check)
	{
		cout << endl << "Enter PIN" << endl;

		cin >> pin;

		if (pin == rpin)
		{
			//Get access to Teachers DashBoard
			TeachersDashBoard();

			check = 0;
		}

		else
		{
			cout << "Invalid Entry " << endl;
		}
	}
	return 0;
}

int TeachersDashBoard()
{
	
	cout << "Welcome";


	return 0;
}

int QuestionInsert()
{
	ofstream fout;

	fout.open("database.txt", ios::binary || ios::app);

	system("CLS"); //Clear the screen

	TestSeries obj;

	cout << endl << "Enter Question : " << endl;

	cin.ignore();

	getline(cin, obj.question);

	cout << endl << "Enter Multiple Choice 1 : " << endl;

	cin.ignore();
	getline(cin, obj.mcq1);

	cout << endl << "Enter Multiple Choice 2 :" << endl;

	cin.ignore();
	getline(cin, obj.mcq2);

	cout << endl << "Enter Multiple Choice 3 : " << endl;

	cin.ignore();
	getline(cin, obj.mcq3);

	cout << endl << "Enter Multiple Choice 4 :" << endl;

	cin.ignore();
	getline(cin, obj.mcq4);

	cout << endl << "Enter which MCQ Number is Correct (Integer)" << endl;

	cin.ignore();

	cin >> obj.answer;


	//Inserting in the File

	fout.write((char *)&obj, sizeof(obj));

	return 0;
}
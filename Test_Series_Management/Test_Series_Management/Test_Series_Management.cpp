// Test_Series_Management.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int rpin = 1234;

string::iterator it;

class TestSeries {
public:

	string question;
	string mcq1, mcq2, mcq3, mcq4;
	int answer;
	int level;
};

class Student {

public:
	int level = 0;
	string username;
	string password;

};

#pragma region Function_Declaration

int Welcome();
int Teacherslogin();
int TeachersDashBoard();
int QuestionInsert();
Student StudentLogin();
int StudentRegister();
int StudentDashboard();
int Taketest(Student );

#pragma endregion

int main()
{
	Welcome();

    return 0;
}

int Welcome()
{
	int choice;
	int check=1;

	cout << "Welcome to Test Series management"<<endl;
	cout << "Enter (1) for the Student login/Registration"<<endl<<"Enter (2) for teachers login \n";
	cin >> choice;
	
	while (check)
	{
		if (choice == 1)
		{
			int choice2;
			//Take the test
			cout << endl << "Enter (1) for Login and (2) for Registration" << endl;
			cin.ignore();

			cin >> choice2;

			if (choice2 == 1)
			{
				StudentLogin();
			}
			else if (choice2 == 2)
			{
				StudentRegister();
			}
			else {
				cout << endl << "Invalid Entry"<<endl;
			}
			

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
	
	cout << "Welcome"<<endl;
	QuestionInsert();


	return 0;
}

int QuestionInsert()
{
	ofstream fout;

	fout.open("Questions.txt", ios::binary || ios::app);

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

	cout << endl << "Enter Level of Question (0 for Beginner and ++ to infnite) :" << endl;

	cin.ignore();

	cin >> obj.level;


	//Inserting in the File

	fout.write((char *)&obj, sizeof(obj));

	return 0;
}

Student StudentLogin()
{
	ifstream fin;

	Student student;

	string username, password;

	int choice = 1;
	
	fin.open("database.txt", ios::binary || ios::in);

	while (choice)
	{
		cout << endl << "Enter Username :" << endl;

		cin.ignore();

		getline(cin, username);

		cout << endl << "Enter Password :" << endl;

		cin.ignore();

		getline(cin, password);

		for (int i = 0;fin.read((char *)&student, sizeof(student));i++) //Check
		{
			if (student.username == username)
			{
				if (student.password == password)
				{
					choice = 0;
					return student;
				}
			}
		}
		cout << endl << "Invalid Creditionals"<<endl;
	}
}

int StudentRegister()
{
	ofstream fout;
	Student student;

	fout.open("database.txt", ios::binary || ios::app);

	cout << endl << "Welcome to the Registration " << endl;
	
	cout << endl << "Enter the Username :" << endl;

	cin.ignore();

	getline(cin, student.username);

	cout << endl << "Enter the Password :" << endl;

	cin.ignore();

	getline(cin, student.password);

	fout.write((char *)&student, sizeof(student));

	cout << endl << "Successfully Registered " << endl;

	Welcome();

	return 0;
}

int StudentDashboard()
{
	Student student;
	ofstream fout;

	fout.open("database.txt", ios::app || ios::binary);

	student = StudentLogin();

	Taketest(student);

	return 0;
}

int Taketest(Student student)
{
	ifstream fin;
	TestSeries question;
	int levelinc = 0;
	int ans = 5;


	fin.open("Questions.txt", ios::app || ios::binary);

	for (int i = 0;fin.read((char *)&question, sizeof(question));i++) //check
	{
		if (question.level == student.level)
		{
			cout << endl << "Question :" << endl;
			for (it = question.question.begin();it != question.question.end();it++)
			{
				cout << *it;
			}

			cout << endl << "Options :" << endl;

			cout << "(1)" << endl;
			for (it = question.mcq1.begin();it != question.mcq1.end();it++)
			{
				cout << *it;
			}

			cout << "(2)" << endl;
			for (it = question.mcq2.begin();it != question.mcq2.end();it++)
			{
				cout << *it;
			}

			cout << "(3)" << endl;
			for (it = question.mcq3.begin();it != question.mcq3.end();it++)
			{
				cout << *it;
			}

			cout << "(4)" << endl;
			for (it = question.mcq4.begin();it != question.mcq4.end();it++)
			{
				cout << *it;
			}


			cout << endl << endl << "Enter Your Answer : " << endl;
			cin.ignore();
			cin >> ans;
			if (ans == question.answer)
			{
				levelinc++;
			}
			else
			{
				cout << endl << "Incorrect Answer" << endl;
			}
		}

		if (levelinc >= 10)
		{
			student.level++; //remember to update this in database file
		}
	}

	return 0;
}
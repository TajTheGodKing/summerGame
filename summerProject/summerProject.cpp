// summerProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*********************************************************************************
Justin T  Cooke, 6/9/2017 ,started at 7:05
Edited 6/12/2017
*********************************************************************************/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std;

class User {
protected:
	string Tag, name, location,password; // Basic user account maybe opt out of real name? 
	int age;

public:
	User();
	User(string, string, string,string, int);
	~User();
	/*Mutators to access private members in User class*/
	void set_Tag(string T) {
		Tag = T;
	}
	void set_Name(string N) {
		name = N;
	}
	void  set_Location(string L) {
		location = L;
	}
	void set_pass(string P) {
		password = P;
	}
	int set_Age(int A) {
		age= A;
	}
	string get_Tag() {
	
		return Tag;
	}
	string get_Name() {
		return name;
	}
	string get_location() {
		return location;
	}
	int get_Age() {
		return age;
	}
	string get_pass() {
		return password;
	}

};
User::User() {};
User::~User() {};
User::User(string T,string P, string N, string L, int A) {
	Tag = T;
	name = N;
	location = L;
	age = A;
	password = P;
//protypes for functions
void fillVec(vector<User> &userVec);
void print(vector<User> &userVec);
void die();
int main() {
	User obj;
	string tag, password;
	vector<User>userVec;//vector to hold users information
	char answer;
	cout << "************************************************* \n" << flush;
	cout << "Welcome to the Contra clone,Do you already have an account(Y/N): \n" << flush;
	cout << "************************************************* \n" << flush;
	cout << ": ";
	cin >> answer;
	if (answer == 'N' || answer == 'n') {
		fillVec(userVec);//place vector name because it is calling the vector by reference 
		print(userVec);
	}
	else if(answer=='Y'|| answer=='y'){
		cout << "-Login-" << endl;
		cout << "GamerTag: ";
		getline(cin, tag);
		cin.ignore();
		cout << "Password: ";
		getline(cin, password);
		cin.ignore();
	}
	else {
		cout << "************INVALID INPUT*************";
		system("pause");	
	die();
	}
	
	
}
//******HERE WE ARE SETTING UP VECTOR SO IT CAN BE FILLED*****
void fillVec(vector<User> &userVec) {
	string Tag, name, location,password,password2;
	int age;
	cout << "Enter in your information as follows \n";
	cout << "Gamer Tag: ";
	getline(cin, Tag);
	cin.ignore();
	cout << "Password: ";
	getline(cin, password);
	cin.ignore();
	if (password.size() < 5) {//quick fix, 6/13
		cout << "*****Password to small.....********" << endl;
		cout << "Please enter Valid Password,Must be at least 5 characters long" << endl;
		getline(cin, password);
		cin.ignore();
	}
	cout << "Please re-enter password:";
		getline(cin, password2);
		cin.ignore();
	 if (password.compare(password2)) {//For some reason i am having an issue with line(Tried != and still puts out wrong value(FIXED!) 
		 cout << "Match!";
	}
	 else {
		 cout << "Password does not match,please try again: " << endl;
		 getline(cin, password2);
		 cin.ignore();
	 }

	cout << "First and last name: \n";
	getline(cin, name);
	cin.ignore();
	cout << endl;
	cout << "City and State(Example: Ontario,CA): " << endl;
	getline(cin, location);
	cin.ignore();
	cout << endl;
	cout << "Age: " << endl;
	cin >> age;
	if (age < 18) {
		die();
	}
	cout << endl;
	//CREATING A NEW INSTANCE 
	User getData(Tag,password, name, location, age);
		//Pushing Instance back into the vector 
		userVec.push_back(getData);
		
}
//Prints The Users information to screen 
void print(vector<User>&userVec) {
	unsigned int SIZE = userVec.size();
	for (unsigned int i = 0; i < SIZE; i++) {
		cout << "Gamer Tag: " << userVec[i].get_Tag();
		cout << endl;
		cout << "UserName: " << userVec[i].get_Name();
		cout << endl;
		cout << "Home Town: " << userVec[i].get_location();
		cout << endl;
		cout << "Age: " << userVec[i].get_Age();
		cout << endl;
		/*
		for(vector<User>::iterator it= userVec.begin();it !=userVec.end();it++){
		cout<<*it;
		}
		*/
	}

}
void die() {//simple die function , to automatically kill program
	cout << "**********ERROR********* Sorry you are not old enough" << endl;
	exit(EXIT_FAILURE);
}

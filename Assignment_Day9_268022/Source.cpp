#include"Day9ProjectPractice.h"
#include <fstream>
#include<iostream>
using namespace std;

void addRecord() {
	StudentRecord s;
	s.accept();

	ofstream outFile("student.dat", ios::out | ios::binary | ios::app);
	if (!outFile) {
		cout << "Faid to open/ create the file !" << endl;
		return;

	}
	outFile.write(reinterpret_cast<char*>(&s), sizeof(StudentRecord));
	outFile.close();
	cout << "Record saved successfully !" << endl;
}

void addCustomRecord(StudentRecord& obj) {
	

	ofstream outFile("student.dat", ios::out | ios::binary | ios::app);
	if (!outFile) {
		cout << "Faid to open/ create the file !" << endl;
		return;

	}
	outFile.write(reinterpret_cast<char*>(&obj), sizeof(StudentRecord));
	outFile.close();
	cout << "Record saved successfully !" << endl;
}


void displayAllActive() {
	ifstream inFile("student.dat", ios::in | ios::binary);
	if (!inFile) {
		cout << "File could not be opened !" << endl;
		return;
	}

	StudentRecord s;
	while (inFile.read(reinterpret_cast<char*>(&s), sizeof(StudentRecord))) {
		//cout << "Roll No: " << s.getRollNo()
		//	<< " | Name: " << s.getFName()
		//	<< " | Dept: " << s.getDept()
		//	<< " | CGPA: " << s.getCgpa()
		//	<< " | Active: " << (s.getActiveStatus() ? "Yes" : "No") << endl;
		if (s.getActiveStatus() == 1) {
			cout << "Roll No: " << s.getRollNo()
				<< " | Name: " << s.getFName()
				<< " | Dept: " << s.getDept()
				<< " | CGPA: " << s.getCgpa()
				<< " | Active: " << s.getActiveStatus() << endl;
		}

	}
	inFile.close();
}

void displayAll() {

	ifstream inFile("student.dat", ios::in | ios::binary);
	if (!inFile) {
		cout << "File could not be opened !" << endl;
		return;
	}

	StudentRecord s;
	while (inFile.read(reinterpret_cast<char*>(&s), sizeof(StudentRecord))) {
		cout << "Roll No: " << s.getRollNo()
			<< " | Name: " << s.getFName()
			<< " | Dept: " << s.getDept()
			<< " | CGPA: " << s.getCgpa()
			<< " | Active: " << (s.getActiveStatus() ? "Yes" : "No") << endl;
		

	}
	inFile.close();

}

void displayByRollNo() {
	int rollNo;
	cout << "Enter the roll no to search: " << endl;
	cin >> rollNo;
	ifstream inFile("student.dat", ios::in | ios::binary);
	if (!inFile) {
		cout << "File could not be opened !" << endl;
		return;
	}

	StudentRecord s;
	bool isFound = false;
	while (inFile.read(reinterpret_cast<char*>(&s), sizeof(StudentRecord))) {
		if (s.getRollNo() == rollNo) {
			cout << "Roll No: " << s.getRollNo()
				<< " | Name: " << s.getFName()
				<< " | Dept: " << s.getDept()
				<< " | CGPA: " << s.getCgpa()
				<< " | Active: " << s.getActiveStatus() << endl;
			cout << " " << endl;
			isFound = true;
			break;
		}
		

	}
	if (!isFound) {
		cout << "Record Doesnt Exist !" << endl;
	}
	inFile.close();
}




int main() {
	int choice;
	
	
	do {

		
		cout << "1. Add New Student || 2. Display All Active Records || 3. Search Student By RollNo || 4. Exit" << endl;
		cout << "Enter your Choice: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			addRecord();
			break;
		case 2:
			displayAllActive();
			break;
		case 3:
			displayByRollNo();
			break;
		case 4:
			break;
		default:
			cout << "Invalid choice! Please select 1-4." << endl;
			break;


		}

	} while (
		choice != 4
		);

	return 0;

}
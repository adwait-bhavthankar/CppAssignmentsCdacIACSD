#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class StudentRecord {
private:
	int rollNo;
	char f_name[50];
	char dept[20];
	float cgpa;
	bool active_status;
public:
	StudentRecord() {
		rollNo = 0;
		f_name[0] = '\0';
		dept[0] = '\0';
		cgpa = 0.0f;
		active_status = false;
	}
	StudentRecord(int r,const char* f,const char* d, float c, bool a) {
		rollNo = r;
		strcpy_s(f_name, f);
		strcpy_s(dept, d);
		cgpa = c;
		active_status = a;

	}

	int getRollNo() {
		return rollNo;
	}
	const char* getFName() {
		return f_name;
	}
	const char* getDept() {
		return dept;
	}

	float getCgpa() {
		return cgpa;
	}

	bool getActiveStatus() {
		return active_status;
	}


	void setRollNo(int r) {
		rollNo = r;
	}

	void setFName(char* c) {
		strcpy_s(f_name, c);

	}

	void setDept(char* d) {
		strcpy_s(dept, d);

	}

	void setCgpa(float c) {
		cgpa = c;
	}

	void setActiveStatus(bool a) {
		active_status = a;

	}

	void accept() {
		int checkActive;
		cout << "Enter the Roll No: " << endl;
		cin >> rollNo;
		cout << "Enter FullName: " << endl;
		cin >> f_name;
		cout << "Enter the dept: " << endl;
		cin >> dept;
		cout << "Enter your cgpa: " << endl;
		cin >> cgpa;
		cout << "Enter active status (1 for active, 0 for not active): " << endl;
		cin >> checkActive; // Missing input added
		if (checkActive == 1) {
			active_status = true;
		}
		else if(checkActive == 0) {
			active_status = false;

		}
		else {
			cout << "Enter only 1 -> for active or 0 -> for not active" << endl;
			cout << "Now by default the student will be active" << endl;
			active_status = true;
		}

	}



};

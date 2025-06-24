#include<iostream>
#include<string>
using namespace std;
struct Student_details{
	string roll_no;
	string student_name;
	int mark1;
	int mark2;
	int mark3;
	int total;
	Student_details* next;
};
int main(){
	string rollno;
	string name;
	int mark1;
	int mark2;
	int mark3;
	int total;
	cout<<"Enter your roll.no: ";
	cin>>rollno;
	cout<<"Enter your name: ";
	cin>>name;
	cout<<"Enter Mark 1: ";
	cin>>mark1;
	cout<<"Enter Mark 2: ";
	cin>>mark2;
	cout<<"Enter Mark 3: ";
	cin>>mark3;
	Student_details* student=new Student_details();
	student->roll_no=rollno;
	student->student_name=name;
	student->mark1=mark1;
	student->mark2=mark2;
	student->mark3=mark3;
	student->total=mark1+mark2+mark3;
	cout << "\nStudent Details\n";
    cout << "Roll No: " << student->roll_no << endl;
    cout << "Name: " << student->student_name << endl;
    cout << "Mark 1: " << student->mark1 << endl;
    cout << "Mark 2: " << student->mark2 << endl;
    cout << "Mark 3: " << student->mark3 << endl;
    cout << "Total: " << student->total << endl;
    delete student; 
    return 0; 
}
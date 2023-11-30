#include<iostream>
#include<fstream>
using namespace std;
class Employee
{
	string name;
	int ID;
	double salary;
	public :
	void accept()
	{
		cout<<"Enter name :";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter ID :";
		cin>>ID;
		cout<<"Enter salary :";
		cin>>salary;
	}
	void display()
	{
		cout<<"Name :"<<name;
		cout<<"ID :"<<ID;
		cout<<"Salary :"<<salary;
	}
};
int main()
{
	int i,n;
	fstream f;
	cout<<"Enter total number of employees :"<<endl;
	cin>>n;
	Employee e[n];
	
	f.open("demo.txt",ios::out);
	for(i=0;i<n;i++)
	{
		cout<<"Enter information of employee"<< i+1<<"\n";
		e[i].accept();
		f.write((char*)&e[i],sizeof e[i]);
	}
	f.close();
	f.open("demo.txt",ios::in);
	for(i=0;i<n;i++)
	{
		cout<<"Information of Employee :"<<endl;
		e[i].display();
		f.write((char*)&e[i],sizeof e[i]);		
	}
	f.close();
	return 0;	
}

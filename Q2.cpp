#include<iostream>
#include<string.h>
using namespace std;
class StudData;
class Student
{
	string name;
	int roll_no;
	string class_room;
	char* division;
	string dob;
	char* blood_group;
	static int count;
	public:
	Student()
	{
		name="";
		roll_no=0;
		class_room="";
		dob="dd/mm/yyyy";
		division = new char;
		blood_group=new char[4];
	}
	~Student()
	{
	delete division;
	delete[] blood_group;
	}
	static int get_count()
	{
		return count;
	}
	void get_data(StudData*);
	void display_data(StudData*);		
};
class StudData
{
	string address;
	long int* telephone;
	long int* driving_licence;
	friend class Student;
	public :
	StudData()
	{
		address="";
		telephone=new long;
		driving_licence=new long;
	}
	~StudData()
	{
		delete telephone;
		delete driving_licence;
	}
	void get_StudData()
	{
		cout<<"Enter your contact address :";
		cin.get();
		getline(cin,address);
		cout<<"Enter your telephone number :";
		cin>>*telephone;
		cout<<"Enter your driving license number :";
		cin>>*driving_licence;
	}
	void display_StudData()
	{
		cout<<"Contact address :"<<address<<endl;
		cout<<"Telephone number :"<<telephone<<endl;
		cout<<"Driving license number :"<<driving_licence<<endl;
	}	
};
inline void Student::get_data(StudData* st)
{
	cout<<"Enter name :";
	getline(cin,name);
	cout<<"Enter Roll number :";
	cin>>roll_no;
	cout<<"Enter class :";
	cin.get();
	getline(cin,class_room);
	cout<<"Enter your division :";
	cin>>*division;
	cout<<"Enter your DOB (dd/mm/yyyy) :";
	cin.get();
	getline(cin,dob);
	cout<<"Enter Blood group :";
	cin>>* blood_group;
	st->get_StudData();
	count++;
}
inline void Student::display_data(StudData* st1)
{
	cout<<"Name :"<<name<<endl;
	cout<<"Roll no."<<roll_no<<endl;
	cout<<"Class :"<<class_room<<endl;
	cout<<"Division :"<<division<<endl;
	cout<<"DOB :"<<dob<<endl;
	cout<<"Blood Gruop :"<<blood_group<<endl;
	st1->display_StudData();
}
int Student::count;
int main()
{
	Student* s1[100];
	StudData* s2[100];
	int n=0;
	char ch;
	do
	{
		s1[n]=new Student;
		s2[n]=new StudData;
		s1[n]->get_data(s2[n]);
		n++;
		cout<<"Do you want to add another student (Y/N) :";
		cin>>ch;
		cin.get();
	}while(ch=='y'|| ch=='Y');
	for (int i=0;i<n;i++)
	{
		cout<<"_____________________________________________"<<endl;
		s1[i]->display_data(s2[i]);
	}
	cout<<"_________________________________________________"<<endl;
	cout<<"Total students :"<<Student::get_count();
	cout<<endl<<"____________________________________________________"<<endl;
	for(int i=0;i<n;i++)
	{
		delete s1[i];
		delete s2[i];
	}
	return 0;
}




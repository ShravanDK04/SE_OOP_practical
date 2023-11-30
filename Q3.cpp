#include<iostream>
#include<stdio.h>
using namespace std;
class publication		  
{
	private:
		string title;
		float price;
	public:
		void data()
		{
			cout<<"Enter Title of the Publication :"<<endl;
			cin.ignore();
			getline(cin,title);
			cout<<"Enter the Price of Publication :"<<endl;
			cin>>price;	
		}
		void display()
		{
			cout<<"Title of Publication :"<<title;
			cout<<"Price of Publication :"<<price;
		}		
};
class book: public publication
{
	private:
		int page_count;
	public:
		void add_book()
		{
			try
			{
				data();
				cout<<"Enter Pages Count of Book :"<<endl;
				cin>>page_count;
				if(page_count<=0)
				{
					throw page_count;
				}
			}
			catch(...)
			{
				cout<<"INVALID CHOICE !!!"<<endl;
				page_count=0;	
			}
		}
		void display_book()
		{
			display();
			cout<<"Page count :"<<page_count<<endl;	
		}
 };
 class tape:public publication 
{
	private:
		float play_time;
	public:
		void add_tape()
		{
			try
			{
				data();
				cout<<"Enter play time of Tape :"<<endl;
				cin>>play_time;
				if(play_time<=0)
				{
					throw play_time;
				}			
			}
			catch(...)
			{
				cout<<"INVALID CHOICE !!!"<<endl;
				play_time=0;
			}
		}
		void display_tape()
		{
			display();
			cout<<"Play time :"<<play_time<<endl;
		}
		
};
int main()
{
	book b[1000];
	tape t[1000];
	int ch;
	int b_count;
	int t_count;
	do
	{
		cout<<"------------------MENU--------------------"<<endl;
		cout<<"1.Add book"<<endl;
		cout<<"2.Add tape"<<endl;
		cout<<"3.Display book"<<endl;
		cout<<"4.Display tape"<<endl;
		cout<<"Enter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
				b[b_count].add_book();
				b_count++;
				break;
			case 2:
				t[t_count].add_tape();
				t_count++;
				break;
			case 3:
				cout<<"****BOOK PUBLICATION DATABASE SYSTEM****"<<endl;
				for(int i=0;i<b_count;i++)
				{
					b[i].display_book();
				}
				break;
			case 4:
				cout<<"****TAPE PUBLICATION DATABASE SYSTEM****"<<endl;
				for(int i=0;i<t_count;i++)
				{
					t[i].display_tape();
				}
		}
	}
		while(ch!=5);
		return 0;	
}  

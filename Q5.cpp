#include<iostream>
using namespace std;
int n;
#define size 10
template<class T>
void selection(T A[size])
{
	int i,j,min;
	T temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
			{
				min=j;
			}
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}
	cout<<"Sorted array :";
	for(i=0;i<n;i++)
	{
	cout<<" "<<A[i];
	}
	cout<<endl;
}
int main()
{
	int A[size];
	float B[size];
	int i,ch;
	do
	{
		cout<<"***********MENU************"<<endl;
		cout<<"1.Integer value"<<endl;
		cout<<"2.Float value"<<endl;
		cout<<"3.EXIT"<<endl;
		cout<<"Enter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter total number of elements :";
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter element"<< i+1<<" :";
					cin>>A[i];
				}
				selection(A);
				break;
			case 2:
				cout<<"Enter total number of elements :";
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter element"<< i+1<<" :";
					cin>>B[i];
				}
				selection(B);
			case 3:
				cout<<"EXITING PROGRAM ..."<<endl;
				break;
				
		}
	}
	while(ch!=3);
	return 0;
}

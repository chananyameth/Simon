#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;

void hatzava(int* arr,const int length)
{
	if(length==7)
	{
		for(int i=0; i<length; ++i)
			arr[i] = (rand()%4)+1;
	}
	else if(length==8)
	{
		for(int i=0; i<length; ++i)
			arr[i] = (rand()%7)+1;
	}
	else if(length==9)
	{
		for(int i=0; i<length; ++i)
			arr[i] = (rand()%9)+1;
	}
}
int* haktzaah(int* arr, int& length)
{
	delete arr;
	int temp;
	cout<<"press:\n(1) kal - 7 numbers, (2) beynoni - 8 numbers, (3) kasheh - 9 numbers:	";
	cin>>temp;
	system("CLS");
	if(temp==1)
	{
		arr = new int[7];
		length = 7;
		hatzava(arr,length);
	}
	else if(temp==2)
	{
		arr = new int[8];
		length = 8;
		hatzava(arr,length);
	}
	else if(temp==3)
	{
		arr = new int[9];
		length = 9;
		hatzava(arr,length);
	}
	else
	{
		cout<<"Error! the input isn't valid!\n";
		arr = new int;
		arr = haktzaah(arr,length);
	}
	return arr;
}
void print(int* arr,const int length)
{
	cout<<"retzef:\n";
	for(int i=0; i<length; ++i)
	{
		cout<<arr[i]<<" ";
		Sleep(800);
	}
	cout<<endl;
}
void nekudot3()
{
	for(int i=0; i<3; ++i)
	{
		Sleep(500);
		cout<<".";
	}
	Sleep(300);
}
void hikon_hachen()
{
	cout<<"hikon";
	nekudot3();
	system("CLS");
	cout<<"hachen";
	nekudot3();
	system("CLS");
	cout<<"tze!!!!!!!!!";
	Sleep(1000);
	system("CLS");
}
void main()
{
	int* arr=new int;
	int* input;
	int length;
	bool flag=1;
	srand(time(NULL));

	arr = haktzaah(arr,length);
	input=new int[length];
	hikon_hachen();
	for(int i=0; i<length; ++i)
	{
		if(!flag) break;
		print(arr,i+1);
		Sleep(200);
		system("CLS");

		for(int j=0; j<=i; ++j)
		{
			cin>>input[j];
			if(input[j] != arr[j])
			{
				flag=0;
				break;
			}
		}
		system("CLS");
	}
	if(flag)
		cout<<"very good!\n";
	else
		cout<<"sorry.. try again!\n";

	delete[] arr;
	Sleep(2000);
}
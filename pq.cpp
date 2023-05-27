#include<iostream>
#include<string>
//#define N 20
using namespace std;
string Q[10];
int Pr[10];
int r = -1,f = -1,n;
void enqueue(string data,int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==n-1)) //Check if Queue is full
		cout<<"Queue is full";
	else 
	{
		if(f==-1) { //if Queue is empty
		f = r = 0;
		Q[r] = data;
		Pr[r] = p;
		}
	else {
		for(i = r;i>=f;i--)
		{
			if(p>Pr[i]) {
			Q[i+1] = Q[i];
			Pr[i+1] = Pr[i];
			}
			else break;
		}
		Q[i+1] = data;
		Pr[i+1] = p;
		r++;
	    }
	}
}

void print() 
{ 		//print the data of Queue
	int i;
	for(i=f;i<=r;i++)
	 {
		cout << "Patient's Name - "<<Q[i];
		switch(Pr[i]) {
			case 1:
				cout << " Priority - 'Checkup' " << endl;
				break;
			case 2:
				cout << " Priority - 'Non-serious' " << endl;
				break;
			case 3:
				cout << " Priority - 'Serious' " << endl;
				break;
			default:
				cout << "Priority not found" << endl;

				}
	}
}
void dequeue() { //remove the data from front
	if(f == -1) {
	cout<<"Queue is Empty";
	}
	else {
	cout<<"deleted Element ="<<Q[f]<<endl;
	cout<<"Its Priority = "<<Pr[f]<<endl;
	if(f==r) f = r = -1;
	else f++;
	}
}
int main() {
	string data;
	int opt,i,p;
	cout<<"Enter Your Choice:-"<<endl;
	do {

		cout << "1 for Insert the Data in Queue" << endl << "2 for show the Data in Queue " << endl << "3 for Delete the data from the Queue"<< endl << "0 for Exit"<< endl;
		cin >> opt;
	switch(opt) {
		case 1:
			cout << "Enter the number of patinent" << endl;
			cin >> n;
			i = 0;
			for(i=0;i<n;i++)
			{

				cout << "Enter your name of the patient : ";
				cin >> data;
				cout << "Enter your Prioritys (3: serious, 2:non-serious, 1: genral checkup) : ";

				cin >> p;
				enqueue(data,p);

			}
			break;
		case 2:
			print();
			break;
		case 3:
			dequeue();
			break;
		}
	}while(opt!=0);
	return 0;
}

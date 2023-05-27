#include<fstream>
#include <iostream>
#include<string.h>
using namespace std;
struct stud
{
    int rno;
    char nm[10];
}s;
void create()
{
    ofstream fout;
    int n,i;
    fout.open("stud1.txt",ios::out); //fout=write into file
    cout<<"\nEnter the Number of record=";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter roll no & name=";
        cin>>s.rno>>s.nm;
        fout<<endl<<s.rno<<"\t"<<s.nm;
    }
    fout.close();
}
void display()
{
    ifstream fin;
    fin.open("stud1.txt",ios::in); //fin = read from file
    while(!fin.eof())
    {
        fin>>s.rno>>s.nm;
        cout<<"\n"<<s.rno<<"\t"<<s.nm;
    }
    fin.close();
}
void search()
{
    ifstream fin;
    int fl,key;
    cout<<"\nEnter number of element=";
    cin>>key;
    fin.open("stud1.txt",ios::in); //fin = read from file
    while(!fin.eof())
    {
        fin>>s.rno>>s.nm;
        if(s.rno==key)
        {
            fl=1;
            break;
        }
    }
    if(fl==1)
        cout<<"\nElement found"<<s.rno<<"\t"<<s.nm;
    else
        cout<<"\nElement not found";
    fin.close();
}
void delete_rec()
{
    ifstream fin,fin1;
    ofstream fout,fout1;
    int key,flag=0;
    cout<<"\n Enter the key to be deleted=";
    cin>>key;
    fin.open("stud1.txt",ios::in);//fin = read from file
    fout.open("temp.txt",ios::out);//out = write
    while(!fin.eof())
    {
        fin>>s.rno>>s.nm;
        if(key==s.rno)
        {
            flag=1;
        }
        else
            fout<<endl<<s.rno<<s.nm;
    }
    fin.close();
    fout.close();
    fin1.open("temp.txt",ios::in);
    fout1.open("stud1.txt",ios::out);
    while(!fin1.eof())
    {
        fin1>>s.rno>>s.nm;
        fout1<<endl<<s.rno<<s.nm;
    }
    fin1.close();
    fout1.close();
    if(flag!=1)
        cout<<"\nRecord Not found!!";
    else
    display();
}
void update_rec()
{
    ifstream fin,fin1;
    ofstream fout,fout1;
    int key,flag=0;
    cout<<"\n Enter the key to be updated=";
    cin>>key;
    fin.open("stud1.txt",ios::in);//fin = read from file
    fout.open("temp.txt",ios::out);//out = write
    while(!fin.eof())
    {
        fin>>s.rno>>s.nm;
        if(key==s.rno)
        {
            flag=1;
            cout<<"\nEnter new record(Roll no,Name)=";
            cin>>s.rno>>s.nm;
            fout<<endl<<s.rno<<s.nm;
        }
        else
            fout<<endl<<s.rno<<s.nm;
    }
    fin.close();
    fout.close();
    fin1.open("temp.txt",ios::in);
    fout1.open("stud1.txt",ios::out);
    while(!fin1.eof())
    {
        fin1>>s.rno>>s.nm;
        fout1<<endl<<s.rno<<s.nm;
    }
    fin1.close();
    fout1.close();
    if(flag!=1)
        cout<<"\nRecord Not found!!";
    else
    display();
}
int main()
{
    int res;
    int ch;
    do
    {
        cout<<"\n1.Create\n2.Dispaly\n3.Search\n4.Delete Record\n5.Update";
        cout<<"\nEnter your choice==";
        cin>>ch;
        switch(ch)
        {
            case 1:create();
                break;
            case 2:display();
                break;
            case 3:search();
                break;
            case 4:delete_rec();
                break;
            case 5:update_rec();
                break;
        }
    }while(ch<7);
}
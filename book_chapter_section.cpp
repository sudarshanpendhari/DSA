#include<iostream>
using namespace std;
class node{
    public:
        string label;
        int cnt;
        node *child[10];
}*root; 
class Gt{
    public:
        void createTree();
        void display(node *root);
        Gt(){
            root=NULL;
        }


};
void Gt::createTree(){
    int tbook,tchap,i,j,k;

    root=new node;

    cout<<"Enter book name=";
    cin>>root->label;

    cout<<"Enter no. of chapters=";
    cin>>tchap;
    root->cnt=tchap;
    for(i=0;i<tchap;i++){

        root->child[i]=new node;

        cout<<"Enter chap name=";
        cin>>root->child[i]->label;

        int tsec;
        cout<<"Enter no. of sections in chapter="<<root->child[i]->label<<"==";
        cin>>tsec;
        root->child[i]->cnt=tsec;

        for(j=0;j<tsec;j++){
            root->child[i]->child[j]=new node;

            cout<<"Enter section"<<j+1<< "name=";
            cin>>root->child[i]->child[j]->label;

            cout<<"Enter no. of subsections in section="<<j+1<<"==";
            cin>>root->child[i]->child[j]->cnt;

 
        }
    }
}
void Gt::display(node *root){
    if(root!=NULL){
        cout<<"---Book Hierarchy---"<<endl;
        cout<<"Book Title="<<root->label;

        for(int i=0;i<root->cnt;i++){
            cout<<"\nchapter "<<i+1<<"--"<<root->child[i]->label;
            cout<<"\nsections\n";
            for (int j=0;j<root->child[i]->cnt;j++){
                cout<<j+1<<root->child[i]->child[j]->label<<", No. of subsection="<<root->child[i]->child[j]->cnt<<endl;
                
            }

        }
    }

}
int main(){
    int choice;
    Gt gt;
    gt.createTree();
    gt.display(root);
    ///make your own menu for create and display
    return 0;
}
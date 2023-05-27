#include<iostream>
using namespace std;
class node
{
public:
int data;
node *left,*right;
}*root;
class BST
{    
    public:

    BST()
    {
    root=NULL;
    }
    node *createBST();
    void inorder(node*root);
    void find_min(node*root);
    void find_max(node*root);
    void search(node*root);
    void mirror(node*root);
    int height(node*root);
};
node *BST::createBST()
{
    int x;
    node*trav;
    cout<<"Enter the data = ";
    cin>>x;
    node *temp;
    temp=new node;
  // temp->left=NULL;
  //  temp->right=NULL;
    temp->data=x;
    if(root==NULL)
    {
    root=temp;
    }
    else
    {
    trav=root;
    while(trav!=NULL)
    {
    if(x<trav->data)
    {    if(trav->left==NULL)
    {
    trav->left=temp;
    break;
    }
   
    trav=trav->left;
   
    }
    else
    {
    if(trav->right==NULL)
    {
    trav->right=temp;
    break;
    }
   
    trav=trav->right;
    }
    }
    }
  return root;
}
void BST::inorder(node*root)
{
    int top=-1;
    node*stack[10];
    while(root!=NULL || top!=-1)
    {
    if(root!=NULL)
    {
    stack[++top]=root;
    root=root->left;
    }
    else
    {
    root=stack[top--];
    cout<<root->data;
    root=root->right;
    }
    }
}

void BST::find_min(node*root)
{
    node*trav;
    trav=root;
    while(trav->left!=NULL)
    {
    trav=trav->left;
    }
    cout<<"Minimum value of given BST is : "<<trav->data;
}

void BST::find_max(node*root)
{
    node*trav;
    trav=root;
    while(trav->right!=NULL)
    {
    trav=trav->right;
    }
    cout<<"maximum value of given BST is : "<<trav->data;
}
void BST::search(node*root)
{
    node*trav;
    int key;
    int flag=0;
    cout<<"Enter the key:";
    cin>>key;
    trav=root;
    while(trav!=NULL)
    {
    if(trav->data==key)
    {
    flag=1;
    break;
    }
    else if(key<trav->data)
    {
    trav=trav->left;
    }
    else
    {
    trav=trav->right;
    }
    }
    if(flag==1)
    {
    cout<<"Found\n";
   
    }
    else
    {
	cout<<"Not found\n";
    	
    }
}
void BST::mirror(node*root)
{
    node*temp;
    if(root!=NULL)
    {
    mirror(root->left);
    mirror(root->right);
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    }
}
int BST::height(node*root)
{
if(root==NULL)
{
return 0;
}
else
{
int lh=height(root->left);
int rh=height(root->right);
return 1+max(lh,rh);

}

}

int main()
{    
    BST B;
    int choice;
    node *root;
   
do
{
    cout<<"\n~~~~~~~~~~~~~~~~Binary Tree~~~~~~~~~~~~~~~~";
    cout<<"\n1.Create node\n2.Inorder Traversal\n3.Minimum Value\n4.Maximum value\n5.search\n6.mirror\n7.height "<<endl;
   
    cout<<"Enter the choice:";
    cin>>choice;
   
    switch (choice)
    {
    case 1:root=B.createBST();
    break;
    case 2:B.inorder(root);
    break;
    case 3:B.find_min(root);
    break;
    case 4:B.find_max(root);
    break;
    case 5:B.search(root);
    break;
    case 6:B.mirror(root);
    break;
case 7:int h=B.height(root);
  cout<<h;
    break;    
    }
}while(choice!=8);
   
   

return 0;
}





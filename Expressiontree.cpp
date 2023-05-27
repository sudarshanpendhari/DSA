#include <iostream>
#include <stack>


using namespace std;

class node
{	public:
	char data;
	node *left,*right;
}*root;

class Etree{
	public:
	
	Etree(){
		root=NULL;
		}
	node *createExpTree(){
		stack<node *>st;
		node* temp,*temp1;
		char exp[10];
		cout<<"enter the prefix expression==";
		cin>>exp;
		int len=0;
		for(int i=0;exp[i]!='\0';i++)
		{
			len=i;
		}
		for (int i=len;i>=0;i--)
		{
			char ch=exp[i];
			if(ch>='a'&& ch<='z')
			{	temp1=new node;
				temp1->data=ch;
				temp1->left=NULL;
				temp1->right=NULL;
				st.push(temp1);
			}
			else{
				temp=new node;
				temp->data=ch;
				temp->left=NULL;
				temp->right=NULL;
				temp->left=st.top();
				st.pop();
				temp->right=st.top();
				st.pop();
				st.push(temp);
				
				}
		}
		root=st.top();
		return root;
	}	
	void inorder(node*root)
	{	if(root==NULL)
			return;
		inorder(root->left);
		cout<<root->data;
		inorder(root->right);
	}
};
int main()
{	
	Etree E;
	node *root =E.createExpTree();
	cout<<"Expression tree is created"<<endl;
	cout<<"Inorder traversal of the expression tree:";
	E.inorder(root);


return 0;}	
	

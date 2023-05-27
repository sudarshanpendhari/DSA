#include<iostream>
using namespace std;
class node
{	public:
	int data;
	node *left,*right;
};

class BTree
{	public:
	
	
	node* createTree()
	{
		int x;	
		node *root;
		cin>>x;
		if(x==-1)
		{	return NULL;}
		root=new node();
		root->data=x;
		root->left=createTree();
		root->right=createTree();
		return root;
	}
	void inorder(node *root){
		if(root==NULL)
			return ;
		inorder(root->left);
		cout<<root->data;
		inorder(root->right);
		
	}

	void preorder(node *root)
	{	if(root==NULL)
			return ;
		cout<<root->data;
		preorder(root->left);
	
		preorder(root->right);

	}
	void postorder(node *root)
	{	if(root==NULL)
			return ;
		postorder(root->left);
	
		postorder(root->right);
		cout<<root->data;

	}
};

int main()
{	
	node *root;
	BTree T;
	root=T.createTree();
	T.inorder(root);


return 0;}
		
			

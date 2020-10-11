#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *right;
	struct node *left;
};

class Dlist
{
	public:
	struct node *root;
	
	void createDlist()
	{
		root=NULL;
	}
	
	void insertleft(int e)
	{
		node *n;
		n= new node;
		n->data=e;
		n->left=NULL;
		n->right=NULL;
		if(root==NULL)
		{
			root=n;
		}
		else
		{
			n->right=root;
			root->left=n;
			root=n;
		}
	}
	
	void insertright(int e)
	{
		node *n,*t;
		n=new node;
		n->data=e;
		n->left=NULL;
		n->right=NULL;
		if(root==NULL)
		{
			root=n;
		}
		else
		{
			t=root;
			while(t->right!=NULL)
			{
				t=t->right;
			}
			t->right=n;
			n->left=t;
		}
	}
	
	void deleteleft()
	{
		node *t;
		if(root==NULL)
		{
			cout<<"Empty";
		}
		else
		{
			t=root;
			root=root->right;
			root->left=NULL;
			cout<<"deleted :"<<t->data;
			delete t;
		}
	}
	
	void deleteright()
	{
		node *t,*t2;
		if(root==NULL)
		{
			cout<<"Empty";
		}
		else
		{
			t=root;
			while(t->right!=NULL)
			{
				t=t->right;
			}
			t2=t->left;
			t2->right=NULL;
			cout<<"deleted :" <<t->data;
			delete t;
		}
	}
	
	void revprint()
	{
		node *t;
		if (root==NULL)
		{
			cout<<"Empty";
		}
		else
		{
			t=root;
			while(t->right!=NULL)
			{
				t=t->right;
			}
			while(t!=NULL)
			{
				cout<<t->data;
				t=t->left;
			}
		}
	}
};

int main()
{
	int no,e;
	Dlist c;
	c.createDlist();
	do
	{
		cout<<"\n 1.insertleft \n 2.insertright \n 3.deleteleft \n 4.deleteright \n 5.print \n 0.exist \n";
		cin>>no;
		switch(no)
		{
			case 1:
				cout<<"Enter data";
				cin>>e;
				c.insertleft(e);
				break;
				
			case 2:
				cout<<"Enter Data";
				cin>>e;
				c.insertright(e);
				break;
				
			case 3:
				c.deleteleft();
				break;
				
			case 4:
				c.deleteright();
				break;
				
			case 5:
				c.revprint();
				break;
				
			case 0:
				cout<<"Existing";
				break;
				
			default:
				cout<<"Error";
				break;		
		}
	}while(no!=0);
}

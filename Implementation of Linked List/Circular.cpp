#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;	
};

class CRD
{
	public:
	struct node *root ,*last;
	
	void createlist()
	{
		root=last=NULL;
	}
	
	void insertleft(int e)
	{
		node *n;
		n=new node;
		n->data=e;
		n->next=NULL;
		if(root==NULL)
		{
			root=last=n;
			last->next=root;
		}
		else
		{
			n->next=root;
			root=n;
		}
	}
	void insertright(int e)
	{
		node *n;
		n=new node;
		n->data=e;
		n->next=NULL;
		if(root==NULL)
		{
			root=last=n;
			last->next=root;
		}
		else
		{
			last->next=n;
			last=n;
			last->next=root;
		}
	}
	void deleteleft()
	{
		node *t;
		if(root==NULL)
		{
			cout<<"empty";
		}
		else
		{
			t=root;
			root=root->next;
			last->next=root;
			cout<<"deleted : "<<t->data;
			delete t;
		}
	}
	void deleteright()
	{
		node *t,*t2;
		if(root==NULL)
		{
			cout<<"empty";
		}
		else
		{
			t=root;
			while(t!=last)
			{
				t2=t;
				t=t->next;	
			}
			t2=last;
			last->next=root;
			cout<<"deleted : "<<t->data;
			delete t;
		}
	}
	void printlist()
	{
		node *t;
		if(root==NULL)
		{
			cout<<"Empty";
		}
		else
		{
			t=root;
			do
			{
				cout<<t->data;
				t=t->next;
			}while(t!=root);
		}
	}
};

int main()
{
	int no,e;
	CRD c;
	c.createlist();
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
				c.printlist();
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

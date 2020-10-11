#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;//self reffering node
};
class DynamicQueue
{
	public:
		node *rear,*front;
		
	void createQueue()
	{
		rear=front=NULL;
	}
	
	void Enqueue(int e)
	{
		node *n;
		n=new node;
		n->data=e;
		n->next=NULL;
		if(rear==NULL)
		{
			rear=front=n;
		}
		else
		{
			rear->next=n;
			rear=n;
			rear->next=NULL;
		}
	}
	
	void Dequeue()
	{
		node *t;
		if (front==NULL)
		{
			cout<<"Queue is Empty";
		}
		else
		{
			t=front;
			front=front->next;
			cout<<"Dequeue"<<t->data;
			delete t;
		}
	}
	
	void printQueue()
	{
		if(front==NULL)
		{
			cout<<"queue is empty";
		}
		else
		{
			node *t;
			t=front;
			while(t!=NULL)
			{
				cout<<t->data;
				t=t->next;
			}
		}
	}	
};

int main()
{
	int no ,e;
	DynamicQueue q;
	q.createQueue();
	do
	{
		cout<<"\n 1.Enqueue \n 2.Dequeue \n 3.print \n 0.exit \n";
		cin>>no;
		switch(no)
		{
			case 1:
				cout<<"Enter data";
				cin>>e;
				q.Enqueue(e);
				break;
				
			case 2:
				q.Dequeue();
				break;
				
			case 3:
				q.printQueue();
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

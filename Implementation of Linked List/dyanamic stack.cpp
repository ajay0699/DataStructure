#include<iostream>
using namespace std;

struct node 
{
	
	int data;
	struct node *next;//self refering node
};
 class DynamicStack
 {
 	public:
 	node *tos;
 	
 	void createStack()
	 {
	 	tos=NULL;
	 }
	 
	 void push(int e)
	 {
	 	node *n;
	 	n=new node;
	 	n->data=e;
	 	n->next=NULL;
	 	if(tos==NULL)
	 	{
	 		tos=n;
		}
		else
		{
			n->next=tos;
			tos=n;	
		}
	 }
	 
	 int pop()
	 {
	 	node *t;
	 	if(tos==NULL)
	 	{
	 		cout<<"Stack is empty";
		}
		else
		{
			t=tos;
			tos=tos->next;
			cout<<"poped :"<<t->data;
			delete t;
		}
	}
	
	 void printStack()
	 {
	 	node *t;
	 	t=tos;
	 	while(t!=NULL)
	 	{
	 		cout<<"\n"<<t->data;
	 		t=t->next;
		}
	 }
	
 };
 
 int main()
 {
 	int no,e;
 	DynamicStack s;
 	s.createStack();
 	do
 	{
 		//cout<<"Enter the no";
 		
 		cout<<"\n 1.push\n 2.pop \n 3.print\n 0.exit\n ";
 		cin>>no;
 		switch(no)
		 {
		 	case 1:
		 		cout<<"enter data";
		 		cin>>e;
		 		s.push(e);
		 		break;
		 		
		 	case 2:
			 	s.pop();
			 	break;
				 
			case 3:
				s.printStack();
				break;
				
			case 0:
				cout<<"Existing";
				break;
				
			default:
				cout<<"error";
				break;	 	
		 }
	}while(no!=0);
 }

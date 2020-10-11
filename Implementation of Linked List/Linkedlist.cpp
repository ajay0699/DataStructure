#include<iostream>
#include<string.h>
using namespace std;

struct node{
	int data;
	struct node *next;//self reffering structure
};

class Linklist{
	public:
		struct node *root;
		
		void createLinklist(){
			root=NULL;
		}
		
		void insertLeft(int e){
			node *n;
			n=new node;
			n->data=e;
			n->next=NULL;
			if(root==NULL){
				root=n;
			}
			else{
				n->next=root;//1
				root=n;//2
			}			
		}
		
		void insertRight(int e)
		{
			node *n,*t;
			n=new node;
			n->data=e;
			if(root==NULL)
			{
				root=n;
			}
			else
			{
				t=root;
				while(t->next!=NULL)
				{
					t=t->next;
				}
				t->next=n;
				n->next=NULL;
			}
		}
		
   		void deleteLeft(){
			node *t;
			if(root==NULL){
				cout<<"Empty Linkedlist";
			}else
			{
				t=root;
				root=root->next;
				cout<<"deleted"<<t->data;
				delete t;
			}
		}
		
		void deleteRight(){
			node *t,*t2;
			if(root==NULL){
				cout<<"Empty LinkedList";
			}
			else{
				t=t2=root;//1.copy
				while(t->next!=NULL){
					t2=t;
					t=t->next;
				} 
				t2->next=NULL;//3 element next will be null
				cout<<"Deleteing"<<t->data;
				delete t;//4 delete
			}
		}
		
		void print(){
			node *t;
			if(root==NULL){
				cout<<"Empty LinkedList";
			}
			else{
				t=root;// copy root into t
				while(t!=NULL){
					cout<<"\n"<<t->data;
					t=t->next;
				}
			}
		}
		
			int search(int e)
		{
			node *t;
			if(root==NULL)
			{
				cout<<"Empty LinkedList";
				return 0;
			}
			else
			{
				t=root;
				while(t!=NULL)
				{
					if(t->data==e)
					{
						return e;
					}
					else
					{
						t=t->next;
					}
				}
				return 0;	
			}
		}
		
		void serachNdelete(int e){
			node *t,*t2;
			if(root==NULL){
				cout<<"Empty LinkedList";
			}
			else{
				t=t2=root;
				while(t!=NULL && t->data!=e){
					t2=t;
					t=t->next;
				}
					if(t!=NULL){
						if(t==root){
							root=root->next;
						}
						else if (t->next==NULL){
							t2->next=NULL;
						}
						else{
							t2->next=t->next;
						}
						cout<<"\n delted "<<t->data;
						delete t;
					}
					else{
						cout<<"Not Found";
					}
				
			}
		}
		
};


int main(){
	int no,e ;
	Linklist L;
	L.createLinklist();
	cout<<"Enter a no for performing task";
	cin>>no;
	do{
		
		cout<<"\n 1.insertLeft\n 2.insertRight\n 3.deleteLeft\n 4.deleteRight\n 5.print\n 6.search\n 7.searchNdelete\n0:exit\n";
		cin>>no;
		switch(no){
			case 1:
				cout<<"Enter a data which you want insert";
				cin>>e;
				L.insertLeft(e);
				break;
			case 2:	
				cout<<"Enter a data which you want insert";
				cin>>e;
				L.insertRight(e);
				break;
			case 3:
				L.deleteLeft();
				break;
			case 4:
				L.deleteRight();
				break;
			case 5:
				L.print();
				break;
			case 6:	
				cout<<"Enter a no which you want to serach";
				cin>>e;
				cout<<L.search(e);
				break;
				
			case 7:
				cout<<"Enter a no which you want to serach n delete";
				cin>>e;
				L.serachNdelete(e);
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

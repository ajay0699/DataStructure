#include<iostream>
using namespace std;

int Q[100],Maxsize,front,rear;
void createQueue(int size){
	Maxsize=size;
	front=0;
	rear=-1;
}
void Enqueue(int e){
	rear++;
	Q[rear]=e;
}
int Dequeue(){
	int temp=Q[front];
	front++;
	return(temp);
}
int isFull(){
	if(rear==Maxsize){
		return 1;
	}else{
		return 0;
	}
}
int isEmpty(){
	if(front>rear){
		return 1;
	}else{
		return 0;
	}
}
void printQueue(){
	int i;
	for(i=front;i<=rear;i++){
		cout<<Q[i];
	}
}
int main(){
	int ch,e,size;
	cout<<"Enter no";
	cin>>ch;
	createQueue(100);//initailization of queue
	do{
		cout<<"\n1:Enqueue\n2:Dequeue\n3:Print\n0:exit\n:";
		cin>>ch;
		switch(ch){
			case 1:
				if(isFull()==1){
					cout<<"Full";
				}
				else{
					cout<<"Enter data";
					cin>>e;
					Enqueue(e);
				}
				break;
			case 2:
					if(isEmpty()==1){
				std::cout<<"empty";
			}	
			else{
				e=Dequeue();
				std::cout<<"Dequeue"<<e;
			}
			break;
		
			case 3:
				if(isEmpty()==1){
				std::cout<<"empty";
			}	
			else{
				printQueue();
			}
			break;
			case 0:
			cout<<"Existing";
			break;
			default:
			cout<<"error";
			break;	
		}		
	}while(ch!=0);
}

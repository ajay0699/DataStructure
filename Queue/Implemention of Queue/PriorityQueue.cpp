#include<iostream>
using namespace std;

int Q[100],Maxsize,front,rear,count;
void createQueue(int size){
	Maxsize=size;
	count=0;
	front=0;
	rear=-1;
}
void Enqueue(int e){
	int i,j,t;
	rear=(rear+1)%Maxsize;
	count++;
	Q[rear]=e;
	for(i=front;i<rear;i++){
		for(j=front;j<rear;j++){
			if(Q[j]>Q[j+1]){
				t=Q[j];
				Q[j]=Q[j+1];
				Q[j+1]=t;			
			}
		}
	}
}
int Dequeue(){
	int temp;
	count--;
	temp=Q[front];
	front=(front+1)%Maxsize;
	return(temp);
}
int isFull(){
	if(count==Maxsize){
		return 1;
	}else{
		return 0;
	}
}
int isEmpty(){
	if(count==0){
		return 1;
	}else{
		return 0;
	}
}
void printQueue(){
	int c,i;
	i=front;
	c=0;
	while(c<count){
		cout<<Q[i];
		i=(i+1)%Maxsize;
		c=c+1;
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

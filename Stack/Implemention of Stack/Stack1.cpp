#include<iostream>
using namespace std;
int s[100],MaxSize,tos;

 initStack(int size){
	MaxSize=size;//initialization size of stack
	tos=-1;// default value of tos
}
push(int e){
	tos++;//increment tos by 1
	s[tos]=e;//Accepet e in stack
}
int isFull(){
	if(tos==MaxSize-1)//check whether stack is full or not
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pop(){
	int temp;//temp variable store a data to return 
	temp=s[tos];
	tos--;
	return(temp);
}
int isEmpty(){
	if (tos==-1)//check whether stack is empty or not
	{
		return 1;
	}
	else{
		return 0;
	}
}
int atTop(){
	return (s[tos]);//return top most element from stack
}
void printStack(){
	int i;
	for(i=tos;i>-1;i--){
		std::cout<<s[i];
	}
}
int main()
{
	int ch,rem;
	std::cout<<"Enter no";
	std::cin>>ch;
	initStack(10);
	while(ch!=0){
		rem=ch%2;
		ch=ch/2;
		push(rem);
	}
	printStack();
/*	do{
		std::cout<<"\n1:push\n2:pop\n3:atTop;\n4:Print\n0:exit\n:";
		std::cin>>ch;
		switch(ch){
			case 1:
				if(isFull()==1){
					std::cout<<"Full";
				}
				else{
					std::cout<<"Enter data";
					std::cin>>e;
					push(e);
				}
				break;
			case 2:
					if(isEmpty()==1){
				std::cout<<"empty";
			}	
			else{
				e=pop();
				std::cout<<"poped"<<e;
			}
			break;
			case 3:
				if(isEmpty()==1){
				std::cout<<"empty";
			}	
			else{
				e=atTop();
				std::cout<<"Topped"<<e;
			}
			break;
			case 4:
				if(isEmpty()==1){
				std::cout<<"empty";
			}	
			else{
				printStack();
			}
			break;
			case 0:
			std::cout<<"Existing";
			break;
			default:
			std::cout<<"error";
			break;	
		}		
	}while(ch!=0);*/
}

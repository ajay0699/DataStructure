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
	cout<<"Enter no";
	cin>>ch;
	initStack(10);
	
	while(ch!=0){
		rem=ch%2;
		ch=ch/2;
		push(rem);
	}
	printStack();

}


#include<iostream>
#include<string.h>
using namespace std;
int s[100];
int maxsize,tos;
void stack(int n)
{
	maxsize=n;
	tos=-1;
}
void push(int e)
{
	tos++;
	s[tos]=e;
}
char pop()
{
	char temp;
	temp=s[tos];
	tos--;
	return temp;
}
int isEmpty()
{
	if(tos==-1)
		return 1;
	else
		return 0;
}
int logic(int a,int b,char c)
{
	if(c=='+')
	return (a+b);
	else if(c=='-')
	return (a-b);
	else if(c=='*')
	return (a*b);
	else if(c=='/')
	return (a/b);
}
void PrintStack()
{
    int i;
    for(i=tos;i>-1;i--)
    {
        cout<<s[i];
    }
}
int main()
{
	char preFx[100],c;
	int pi=0,i;
	cout<<"Enter prefix: ";
	cin>>preFx;
	int k=strlen(preFx);
	stack(k);
	
	for(int i=strlen(preFx);i>=0;i--)
	{
		c=preFx[i];
		switch(c)
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				int a;
				a=pop();
				int b;
				b=pop();
				int z;
				z=logic(a,b,c);
				push(z);
				break;
			default:
				char x=c;
				int no=x-'0';
				if(no >= 0 && no <= 9){
					push(no);
				}
				break;
		}
	}
	PrintStack();
}

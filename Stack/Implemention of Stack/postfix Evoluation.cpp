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
	return (b+a);
	else if(c=='-')
	return (b-a);
	else if(c=='*')
	return (b*a);
	else if(c=='/')
	return (b/a);
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
	char postFx[100],c;
	int pi=0,i;
	cout<<"Enter postfix: ";
	cin>>postFx;
	int k=strlen(postFx);
	stack(k);
	
	for(int i=0;i<strlen(postFx);i++)
	{
		c=postFx[i];
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
				push(no);
				break;
		}
	}
	PrintStack();
}

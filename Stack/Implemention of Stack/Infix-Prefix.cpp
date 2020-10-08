#include<iostream>
#include<string.h>
using namespace std;
char s[100];
int maxsize,tos;
void stack(int n)
{
	maxsize=n;
	tos=-1;
}
void push(char e)
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
int Preced(char c)
{
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/'||c=='%')
		return 2;
	if(c=='^')
		return 3;
	else
		return 0;
}
int main()
{
	char inFx[100],prFx[100],c;
	int pi=0,i;
	cout<<"Enter Infix: ";
	cin>>inFx;
	int k=strlen(inFx);// Rule 1:(Accept infix &ini stack)count the how much long stack want to be create
	stack(k);
	
	for(int i=strlen(inFx);i>=0;i--)//Rule 2:read infix R to L
	{
		c=inFx[i];
		switch(c)
		{
			case ')'://rule 3.1:')'push it on Stack
				push(c);
				break;
			
			case '('://Rule 3.2 ')' pop everything from stack till')' &cpoy poped to prefix
				while(s[tos]!=')')
				{
					prFx[pi]=pop();
					pi++;
				}
				c=pop();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while((Preced(s[tos])>=Preced(c)) && (isEmpty()!=1))//Rule 3.3 Operator:if precedance of operator on tos is lesser compute to new operator then push it on stack
				{
					prFx[pi]=pop();
					pi++;	
				}
				push(c);
				break;
			default:
				prFx[pi]=c;
				pi++;
				break;
		}
	}
	while(isEmpty()!=1)//copy leftover from stack to pretfix 
	{
		prFx[pi]=pop();
		pi++;
	}
	
	for(i=pi;i>=0;i--)
	{
		cout<<prFx[i];
	}
}

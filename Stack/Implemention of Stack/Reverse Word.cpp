#include <iostream>
using namespace std;
char s[100],tos,MaxSize;
int stack (int size)
{
    MaxSize=size;
    tos=-1;
}
 void push(char e)
{
    tos++;
    s[tos]=e;
}
 int isFull()
{
    if(tos==MaxSize-1)
    return 1; 
    else
    return 0;
}
int pop()
{
    int temp;
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
int atTop()
{
    return (s[tos]);
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
    char a[10];
   
    cout<<"Enter data";
    cin>>a;
    stack(20);
    for(int i=0;i<=9;i++)
    {
		push(a[i]);
	}
	PrintStack();
}

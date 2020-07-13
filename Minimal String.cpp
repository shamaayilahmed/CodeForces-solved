#include<iostream>
#include<string>
#include<stack>
using namespace std;
const int MAX=1e5+5;
int main()
{
    char String[MAX];
    gets(String);
    int Size=strlen(String);
    char best[MAX];
    best[Size]='z';
    for(int i=Size-1;i>=0;i--)
    {
        best[i]=min(best[i+1],s[i]);
    }
    stack<char>Stack;
    int pointer=0;
    while(!Stack.empty()||pointer<Size)
    {
        if(!Stack.empty()&&Stack.top()<=best[pointer])
        {
            putchar(Stack.top());
             Stack.pop();
        }
        else Stack.push(String[pointer++]);
    }
    cout<<endl;
    return 0;
}

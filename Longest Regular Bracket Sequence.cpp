/*Input
The first line of the input file contains a non-empty string, consisting of «(» and «)» characters. Its length does not exceed 106.

Output
Print the length of the longest substring that is a regular bracket sequence, and the number of such substrings. If there are no such substrings, write the only line 
containing "0 1".

Examples
input
)((())))(()())
output
6 2

input
))(
output
0 1

*/
#include <bits/stdc++.h>
#include<string>
#include<stack>
#include<climits>
using namespace std;
int Start[1000001],Extent[1000001],Frequency[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string String;
    int Maximum=0;
    stack<int> Stack;
    cin>>String;

    for(int i=0;i<String.size();i++){
      char ch=String[i];
      if(ch=='('){
        Stack.push(i);
      }
      else{
        if(Stack.empty()){
            Start[i]=Extent[i]= -1;
        }
        else{
            int index=Stack.top();
            Stack.pop();

            Start[i]=Extent[i]=index;

            if(index > 0 && String[index-1] == ')' && Start[index-1] >= 0)
                Extent[i]=Extent[index-1];

                int Length = i - Extent[i] + 1;
                Frequency[Length]++;
                Maximum=max(Maximum , Length);
        }
      }
    }
    Frequency[0]=1;
    cout<<Maximum<<" "<<Frequency[Maximum];
}

/*The single line of the input contains a sequence of characters "+" and "-" of length n (1 ≤ n ≤ 100000). The i-th (1 ≤ i ≤ n) position of the sequence contains the character
"+", if on the i-th step from the wall the "plus" wire runs above the "minus" wire, and the character "-" otherwise.

Output
Print either "Yes" (without the quotes) if the wires can be untangled or "No" (without the quotes) if the wires cannot be untangled.

Examples
input
-++-
output
Yes

input
+-
output
No

input
++
output
Yes

input
-
output
No
*/

#include <iostream>
#include<stack>
#include<cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char String[100010];
    cin>>String;
    stack<char> Stack;
    int i=0;
    while(String[i]!='\0'){
        if(Stack.empty()){
            Stack.push(String[i]);
        }
        else{
            if(Stack.top()==String[i])
                Stack.pop();
            else
                Stack.push(String[i]);
        }
        i++;
    }
    puts(Stack.empty()?"Yes":"No");
    return 0;
}

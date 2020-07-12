/*Input
The first line contains integer n (1 < n ≤ 105). The second line contains n distinct integers s 1, s 2, ..., s n (1 ≤ s i ≤ 109).

Output
Print a single integer — the maximum lucky number among all lucky numbers of sequences s[l..r].

Examples
input
5
5 2 1 4 3
output
7

input
5
9 8 3 5 7
output
15

Note:
For the first sample you can choose s[4..5] = {4, 3} and its lucky number is (4 xor 3) = 7. You can also choose s[1..2].

For the second sample you must choose s[2..5] = {8, 3, 5, 7}.
*/


#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll Array[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll Size;
    cin>>Size;
    for(ll i=0;i<Size;i++){
        cin>>Array[i];
    }
    stack<ll> Stack;
    ll Answer=0;
    for(ll i=0;i<Size;i++){
        while(!Stack.empty()){
            if(Stack.top()<Array[i]){
                Answer=max(Answer,Stack.top()^Array[i]);
                Stack.pop();
            }
            else{
                Answer=max(Answer,Stack.top()^Array[i]);
                break;
            }
        }
        Stack.push(Array[i]);
    }
    cout<<Answer<<endl;

    return 0;
}

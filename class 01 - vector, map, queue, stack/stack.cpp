#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)1e6 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
//#define int ll


using namespace std;



/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/


/// to declare stack: stack < data type > name;
/// to insert an element: name.push(element);
/// to access the top element: name.top();
/// to erase the top element: name.pop();
/// to check if the stack is empty : name.empty() /// if name.empty() == 1 then it is empty

int main()
{


    /// stack;
    stack < int > stc;
    stc.push(5);
    stc.push(6);
    stc.push(5);
    stc.push(5);
    stc.push(4);
    int a = stc.top();
    cout<<a<<endl;
    stc.pop();
    return 0;
}

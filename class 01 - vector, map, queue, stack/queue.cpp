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

/// to declare queue: queue < data type > name;
/// to insert an element: name.push(element);
/// to access the front element: name.front();
/// to erase the front element: name.pop();
/// to check if the queue is empty : name.empty() /// if name.empty() == 1 then it is empty


int main()
{

    /// queue
    int q;
    queue < int > que;
    cin>>q;
    while(q--){
        int typ;
        if(typ == 1){
            int idx;
            cin>>idx;
            que.push(idx);
        }
        else{
            int a;
            if(que.empty() == 1) a = -1;
            else{
                a = que.front();
                que.pop();
            }
            cout<<a<<endl;
        }
    }

    return 0;
}

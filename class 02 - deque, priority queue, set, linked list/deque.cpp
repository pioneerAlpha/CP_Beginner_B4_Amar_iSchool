#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)2e5 + 5)
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

/// to declare: deque < data type > name;
/// to push in front: name.push_front(val);
/// to push in back: name.push_back(val);
/// to pop from back: name.pop_back();
/// to pop from front: name.pop_front();

int main()
{
    fastio;
    deque < int > deq;
    for(int i = 1 ; i<=10 ; i++) deq.push_back(i);
    for(int i = 11 ; i<=20 ; i++) deq.push_front(i);
    while(!deq.empty()){
        int a = deq.front();
        cout<<a<<endl;
        deq.pop_front();
    }

    while(!deq.empty()){
        int a = deq.back();
        cout<<a<<endl;
        deq.pop_back();
    }

    return 0;
}

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

/// to declare: priority_queue < data type > name;
/// to insert: name.push(val);
/// to access: name.top();
/// to erase: name.pop();

int main()
{
    fastio;
    int q;
    cin>>q;
    priority_queue < int > pqq;
    while(q--){
        int typ;
        cin>>typ;
        if(typ == 1){
            int val;
            cin>>val;
            pqq.push(-val);
        }
        else if(typ == 2){
            int ans;
            if(pqq.empty()) ans = -1;
            else{
                ans = -pqq.top();
                pqq.pop();
            }
            cout<<ans<<endl;
        }
        else{
            int ans;
            if(pqq.empty()) ans = -1;
            else{
                ans = -pqq.top();
            }
            cout<<ans<<endl;
        }
    } /// O ( q * log ( q ) )
    return 0;
}

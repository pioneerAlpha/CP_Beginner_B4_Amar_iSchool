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

/// to declare a map : map < data1 , data2 > name;


int main()
{
    int q;
    cin>>q;
    map < int , int > vis;
    while(q--){ /// O ( q )
        int type , ele;
        cin>>type>>ele;
        if(type == 1) vis[ele] = 1;
        else if(type == 2) vis[ele] = 0;
        else{
            cout<<vis[ele]<<" ";
            if(vis[ele] == 1) cout<<"YES\n";
            else cout<<"NO\n";
        }

        /// O (log ( q ))
    }

    /// O (q * log (q) )
    return 0;
}

#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)1e5 + 5)
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



int main()
{
    fastio;
    int x , ans = 0;
    cin>>x;
    for(int i = 0 ; i<=30 ; i++){
        if(( x & (1<<i) ) != 0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

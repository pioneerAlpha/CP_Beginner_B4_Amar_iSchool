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

int bit[1005];


int main()
{
    fastio;
    int n , m , k ;
    cin>>n >> m >> k;

    for(int i = 1 ; i<=m+1 ; i++) cin>>bit[i];
    int ans = 0;
    for(int i = 1 ; i<=m ; i++){ /// O ( m )
        int x = bit[m+1] , y = bit[i] , cnt = 0;
        for(int j = 0 ; j<n; j++){ /// O ( n )
            if( (x & (1<<j)) != (y & (1<<j)) ) cnt++;
        }
        if(cnt <= k) ans++;

//        int tmp = x^y;
//        if(__builtin_popcount(tmp) <= k) ans++;

    }
    /// O ( m * n )
    cout<<ans<<endl;

    return 0;
}

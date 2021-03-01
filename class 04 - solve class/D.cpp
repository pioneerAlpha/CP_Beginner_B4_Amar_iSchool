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

int arr[17];


int main()
{
    fastio;
    int n , L , R , x , ans = 0;
    cin>>n>>L>>R>>x; /// combination = 2^n
    for(int i = 0 ; i<n ; i++) cin>>arr[i];
    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int mnn = MAX , mxx = 0 , sum = 0;
        for(int i = 0 ; i < n ; i++){
            if((mask & (1<<i)) != 0){
                /// this problem is chosen for the contest
                sum += arr[i];
                mxx = max(mxx , arr[i]);
                mnn = min(mnn , arr[i]);
            }
        }
        if(sum >= L && sum <= R && mxx - mnn >= x) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

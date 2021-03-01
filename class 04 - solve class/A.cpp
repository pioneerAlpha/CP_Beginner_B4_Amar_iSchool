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

int arr[55];

bool cmp(int a , int b)
{
    if(a > b) return true;
    return false;
}

int main()
{
//    fastio;
    int n , k;
    cin>>n>>k;
//    cout<<n<<" "<<k<<endl;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    sort(arr + 1 , arr + n + 1 , cmp);
//    for(int i = 1 ; i <= n ; i++) cout<<arr[i]<<" ";
    int ans = 0;
    for(int i = 1 ; i<=n ; i++){
        if(arr[i] >= arr[k] && arr[i] > 0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

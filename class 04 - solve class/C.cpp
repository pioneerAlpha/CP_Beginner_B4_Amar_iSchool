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
    int n ;
    cin>>n; /// combination = 2^n
    for(int i = 0 ; i<n ; i++) cin>>arr[i];
    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            if((mask & (1<<i)) != 0){
                /// ccw
                sum += arr[i];
            }
            else{
                /// cw
                sum -= arr[i];
            }
        }
        if(sum % 360 == 0){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}

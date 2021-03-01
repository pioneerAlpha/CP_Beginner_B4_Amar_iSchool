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

ll fun(int a , int d , ll n)
{
    ll ans = n*( 2*a + (n-1)*d )/2;
    return ans;
}


int main()
{
    fastio;
    ll n;
    cin>>n;
    ll even , odd;
    if(n & 1){
        odd = n;
        even = n-1;
    }
    else{
        even = n;
        odd = n-1;
    }
    ll sumodd = 0 , sumeven = 0;
    sumodd = fun(-1,-2,(odd+1)/2); /// if ( n == 10^15 it will overflow )
    sumeven = fun(2,2,(even)/2);
    ll ans = sumodd + sumeven;

    /// here is another way:
    ans = n/2;
    if(n & 1) ans -= n;
    cout<<ans<<endl;
    /// I will discuss it in the next class
    return 0;
}

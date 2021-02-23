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
    while(1){
        int n , i;
        cin>>n>>i;
        int a = (1<<i) ; /// a = 2^i;

        /// set i'th bit on:
        int ans = n | a;
        cout<<"on "<<ans<<endl;

        /// checking the i'th bit:
        ans = n & a;
        if(ans != 0) ans = 1;
        cout<<"checking "<<ans<<endl;

        /// set i'th bit off:
        ans = n;
        if((n & a) != 0) ans = n^a;
        cout<<"off "<<ans<<endl;

        /// inverse i'th bit:
        ans = n^a;
        cout<<"inverse "<<ans<<endl;
    }
}

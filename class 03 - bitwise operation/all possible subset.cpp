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

int arr[25];

int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    /// 2 ^ n : 0 to (2 ^ n - 1)
    for(int mask = 0 ; mask < (1<<n) ; mask++){
        vector < int > sub;
        for(int i = 0 ; i < n ; i++){
            int a = 1<<i;
            if((mask & a) != 0) sub.push_back(arr[i]);
        }
        for(int a:sub) cout<<a<<" ";
        cout<<endl;
    }
}

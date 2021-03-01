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
int arr[505][505];


int main()
{
    fastio;
    int n , m , ans = 0;
    cin>>n>>m;
    vector < int > pos;
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++) cin>>arr[i][j];
        ans ^= arr[i][1];
        pos.push_back(1);
    }
    if(ans == 0){
        for(int i = 1 ; i<=n && ans == 0; i++){
            for(int j = 2 ; j<=m ; j++){
                if(arr[i][j] != arr[i][1]){
                    ans ^= arr[i][1]; /// removing arr[i][1]
                    ans ^= arr[i][j];
                    pos[i-1] = j;
                    break;
                }
            }
        }
    }
    if(ans == 0) cout<<"NIE\n";
    else{
        cout<<"TAK\n";
        for(int a:pos) cout<<a<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)2e5 + 5)
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



int lef[N] , rig[N];
int L[N] , R[N]; /// for chain

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++){
        int k , pre = -1;
        cin>>k;
        L[i] = -1;
        while(k--){
            int a;
            cin>>a;
            if(L[i] == -1) L[i] = a;
            if(pre != -1) rig[pre] = a;
            lef[a] = pre;
            pre = a;
        }
        rig[pre] = -1;
        R[i] = pre;
    }

    int q;
    cin>>q;
    while(q--){
        int typ;
        cin>>typ;
        if(typ == 1){ /// merge y to x;
            int x , y;
            cin>>x>>y;
            int pre = R[x] , post = L[y];
            rig[pre] = post;
            lef[post] = pre;
            R[x] = R[y];
        }
        else if(typ == 2){ /// break the chain
            int c , u , v , x;
            cin>>c>>u>>v>>x;
            rig[u] = -1;
            lef[v] = -1;
            L[x] = v;
            R[x] = R[c];
            R[c] = u;
        }
        else{
            /// query
        }
    }
    return 0;
}

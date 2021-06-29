//#include<cstdio>
//#include<cassert>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)2e9 + 5)
#define MAXP ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX_X ((int)2001)
#define MAX_Y ((int)2001)
#define pi acos(-1)
//#define MOD ((int)1e6 + 3)
#define MOD ((int)998244353 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define N ((int)1e2 + 9)
#define M ((int)1e3 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 17
#define endl "\n"
#define mpp make_pair
#define BUCK 105
#define LEF (idx<<1)
#define RIG ((idx<<1)|1)
//#define int ll
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/




typedef tree < int,  null_type,  less < int >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
typedef tree < pair < int, int >,  null_type,  less < pair < int, int > >,  rb_tree_tag,  tree_order_statistics_node_update > o_setp;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).

typedef long double ldd;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l,r) (rng);
}

int arr[N][N] , ans[N][N];

int dxx[] = {0,0,1,-1};
int dyy[] = {1,-1,0,0};

bool vis[N][N];

void add(priority_queue < pair < int , pair < int , int > > >& pqq , int r , int c)
{
    vis[r][c] = 1;
    pqq.push({-ans[r][c] , {r,c}});
}

int main()
{

    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        memset(vis,0,sizeof vis);
        for(int i = 0 ; i<=m+1 ; i++) vis[0][i] = vis[n+1][i] = 1;
        for(int i = 0 ; i<=n+1 ; i++) vis[i][0] = vis[i][m+1] = 1;
        for(int i = 1 ; i<=n ; i++) for(int j = 1 ; j<=m ; j++) cin>>arr[i][j];
        priority_queue < pair < int , pair < int , int > > > pqq;
        for(int i = 1 ; i <= n ; i++){
            if(!vis[i][1]){
                ans[i][1] = arr[i][1];
                add(pqq,i,1);
            }
            if(!vis[i][m]){
                ans[i][m] = arr[i][m];
                add(pqq,i,m);
            }
        }
        for(int i = 1 ; i<=m ; i++){
            if(!vis[1][i]){
                ans[1][i] = arr[1][i];
                add(pqq,1,i);
            }
            if(!vis[n][i]){
                ans[n][i] = arr[n][i];
                add(pqq,n,i);
            }
        }
//        cout<<"sda\n";
        while(!pqq.empty()){
            int row = pqq.top().second.first , col = pqq.top().second.second;
            pqq.pop();
            for(int i = 0 ; i<4 ; i++){
                int r = row + dxx[i] , c = col + dyy[i];
                if(!vis[r][c]){
                    ans[r][c] = max(arr[r][c] , ans[row][col]);
                    add(pqq,r,c);
                }
            }
        }
        int sum = 0 ;
        for(int i = 1 ; i<=n ; i++) for(int j = 1 ; j<=m ; j++) sum += ans[i][j] - arr[i][j];

        cout<<sum<<endl;

    }
    return 0;
}

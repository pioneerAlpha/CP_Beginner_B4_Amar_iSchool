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
#define MOD ((int)1e9 + 7)
//#define MOD ((int)998244353 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define N ((int)1e3 + 9)
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

vector < int > vec[N]; /// vec[i] = stores the nodes 'U' such that there is an edge
/// from 'i' to 'U';

int nxt[N];

bool vis[N];

bool dfs2(int n , int des, bool follow)
{
    if(n == des){
        if(follow == 1) return 0;
        else return 1;
    }

    vis[n] = 1;
    for(int a:vec[n]){
        if(vis[a] == 0 && a != nxt[n]){
            if(dfs2(a,des,0) == 1) return 1;
        }
    }
    if(vis[nxt[n]] == 0){
        if(dfs2(nxt[n] , des , follow)) return 1;
        else return 0;
    }
    else return 0;
}

bool dfs(int n , int des)
{
    if(n == des) return 1;
    vis[n] = 1;
    for(int a:vec[n]){
        if(vis[a] == 0){
            if(dfs(a , des) == 1){
                nxt[n] = a;
                return 1;
            }
        }
    }
    return 0;
}


int main()
{
    /// porblem link: https://csacademy.com/contest/archive/task/simple-paths/statement/
    fastio;
    int n , m , q;
    cin>>n>>m>>q;
    for(int i = 1 ; i<=m ; i++){
        int u , v ;
        cin>>u>>v;
//        from[i] = u , too[i] = v , cost[i] = c;
        vec[u].push_back(v); /// u -> v
        vec[v].push_back(u); /// v -> u;
    }
    while(q--){
        int x , y;
        cin>>x>>y;
        memset(nxt,-1,sizeof nxt);
        memset(vis,0,sizeof vis);
        if(dfs(x , y) == 1){
            memset(vis,0,sizeof vis);
            if(dfs2(x,y,1) == 1) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}

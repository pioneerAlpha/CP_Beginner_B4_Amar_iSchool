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
#define N ((int)1e5 + 9)
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

vector < int > vec[N];

void add(int u , int v)
{
    vec[u].push_back(v);
}

vector < pair < int , int > > ans;

bool vis[N] , cnt[N];

int dep[N] , par[N] , chl[N];

void dfs(int n,int L)
{
    dep[n] = L;
    vis[n] = 1;
    for(int a:vec[n]){
        if(vis[a] && dep[a] > dep[n]){
            cnt[a] = !cnt[a];
            ans.push_back({a,n});
        }
        else if(!vis[a]){
            par[a] = n;
            chl[n]++;
            dfs(a,L+1);
        }
    }
}

int main()
{
    int n , m;
    cin>>n>>m;
    if(m & 1){
        cout<<"-1\n";
        return 0;
    }
    while(m--){
        int u , v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    queue < int > leaf;
    for(int i = 1 ; i<=n ; i++){
        if(chl[i] == 0) leaf.push(i);
    }
    while(!leaf.empty()){
        int a = leaf.front();
        leaf.pop();
        int p = par[a];
        if(cnt[a]){
            cnt[a] = !cnt[a];
            ans.push_back({a,p});
        }
        else if(p > 0){
            ans.push_back({p,a});
            cnt[p] = !cnt[p];
        }

        chl[p]--;
        if(chl[p] == 0) leaf.push(p);
    }
    for(auto p:ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}

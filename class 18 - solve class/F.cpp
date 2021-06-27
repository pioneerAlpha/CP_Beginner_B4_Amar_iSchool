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

string str[25] , aux[25] , cur , dir;

int dxx[] = {0,0,1,-1};
int dyy[] = {1,-1,0,0};

bool vis[25][25];

int n , m;

void prnt(string str[])
{
    for(int i = 0 ; i<=n+1 ; i++) cout<<str[i]<<endl;
    cout<<endl;
}

void mov()
{
    for(int i = 0 ; i<cur.size() ; i++){
        for(int j = 0 ; j<4 ; j++){
            if(dir[j] == cur[i]){
//                cout<<j<<endl;
                for(int r = 0 ; r <= n+1 ; r++) aux[r] = str[r];
                for(int r = 1 ; r <= n ; r++){
                    for(int c = 1 ; c <= m ; c++) if(aux[r][c] == '1') aux[r][c] = '2';
                }
//                prnt(str);
                for(int r = 1 ; r <= n ; r++){
                    for(int c = 1 ; c <= m ; c++){
                        if(str[r][c] == '1'){
                            int x = r + dxx[j] , y = c + dyy[j];
                            if(str[x][y] != '0') aux[x][y] = '1';
                            else aux[r][c] = '1';
                        }
                    }
                }

                for(int r = 1 ; r <= n ; r++) str[r] = aux[r];
//                prnt(str);
            }
        }
    }
}

bool dfs(int r , int c , int tr , int tc)
{
    if(r == tr && c == tc) return 1;
    if(vis[r][c] || str[r][c] == '0') return 0;
    vis[r][c] = 1;
    for(int i = 0 ; i<4 ; i++){
        if(dfs(r + dxx[i] , c + dyy[i] , tr , tc)){
            cur += dir[i];
            return 1;
        }
    }
    return 0;
}

int main()
{
    dir = "RLDU";
    string ans;
    cin>>n>>m;
    for(int i = 1 ; i<=n ; i++){
        cin>>str[i];
        str[i] = "0" + str[i] + "0";
    }
    for(int i = 1 ; i<=m+2 ; i++) str[0] += "0";
    str[n+1] = str[0];
    while(1){
        bool flag = 1;
        for(int i = 1 ; i <= n && flag ; i++){
            for(int j = 1 ; j<=m ; j++)
            {
                if(str[i][j] == '1')
                {
                    str[i][j] = '2';
                    for(int r = 1 ; r <= n && flag ; r++)
                    {
                        for(int c = 1 ; c <= m ; c++)
                        {
                            if(str[r][c] == '1')
                            {
                                flag = 0;
                                str[i][j] = '1';
                                cur = "";
                                memset(vis,0,sizeof vis);
                                dfs(i,j,r,c);
                                reverse(cur.begin() , cur.end());
                                ans += cur;
//                                cout<<cur<<endl;
                                mov();
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
        if(flag) break;
    }
    cout<<ans<<endl;
    return 0;
}

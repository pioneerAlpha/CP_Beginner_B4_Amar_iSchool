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
#define N ((int)1e5 + 9)
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

int sqr(int n) /// returns int x such that x*x <= n
{
    int L = 0 , R = n;
    while(L < R){
        int mid = (L+R+1)>>1;
        if(1LL*mid*mid <= n) L = mid;
        else R = mid-1;
    }
    return L;
}

int main()
{
    fastio;
    cout<<fixed<<setprecision(15);
    int t ,caseno = 1;

    t = 1;
    while(t--){
        int n;
        cin>>n;
        vector < int > arr;
        int cnt = 0 , zero = 0 ;
        ll ans = 0;
        for(int i = 0 ; i<n ;i++){
            int a;
            cin>>a;
            int b = sqr(a);
            if(b*b == a){
                cnt++;
                if(a == 0) zero++;
            }
            else{
                int val = a - b*b;
                b++;
                val = min(val , b*b - a);
                arr.push_back(val);
            }
        }

        if(cnt < n/2){
            sort(arr.begin() , arr.end());
            for(int a:arr){
                cnt++;
                ans += a;
                if(cnt == n/2) break;
            }
        }
        else if(cnt > n/2){
            int rem = cnt - zero;
            while(cnt > n/2 && rem > 0){
                ans++;
                rem--;
                cnt--;
            }
            while(cnt > n/2){
                cnt--;
                ans += 2;
            }
        }

        cout<<ans<<endl;

//        cout<<"Case "<<caseno++<<": "<<L<<endl;
    }
    return 0;
}

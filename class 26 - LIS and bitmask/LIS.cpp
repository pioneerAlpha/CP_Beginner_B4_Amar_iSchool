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
#define MAXL ((LL)1e18 + 5)
#define MAX_X ((int)2001)
#define MAX_Y ((int)2001)
#define pi acos(-1)
//#define MOD ((int)1e9 + 7)
//#define MOD ((int)998244353 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define N ((int)1e6 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
//#define logn 17
#define endl "\n"
#define mpp make_pair
#define BUCK 105
#define LEF (idx<<1)
#define RIG ((idx<<1)|1)
//#define int LL


using namespace std;
using namespace __gnu_pbds;

typedef long long LL;
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


int BinarySearch(vector < int >& arr, int value){
    int L = 0 , R = arr.size()-1;
    while(L<R){
        int mid = (L+R+1)>>1;
        if(arr[mid] <= value) L = mid;
        else R = mid-1;
    }
    return L;
}

int main()
{
    int n;
    cin>>n;
    vector < int > arr(n+1) , aux(n+1) , dpp(n+1);
    for(int i = 1 ; i <= n ; i++) cin>>arr[i];
    for(int i = 1 ; i <= n ; i++) aux[i] = MAX;
    aux[0] = -MAX;
    for(int i = 1 ; i <= n ; i++){
        dpp[i] = BinarySearch(aux , arr[i]) + 1;
        if(aux[dpp[i]] > arr[i]) aux[dpp[i]] = arr[i];
    }
    int LIS = 0 , last = MAX;
    for(int i = 1 ;i <= n ; i++) LIS = max(LIS , dpp[i]);
    cout<<LIS<<endl;
    vector < int > seq(LIS+1);
    for(int i = n ; i > 0 ; i--){
        if(dpp[i] == LIS && arr[i] <= last){
            seq[LIS] = arr[i];
            LIS--;
            last = arr[i];
        }
    }
    for(int i = 1 ; i<seq.size() ; i++) cout<<seq[i]<<" ";
    return 0;
}

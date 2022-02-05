#include<bits/stdc++.h>
#define LL long long
#define N ((int)1e5 + 8)
#define MAX ((int)1e9 + 8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define Type pair < int , int >

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // generator


int GetRandomNumber(int a , int b)
{
    return uniform_int_distribution<int>(a, b)(rng); //rand([a,b])
}


int Solve(int mask) /// minimum damage to distroy all balcony in mask
{
    if(mask == 0) return 0;
    if(dpp[mask] != -1) return dpp[mask];
    int ans = MAX, sum = 0;

    for(int i = 0 ; i < n ; i++){
        if(mask & (1<<i)) sum += arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        if((mask & (1<<i)) == 0) continue;
        int newMask = mask, dam = sum;
        for(int j = 0 ; j < 3 ; j++){
            int idx = i+j;
            if(idx >= n) idx -= n;
            if(newMask & (1<<idx)){
                newMask ^= 1<<idx;
                dam -= arr[idx];
            }
        }
//        int dam = 0;
//        for(int j = 0 ; j < n ; j++){
//            if(newMask & (1<<j)) dam += arr[j];
//        }
        ans = min(ans , Solve(newMask) + dam);
    }
    return dpp[mask] = ans;
} /// O(2^n * n * n) -> O(2^n * n)

int main()
{
    cout<<Solve((1<<n) - 1);
}



int Solve(int pre , int cur , int mask)
{
    if(mask == 0) return 0;
    if(dpp[pre][mask] != -1) return dpp[pre][mask];
    int ans = MAX;
    for(int i = 0 ; i < n ; i++){
        if(mask & (1<<i)){
            if(cur > 0) ans = min(ans , abs(A[i] - A[pre])*C[cur] + Solve(i , cur + 1 , mask ^ (1<<i)));
            else ans = min(ans , Solve(i , cur + 1 , mask ^ (1<<i)));
        }
    }
    return dpp[pre][mask] = ans;
} /// O(2^n * n * n)


void LIS(int n, vector < int >& arr, vector < int >& dpp)
{
    /// dpp[i] = length of the LIS whose last element is arr[i];

    for(int i = 1; i <= n ; i++){
        int ans = 1;
        for(int j = 1 ; j < i ; j++){
            if(arr[j] <= arr[i]) ans = max(ans , dpp[j] + 1);
        }
        dpp[i] = ans;
    }



    for(int i = 1; i <= n ; i++){
        int ans = 1;
        for(int j = 1 ; j < i ; j++){
            if(abs(arr[j]) < abs(arr[i]) && 1LL*arr[j]*arr[i] < 0) ans = max(ans , dpp[j] + 1);
        }
        dpp[i] = ans;
    }

    int ans = 0;
    for(int i = 1; i <= n ; i++) ans = max(ans , dpp[i]);

    cout<<ans<<endl;


    /// searching common element:
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        ans = max(ans , inc[i] + dec[i] - 1);
    }

    cout<<ans<<endl;

}

int GetMaxDamage(int i , int mask)
{
    if(dam[i][mask] != -1) return dam[i][mask];
    int damage = 0;
    for(int j = 0 ; j < n ; j++){
        if((mask & (1<<j)) == 0){
            damage = max(damage , arr[j][i] - '0');
        }
    }
    return dam[i][mask] = damage;
}///O( n  * 2^n )

int Solve(int mask)
{
    if(mask == 0) return 0;
    int ans = MAX;
    for(int i = 0 ; i < n ; i++){
        if(mask & (1<<i)){
            int damage = 1;
            damage = max(damage , GetMaxDamage(i,mask));
            int shot = (health[i] + damage - 1) / damage;
            ans = min(ans , shot + Solve(mask ^ (1<<i)));
        }
    }

    return dpp[mask] = ans;
}
/// O(2^n * n)





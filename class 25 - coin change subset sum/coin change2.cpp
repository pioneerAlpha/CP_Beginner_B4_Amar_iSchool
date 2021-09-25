int solve3(int idx, int value)   /// sub variation 3
{
    if(value < 0) return 0; /// remember to handle
    if(idx > n)
    {
        if(value == 0) return 1;
        else return 0;
    }
    int ans = solve(idx+1, value) + solve(idx, value - arr[idx]) ;
    /// mod:
}

int main(){
    /// base case:
    for(int value = 1 ; value <= k ; value++) dpp[n+1][value] = 0;
    dpp[n+1][0] = 1;

    for(int idx = n ; idx > 0 ; idx--){
        for(int value = 0 ; value <= k ; value++){
            int ans = dpp[idx+1][value];
            if(value - arr[idx] >= 0){
                ans += dpp[idx][value - arr[idx]] ;
                if(ans >= MOD) ans -= MOD;
            }
            dpp[idx][value] = ans;
        }
    }
}

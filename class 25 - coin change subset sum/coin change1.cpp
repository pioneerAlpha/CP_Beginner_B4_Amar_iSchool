int solve(int idx, int value)
{
    if(value < 0) return 0;
    if(idx > n)
    {
        if(value == 0) return 1;
        else return 0;
    }
    int ans = 0;
    for(int i = 0 ; i <= cnt[idx] ; cnt++)
    {
        if(val - 1LL*i*arr[idx] < 0) break;
        ans += solve(idx + 1, value - 1LL*arr[idx]*i);
        if(ans >= MOD) ans -= MOD;
    }

} /// O(n*value):state
/// time:O(n*value*max(cnt[i]))

int main(){
    /// base case:
    for(int value = 1 ; value <= k ; value++) dpp[n+1][value] = 0;
    dpp[n+1][0] = 1; 

    for(int idx = n ; idx > 0 ; idx--)
    {
        for(int value = 0 ; value <= k ; value++)
        {
            int ans = 0;
            for(int i = 0 ; i <= cnt[idx] ; cnt++)
            {
                if(val - 1LL*i*arr[idx] < 0) break;
                ans += dpp[idx + 1][value - 1LL*arr[idx]*i];
                if(ans >= MOD) ans -= MOD;
            }
            dpp[idx][value] = ans;
        }
    }

    cout<<dpp[1][value]<<endl;
}

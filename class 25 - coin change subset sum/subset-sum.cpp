bool solve(int idx , int sumA)
{
    if(sumA < 0) return 0;
    if(idx > n){
        if(sumA == 0) return 1;
        else return 0;
    }
    bool ans = solve(idx + 1 , sumA) | solve(idx + 1 , sumA - arr[idx]);
    return dpp[idx][sumA] = ans;
}

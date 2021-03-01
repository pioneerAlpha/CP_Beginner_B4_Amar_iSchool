#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)1e5 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
//#define int ll


using namespace std;



/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

void NOO()
{
    cout<<"NO\n";
    exit(0);
}


int main()
{
    fastio;
    int n , k;
    cin>>n>>k;
    priority_queue < int > pqq;
    for(int i = 0 ; i<=30 ; i++){
        if((n & (1<<i)) != 0){ /// 5 = 2^0 + 2^2 = 101
            pqq.push(1<<i);
        }
    }
    if(pqq.size() > k) NOO();
    while(pqq.size() < k){
        int a = pqq.top();
        pqq.pop();
        if(a > 1) /// 1 = 2^0
        {
            a /= 2;
            pqq.push(a);
            pqq.push(a);
        }
        else break;
    }

    if(pqq.size() == k){
        cout<<"YES\n";
        while(!pqq.empty()){
            int a = pqq.top();
            pqq.pop();
            cout<<a<<" ";
        }
    }
    else NOO();
    return 0;
}

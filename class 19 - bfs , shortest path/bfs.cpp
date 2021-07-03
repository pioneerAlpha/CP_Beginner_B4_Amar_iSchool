#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define N ((int)1e5 + 9)
#define endl "\n"
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)1e9 + 5)
#define MAXP ((int)1e2 + 5)
//#define MOD ((int)1e9 + 7)
#define MOD ((int)998244353 + 0)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

vector < int > edg[N];

void bfs(int src , int dis[] , int n)
{
    for(int i = 1 ; i<=n ; i++) dis[i] = -1;
    dis[src] = 0;
    queue < int > que;
    que.push(src);
    while(!que.empty()){
        int a = que.front();
        que.pop();
        for(int node:edg[a]){
            if(dis[node] == -1){
                que.push(node);
                dis[node] = dis[a] + 1;
            }
        }
    }
} /// O (n + m)



void add(int u , int v)
{
    edg[u].push_back(v);
}

int main()
{
    int n , m;
    cin>>n>>m;
    while(m--){
        int u , v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
}

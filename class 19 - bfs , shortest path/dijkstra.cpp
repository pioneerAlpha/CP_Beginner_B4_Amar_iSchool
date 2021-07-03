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


int dis[N] , vis[N];

vector < pair < int , int > > edg[N]; /// first = node , second = weight;

void dijkstra(int src , int dis[] , int vis[] , int n)
{
    for(int i = 1 ; i<= n ; i++) dis[i] = MAX , vis[i] = 0;
    dis[src] = 0;
    priority_queue < pair < int , int > > pqq;
    pqq.push({0,src});
    while(!pqq.empty()){
        int cur = pqq.top().second;
        pqq.pop();
//        if(vis[cur]) continue;
//        vis[cur] = 1;
        for(auto p:edg[cur]){
            int a = p.first , w = p.second;
            if(dis[a] > dis[cur] + w){
                dis[a] = dis[cur] + w;
                pqq.push({-dis[a] , a});
            }
        }
    }
} /// O ( m*m*log + n*n*log )

void add(int u , int v , int w)
{
    edg[u].push_back({v,w});
}

int main()
{
    int n , m;
    cin>>n>>m;
    while(m--){
        int u , v , w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra(1,dis,vis,n);
}

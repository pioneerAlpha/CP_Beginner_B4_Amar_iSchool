#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

//int dis[2005][2005];
//
//
//int dxx[] = {1,0,0,-1};
//int dyy[] = {0,-1,1,0};
//
//
//void bfs(vector < pair < int , int > > src , int n , int m)
//{
//    memset(dis,-1,sizeof dis);
//    queue < pair < int , int > > que;
//    for(auto p:src){
//        dis[p.first][p.second] = 0;
//        que.push({p.first,p.second});
//    }
//
//
//    while(!que.empty())
//    {
//        pair < int , int > p = que.front();
//        int row = p.first , col = p.second;
//        que.pop();
//        for(int i = 0 ; i<4 ; i++)
//        {
//            int x = row + dxx[i] , y = col + dyy[i];
//            if(min(x,y) > 0 && x <= n && y <= m && dis[x][y] == -1)
//            {
//                dis[x][y] = dis[row][col] + 1;
//                que.push({x,y});
//            }
//        }
//    }
//}

int main()
{
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n , m , k ;
    cin>>n>>m>>k;

    vector < pair < int , int > > src;
    while(k--){
        int x , y;
        cin>>x>>y;
        src.push_back({x,y});
    }

//    bfs(src,n,m);
    int ans = 0;
    pair < int , int > pos;
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            int dis = n+m+5;
            for(auto p:src){
                dis = min(dis , abs(i-p.first) + abs(j-p.second));
            }
            if(ans <= dis){
                ans = dis;
                pos = {i,j};
            }
        }
    }
    cout<<pos.first<<" "<<pos.second<<endl;
    return 0;
}

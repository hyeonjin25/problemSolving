#include <bits/stdc++.h>

using namespace std;

int vis[305][305];
int dx[8]={2,1,-2,1,2,-1,-2,-1};
int dy[8]={1,2,1,-2,-1,2,-1,-2};

queue<pair<int,int>> Q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
   int T;
   cin >> T;
   
   while(T--){
    int l;
    int nowX,nowY,goX,goY;
    
    fill(&vis[0][0],&vis[304][305],-1);
    
    cin >> l;
    cin >> nowX >> nowY >> goX >> goY;
    
    vis[nowX][nowY]=0;

    Q.push({nowX,nowY});
    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        
        for(int i=0; i<8;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx<0||ny<0||nx>=l||ny>=l) continue;
            if(vis[nx][ny]!=-1) continue;

            Q.push({nx,ny});
            vis[nx][ny]=vis[cur.first][cur.second]+1;
        }
    }
    
     cout << vis[goX][goY]<<'\n';
   }
    
}

#include <bits/stdc++.h>

using namespace std;

int mat[1005][1005];
int vis[1005][1005];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

queue<pair<int,int>>Q;

int main()
{
    int n,m;
    cin >> n>>m;
    
    for(int i =0; i<n;i++) fill(vis[i],vis[i]+1005,-1);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
            if(mat[i][j]==2){
                Q.push({i,j});
                vis[i][j]=0;
            }
        }
    }

    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        for(int k=0; k<4; k++){
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(vis[nx][ny]>-1||mat[nx][ny]==0) continue;
            
            Q.push({nx,ny});
            vis[nx][ny]=vis[cur.first][cur.second]+1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0) cout << 0 << ' ';
            else cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
}
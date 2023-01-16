#include <bits/stdc++.h>

using namespace std;

int vis1[1005][1005]; // 불
int vis2[1005][1005]; // 상근이
char paper[1005][1005];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

queue<pair<int,int>> Q1; // 불
queue<pair<int,int>> Q2; // 상근이

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
   int T;
   cin >> T;
   
   while(T--){
    while (Q1.size()) Q1.pop();
    while (Q2.size()) Q2.pop();
    int w,h;
    
    fill(&vis1[0][0],&vis1[1004][1005],-1);
    fill(&vis2[0][0],&vis2[1004][1005],-1);
    
    cin >> w>> h;
    
    char temp;
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++){
            cin >>temp;
            paper[i][j] = temp;
            if(temp=='*') {
                Q1.push({i,j});
                vis1[i][j]=0;
            }
            if(temp=='@') {
                Q2.push({i,j});
                vis2[i][j]=0;
            }
        }
    
    // 불 이동
    while(Q1.size()){
        auto cur = Q1.front(); Q1.pop();
        
        for(int i=0; i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            
            if(nx<0||ny<0||nx>=h||ny>=w) continue;
            if(vis1[nx][ny]!=-1 || paper[nx][ny]=='#') continue;

            Q1.push({nx,ny});
            vis1[nx][ny]=vis1[cur.first][cur.second]+1;
        }
    }

    
    // 상근이 이동
    while(Q2.size()){
        auto cur = Q2.front(); Q2.pop();
        
        for(int i=0; i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            
            if(nx<0||ny<0||nx>=h||ny>=w) {
                cout << vis2[cur.first][cur.second]+1 <<'\n';
                goto g;
            }
            if(vis2[nx][ny]!=-1||paper[nx][ny]!='.') continue;
            if(vis2[cur.first][cur.second]+1>=vis1[nx][ny] && vis1[nx][ny]!=-1)continue;

            Q2.push({nx,ny});
            vis2[nx][ny]=vis2[cur.first][cur.second]+1;
        }
    }
    
    cout << "IMPOSSIBLE"<<'\n';
    g: continue;
   }
    
}
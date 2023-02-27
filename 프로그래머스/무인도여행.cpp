#include <bits/stdc++.h>

using namespace std;

queue<pair<int,int>> Q;
int vis[105][105];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n=maps.size();
    int m=maps[0].size();
     
    for(int i=0;  i<n; i++){
        for(int j=0; j<m; j++){
            if(maps[i][j]=='X'||vis[i][j]==1) continue;
            Q.push({i,j});
            vis[i][j]=1;
            int cnt=maps[i][j]-'0';
            
            while(Q.size()){
                auto cur = Q.front(); Q.pop();
                for(int k=0; k<4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
                    if(vis[nx][ny]==1||maps[nx][ny]=='X') continue;
                    Q.push({nx,ny});
                    vis[nx][ny]=1;
                    cnt+=maps[nx][ny]-'0';
                }
            }
            answer.push_back(cnt);
        }
    }
    
    if(answer.size()==0) answer.push_back(-1);
    
    sort(answer.begin(), answer.end());
    return answer;
}
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> vis(55, vector<int>(55, 0));
vector<vector<int>> vis2(55, vector<int>(55, 0));

vector<int> bfs(int a,int b, int n, vector<vector<int>>& vis, vector<vector<int>> bd,bool game){
    queue <pair<int,int>> Q;

    Q.push({a,b});
    vis[a][b]=1;
    
    int u=a,d=a,l=b,r=b;
    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            if(vis[nx][ny]==1) continue;
            if(bd[nx][ny]==(game?1:0)) continue;
            Q.push({nx,ny});
            vis[nx][ny]=1;
            d = max(nx,d);
            l = min(ny,l);
            r = max(ny,r);
        }   
    }
    return {u,l,d-u+1, r-l+1}; // 시작x, 시작y, 세로, 가로 크기 리턴
}

vector<vector<int>> turn(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> t(m,vector<int>(n));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            t[j][n-1-i]=v[i][j];
        }
    }

    return t;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    vector<vector<vector<int>>> boards;
    vector<int> num;
    int n = game_board.size();
    
    // board 탐색
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           if(game_board[i][j]==1||vis[i][j]==1) continue;
           auto s = bfs(i,j,n,vis,game_board,1);
           vector<vector<int>> v(s[2]);
           // 해당 위치의 board 저장
           int n=0;
           for(int h=0; h<s[2]; h++){
               for(int g=0; g<s[3];g++){
                   v[h].push_back(!game_board[s[0]+h][s[1]+g]);
                   n+=!game_board[s[0]+h][s[1]+g];
               }
           }
           boards.push_back(v);
           num.push_back(n);
       }
   }
    
    vector<int>used(2600,0);
    // table 탐색
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           if(table[i][j]==0||vis2[i][j]==1) continue;
           auto s = bfs(i,j,n,vis2,table,0);
           vector<vector<int>> v(s[2]);
           // 해당 위치의 board 얻기
           for(int h=0; h<s[2]; h++){
               for(int g=0; g<s[3];g++){
                   v[h].push_back(table[s[0]+h][s[1]+g]);
               }
           }
    
           // v를 넣을 칸이 있는지 확인
           for(int h=0; h<boards.size(); h++){
               if(used[h]) continue;
               vector<vector<int>> temp = boards[h];
               for(int i=0; i<4; i++){
                   if(temp==v){
                       used[h]=1;
                       answer+=num[h];
                       
                       goto g;
                   }
                   // 90도 돌리기
                   temp = turn(temp);
               }
           }
           g: continue;
       }
   }
    return answer;
}
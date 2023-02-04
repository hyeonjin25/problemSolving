#include <bits/stdc++.h>

using namespace std;

int n, m;
int mat[10][10];
int dir[10]; // 각 cctv의 방향 저장 0-위, 1-오른쪽, 2-아래, 3-왼쪽
int tv[10]; // 각 cctv의 종류 저장
int res = 1e9; // 가장 많이 감시할 수 있는 경우의 영역 수
vector<pair<int, int>> cam; // cctv의 위치 저장

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

vector<vector<int>> cv={{1},{1,3},{0,1},{3,0,1},{0,1,2,3}};


void func(int k){
  if((int)cam.size()<=k){
    for(int i=0; i<(int)cam.size(); i++){
        vector<int> f = cv[tv[i]];

        for(int j=0;j<(int)f.size();j++)
        {
          int d = f[j]+dir[i];
          d = d%4;
          int x = cam[i].first;
          int y = cam[i].second;
          while(1){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx<0||nx>=n||ny<0||ny>=m) break;
            if(mat[nx][ny]==6) break;

            if(mat[nx][ny]==0)
            { 
              mat[nx][ny]=-1;
            }
            x=nx;
            y=ny;
          }
        }
    
    }

    int number=0; // 감시할 수 있는 영역 수 저장
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        if(mat[i][j]==0) number++;
        else if(mat[i][j]==-1) mat[i][j]=0;
      }
    }

    res = min(number,res);
    return;
  }

  for(int i=0;i<4;i++){
    dir[k]=i;
    func(k+1);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
      if (mat[i][j] != 0 && mat[i][j] < 6)
        { 
          cam.push_back({i, j});
          tv[(int)cam.size()-1] = mat[i][j]-1;
        }
    }

  func(0);
  
  cout << res;
}
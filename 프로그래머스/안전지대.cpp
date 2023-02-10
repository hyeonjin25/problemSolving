#include <bits/stdc++.h>
#include <vector>

using namespace std;

int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};

int mat[105][105];

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board.size(); j++){
            if(board[i][j]==1){
                mat[i][j]=1;
                for(int k=0; k<9; k++){
                    int nx=i+dx[k]; int ny=j+dy[k];
                    if(nx<0||nx>=board.size()||ny<0||ny>=board.size()) continue;
                    mat[nx][ny]=1;
                }
            }
        }
    }
    
     for(int i=0; i<board.size(); i++)
         for(int j=0; j<board.size(); j++)
             if(mat[i][j]==0) answer++;
        
    return answer;
}

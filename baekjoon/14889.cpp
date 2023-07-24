#include <bits/stdc++.h>

using namespace std;

int mat[25][25];
int per[25];
int per2[25];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
   int n;
   cin >> n;

   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin >> mat[i][j];   
    
    for(int i=0;i<n;i++){
        if(i<(n/2)) per[i]=0;
        else per[i]=1;
    }
    
    // 2개 조합용
    for(int i=0;i<n/2;i++){
        if(i<2) per2[i]=0;
        else per2[i]=1;
    }

    int k=0;
    int res=1e9;
    do{
        vector<int> t1;
        vector<int> t2;
        // 1,2,3이 a팀이면 4,5,6은 b팀임을 알 수 있으므로 나누기 2
        for(int i=0;i<n;i++){
          if(per[i]==0) t1.push_back(i);
          else t2.push_back(i);
        }
        int sum1=0; int sum2=0;
        for(int i=0;i<t1.size();i++){
          for(int j=0;j<t1.size();j++){
            sum1+=mat[t1[i]][t1[j]];
            sum2+=mat[t2[i]][t2[j]];
          }
        }
        res=min(res,abs(sum1-sum2));

        k++;
    }while(next_permutation(per, per+n)); // 팀을 반으로 나누는 경우의 수
  
    
    cout << res;
}
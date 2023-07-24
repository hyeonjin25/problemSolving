#include <bits/stdc++.h>
#include <vector>

using namespace std;
int per[25];
int fall[25];
// int po[100000005];
map<int,int> mp;

int solution(vector<int> position, vector<int> height, int m) {
    int answer = 1e9;
    int n = position.size();

    // 해당 위치에 몇번 블록이 있는지 저장
    for(int i=0; i<n; i++){
        mp[position[i]]=i;
    }

    // n-m개의 블록 뽑기 위한 배열
    for(int i=0; i<n; i++){
        if(i<n-m) per[i]=0;
        else per[i]=1;
    }
    // n-m개의 블록 겹치지 않게 뽑기
    do{
        for(int k=0; k<n; k++){
            if(per[k]==1) continue;
            //각 블록이 쓰러뜨릴 수 있는 다른 블록의 수 저장
            int big=0;
            for(int i=n-2; i>=0; i--){
                if(per[i]==1) continue;
                for(int j=i+1; j<=n; j++){
                    if(mp[position[j]]>0) {
                        fall[i]+=fall[position[j]]+1;
                        mp[position[j]]=0;
                    }
                }
                big = max(big,fall[i]);
                cout << big << ' ';
            }
            answer = min(answer,big);
            cout << '\n';

        }
    }while(next_permutation(per,per+n));


    return answer;
}

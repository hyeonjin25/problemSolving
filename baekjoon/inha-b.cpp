#include<iostream>
using namespace std;

int n, m, res;
int vis[10], arr[6];
int same[6]={0,1,2,0,1,2};

void re(int cnt){
  if(cnt==n) {
    int sum=0, pre;
    for(int i=0; i<n; i++){
      int job = vis[i];
      if(i!=0&&same[pre]==same[job]) sum+=(arr[job]/2);
      else sum+=arr[job];
      pre = job;
    }
    if(sum>=m) res++;
    return;
  }

  for(int i=0; i<6; i++){
    vis[cnt]=i;
    re(cnt+1);
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n>>m;

  for(int i=0; i<6; i++) cin >> arr[i];

  re(0);
  
  cout << res;
}
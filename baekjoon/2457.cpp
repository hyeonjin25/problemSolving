#include<iostream>
using namespace std;

pair<int,int> arr[100005];
int mtod[15];

int comp(pair<int,int>a, pair<int,int>b){
  if(a.first==b.first) return a.second>b.second;
  return a.first<b.first;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  for(int i=1; i<=12; i++){
    if(i==4||i==6||i==9||i==11) mtod[i] = mtod[i-1]+30;
    else if(i==2) mtod[i] = mtod[i-1]+28;
    else mtod[i] = mtod[i-1]+31;
  }

  int n; cin >> n;

  int m,d,m2,d2;
  for(int i=0; i<n; i++){
    cin >> m >> d >> m2 >> d2;
    arr[i].first = mtod[m-1]+d;
    arr[i].second = mtod[m2-1]+d2;
  }

  sort(arr, arr+n, comp);

  int lng = 0;
  int lngidx = 0;
  for(int i=0; i<n; i++){
    if(arr[i].first>mtod[2]+1) break;
    if(lng<=arr[i].second){
      lng = arr[i].second;
      lngidx = i;
    }
  }

  int ans = 1;
  int st = lngidx;
  lng = 0;
  for(int i=st+1; i<n; i++){
    if(arr[i].first>arr[st].second){
      if(arr[lngidx].second>mtod[10]+30){
        cout << ans+1;
        return 0;
      }
      i = lngidx;
      lng = arr[lngidx].second;
      ans++;
      continue;
    }
    if(lng<=arr[i].second){
      lng = arr[i].second;
      lngidx = i;
    }
  }

  cout << 0;
}
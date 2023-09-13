#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> m;
int z = 0;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  int temp;
  for(int i=0; i<n; i++) {
    cin >> temp;
    if(temp>0) p.push_back(temp);
    if(temp<0) m.push_back(temp);
    if(temp==0) z =1;
  }

  sort(p.begin(), p.end());
  sort(m.begin(), m.end());

  int sum = 0;
  while(p.size()>1){
    int a = p.back();
    p.pop_back()
    int b = p.back();
    p.pop_back();
    ans+=a*b;
  }
  for(int i=p.size()-1; i>=0; i-=2){
    if(p[i]==1) {
      sum+=1; i++;
    }
    else if(i==0) sum+=p[i];
    else sum+=(p[i]*p[i-1]);

  }

  int st = 0;
  if(z && m.size()%2==1) st=1;

  for(int i=st; i<m.size(); i+=2){
    if(i==m.size()-1) sum+=m[i];
    else sum+=(m[i]*m[i-1]);
  }

  cout << sum;
}
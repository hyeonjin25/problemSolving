#include <bits/stdc++.h>

using namespace std;

vector<int>D,P,S;

int main()
{
  int n, k; cin >> n >> k;

  P.resize(n);

  int temp;
  for(int i=0; i<n; i++) {
    cin >> temp;
    S.push_back(temp);
  }

  for(int i=0; i<n; i++) {
    cin >> temp;
    D.push_back(temp);
  }

  for(int i=0; i<k; i++) {
    if(i!=0) S=P;
    for(int j=0; j<n; j++) {
      P[D[j]-1]=S[j];
    }
  }

  for(int i=0; i<n; i++) cout << P[i] << ' ';
}
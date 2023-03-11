#include <bits/stdc++.h>
using namespace std;

int parent[101010]; // 가리키는 부모 노드를 저장

int find(int x) {
  if (parent[x] == x) return x;
  else return x = find(parent[x]); // 압축
}

// union은 내장 함수가 있으므로 merge로 사용
int merge(int x, int y) {
  x = find(x);
  y = find(y);
  // x가 커야 할지, y가 커야 할지 문제에 따라 판단
  if (x > y) swap(x, y);
  // y를 x에게 합침
  parent[y] = x;
}

int main(){
  int n = 100;
  for (int i=1; i<=n; i++) {
    parent[i] = i; // 처음에는 자기 자신을 가리킴
  }
}
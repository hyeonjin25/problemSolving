#include <bits/stdc++.h>

using namespace std;

void func(int a, int b, int n) // 원판 n개를 a에서 b로 옮기는 방법을 출력
{
  if (n == 1)
  {
    cout << a << ' ' << b << '\n';
  }
  else
  {
    func(a, 6 - a - b, n - 1);     // n-1개를 a,b가 아닌 나머지로 옮김
    cout << a << ' ' << b << '\n'; // n번 원판을 a에서 b로 옮긴다.
    func(6 - a - b, b, n - 1);     // n-1개를 다시 나머지에서 b로 옮긴다.
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << (1 << n) - 1 << '\n'; // 수열의 일반항 -> 2^n-1
  func(1, 3, n);
}

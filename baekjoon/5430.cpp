#include <bits/stdc++.h>

using namespace std;

void parse(string x, deque<int> &D)
{
  // 숫자만 추출해서 넣기
  string temp = "";
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] == ',' || x[i] == ']')
    {
      if (temp.size() != 0)
      {
        D.push_back(stoi(temp));
        temp = "";
      }
    }
    else if (x[i] != '[')
    {
      temp += x[i];
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T, n;

  cin >> T;

  while (T--)
  {
    deque<int> D;
    string p, x;
    int rev = 0;
    cin >> p >> n >> x;

    parse(x, D); // 숫자만 추출해서 넣기

    for (auto c : p)
    {
      if (c == 'R')
      {
        rev = 1 - rev; // 뒤집는다는 표시
      }
      else // D
      {
        if (D.size())
        {
          if (!rev)
            D.pop_front();
          else
            D.pop_back();
        }
        else
        {
          cout << "error" << '\n';
          goto g;
        }
      }
    }

    if (rev)
      reverse(D.begin(), D.end());

    cout << '[';
    for (auto i : D)
    {
      cout << i;
      D.pop_front();
      if (D.size())
        cout << ',';
    }
    cout << ']' << '\n';

  g:
    continue;
  }
}
#include <iostream>
#include <stack>

using namespace std;

// 가장 처음에 2번이 들어왔을 경우를 고려해야함.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // test case 수
	int c, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		stack<int> stack;

		std::stack<int> minstack;
		std::stack<int> maxstack;

		int R; //질의 수
		cin >> R;
		int min = 0;
		int max = 0;
		for (int r = 0; r < R; r++) {

			cin >> c;
			if (c == 1) {
				cin >> n; // 1번이면 넣을 숫자 받기
				stack.push(n);

				if (min==0) { min = n; max = n; minstack.push(n); maxstack.push(n); } //처음 받는경우 초기화

				else {
					if(n < min){min = n; minstack.push(n);}
					if(n > max){max = n; maxstack.push(n);}
				}
				cout << min << " " << max << "\n";
			}
			else {
				if (min == 0 || stack.empty()) continue; // stack이 비어있을 경우 건너뛰기

				int top = stack.top();
				stack.pop();
				if (top == min) {
					minstack.pop();
					min = minstack.top();
				}
				if (top == max) {
					maxstack.pop();
					max = maxstack.top();
				}
			}
		}
	}
}
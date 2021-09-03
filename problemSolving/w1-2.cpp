#include <iostream>
#include <stack>

using namespace std;

// ���� ó���� 2���� ������ ��츦 ����ؾ���.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // test case ��
	int c, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		stack<int> stack;

		std::stack<int> minstack;
		std::stack<int> maxstack;

		int R; //���� ��
		cin >> R;
		int min = 0;
		int max = 0;
		for (int r = 0; r < R; r++) {

			cin >> c;
			if (c == 1) {
				cin >> n; // 1���̸� ���� ���� �ޱ�
				stack.push(n);

				if (min==0) { min = n; max = n; minstack.push(n); maxstack.push(n); } //ó�� �޴°�� �ʱ�ȭ

				else {
					if(n < min){min = n; minstack.push(n);}
					if(n > max){max = n; maxstack.push(n);}
				}
				cout << min << " " << max << "\n";
			}
			else {
				if (min == 0 || stack.empty()) continue; // stack�� ������� ��� �ǳʶٱ�

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
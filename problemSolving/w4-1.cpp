#include <iostream>
#include <stdlib.h>

using namespace std;

// GCD(A,B) <= A-B

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // �׽�Ʈ ���̽� ����
	cin >> T;
	for (int t = 0; t < T; t++) {

		int a, b, x, y;
		cin >> a >> b >> x >> y;

		// �ִ� �����
		int gap = abs(a - b);

		// ���õ��� �ø��� ��쿡 �ʿ��� ���
		int cost = (gap - (b % gap)) * x;

		// ���� ������ ���� �ϳ��� �� ���� ���� ���õ��� ���� �� ����.
		if (min(a, b) >= gap)
			cost = min(cost, (b % gap) * y); // ���õ� �ø��� ���� ������ ��� �� �� ���� cost ä��

		cout << gap << " " << cost << "\n";
	}
}
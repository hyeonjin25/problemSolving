#include <iostream>
#include <stdlib.h>

using namespace std;

// GCD(A,B) <= A-B
// a-b�� ������������� 1�� ���ϰų� �A �� �� �� �� ���� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // �׽�Ʈ ���̽� ����
	cin >> T;
	for (int t = 0; t < T; t++) {

		int a, b, x, y;
		cin >> a >> b >> x >> y;

		if (b > a)swap(a, b);

		int cha = a - b;

		cout << min((b % cha) * y, cha - (b % cha) * x) << "\n";
	}
}
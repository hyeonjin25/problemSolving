#include <iostream>
#include <stdlib.h>

using namespace std;

// GCD(A,B) <= A-B
// a-b로 나누어떨어지도록 1을 더하거나 뺸 후 둘 중 더 낮은 가격

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // 테스트 케이스 개수
	cin >> T;
	for (int t = 0; t < T; t++) {

		int a, b, x, y;
		cin >> a >> b >> x >> y;

		if (b > a)swap(a, b);

		int cha = a - b;

		cout << min((b % cha) * y, cha - (b % cha) * x) << "\n";
	}
}
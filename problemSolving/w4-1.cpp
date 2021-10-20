#include <iostream>
#include <stdlib.h>

using namespace std;

// GCD(A,B) <= A-B

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // 테스트 케이스 개수
	cin >> T;
	for (int t = 0; t < T; t++) {

		int a, b, x, y;
		cin >> a >> b >> x >> y;

		// 최대 공약수
		int gap = abs(a - b);

		// 숙련도를 올리는 경우에 필요한 비용
		int cost = (gap - (b % gap)) * x;

		// 둘의 차보다 둘중 하나가 더 작은 경우는 숙련도를 내릴 수 없다.
		if (min(a, b) >= gap)
			cost = min(cost, (b % gap) * y); // 숙련도 올리는 경우와 내리는 경우 중 더 작은 cost 채택

		cout << gap << " " << cost << "\n";
	}
}
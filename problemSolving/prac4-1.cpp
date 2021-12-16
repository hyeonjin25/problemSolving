#include <iostream>
#include <algorithm>

using namespace std;


int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;

		int gap = abs(a - b);

		//�ø�
		int cost = (gap - (b % gap)) * x;

		//����
		if (min(a, b) >= gap) {
			cost = min(cost, (b % gap) * y);
		}

		cout << gap << " " << cost << "\n";
	}
}
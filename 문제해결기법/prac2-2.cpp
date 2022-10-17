#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	return (a.first + a.second) > (b.first + b.second);
}

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		pair<int, int> rs[10001];

		for (int i = 0; i < n; i++) {
			cin >> rs[i].first >> rs[i].second;
		}

		sort(rs, rs + n, compare);

		int in = 0;
		int bi = 0;

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				in += rs[i].first;
			}
			else {
				bi += rs[i].second;
			}
		}

		cout << in - bi << "\n";
	}

}
#include <iostream>
#include <algorithm>

using namespace std;


int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int n;
		cin >> n;

		int sin[5001] = { 0, };
		bool same = false;
		bool suc = false;
		bool end = false;
		int cycle = 0;
		int s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			sin[i] = s;
		}

		int first = sin[0];
		for (int i = 1; i < n; i++) {
			if (first == sin[i]) {
				same = true;
				int j = 0;
				while (same&&!end) {
					while (1) {
						if (sin[j] == sin[i + j]) {
							if (i + j == n - 1) {
								suc = true;
								cycle = i;
								end = true;
								break;
							}
						}
						else {
							same = false;
							break;
						}
						j++;
					}
					j += i;
				}
			}
		}

		if (suc) {
			n = cycle;
		}
		for (int i = 0; i < n; i++) {
			cout << sin[i] << " ";
		}
		cout << "\n";
	}
}
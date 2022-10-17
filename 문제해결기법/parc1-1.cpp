#include <iostream>

using namespace std;

int main() {

	int T;
	string s;
	int k;

	cin >> T;
	for (int t = 0; t < T; t++) {

		cin >> s >> k;

		int slen = s.length();
		int r = (slen % k == 0) ? slen / k : slen / k + 1;

		int idx = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < r; j++) {

				if (j % 2 == 0) { // Â¦¼ö¿­
					idx = i + (j / 2 * 2 * k);
					if (idx > slen - 1) continue;
				}
				else { // È¦¼ö¿­
					idx = (2 * k - 1 - i) + (j / 2 * 2 * k);
					if (idx > slen - 1) continue;
				}
				cout << s[idx];
			}
		}
		cout << "\n";

	}
}
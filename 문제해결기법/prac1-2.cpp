#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;


	for (int t = 0; t < T; t++) {

		int n, min, max;
		vector<int> vec;
		vector<int> min_vec;
		vector<int> max_vec;

		int q, b;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> q;

			if (q == 1) {
				cin >> b;
				if (vec.empty()) {
					min_vec.push_back(b);
					max_vec.push_back(b);
					min = b; max = b;
				}
				if (min > b) {
					min = b;
					min_vec.push_back(b);
				}
				else if (max < b) {
					max = b;
					max_vec.push_back(b);
				}
				vec.push_back(b);
				cout << min << " " << max << "\n";
			}
			else {
				if (!vec.empty()) {
					int top = vec.back();
					vec.pop_back();
					if (min == top) {
						min_vec.pop_back();
						min = min_vec.back();
					}
					if (max == top) {
						max_vec.pop_back();
						max = max_vec.back();
					}
				}
			}
		}

	}

}
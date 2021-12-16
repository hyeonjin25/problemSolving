#include <iostream>

using namespace std;

int n, m;
int house[1000001];

bool check(int len) {
	int cur = 1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (cur <= house[i]) {
			cur = house[i] + len;;
			count++;
		}
		if (count == m) return true;
	}
	return false;
}

int binary(int l, int r) {
	int mid = (l + r) / 2;

	if (l == r) return l;

	if (l + 1 == r) {
		if (check(r)) return r;
		else return l;
	}

	if (check(mid)) 
		binary(mid, r);
	else 
		binary(l, mid - 1);
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}

	cout << binary(1, house[n - 1]);

}
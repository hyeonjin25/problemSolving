#include <iostream>
using namespace std;

int mat[1005];
int dp[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> n;

		// ��Ʈ���ī ũ�� �Է¹ޱ�
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
		}

		int max_count = 0;
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (mat[j] < mat[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			max_count = max(max_count, dp[i]);
		}
		cout << max_count << "\n";
	}
}
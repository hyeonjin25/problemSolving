#include <iostream>
#include <algorithm>

using namespace std;

// ��Ʈ���ī ���� - �迭�� �ش� ��Ʈ���ī�� ������ �� �ִ� �ִ� ������ �����ϰ�, �װ� �̿��ؼ� ��� ������ ����,
// dynamic programming - ��갪 �����ϱ�

int mat[100001];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> n;
		// ��Ʈ���ī ũ�� �ޱ�
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
		}

		int ans = 0;
		// ��Ʈ���ī�� ���鼭 �� ��Ʈ�ν�ī�� �ִ� ���� ���ϱ�
		for (int i = 0; i < n; i++) {
			dp[i] = 1; // �⺻ ���� 1��
			for (int j = 0; j < i; j++) { // ó������ ���� ������ ��Ʈ���ī���� ��
				if (mat[j] < mat[i]) // ��Ʈ���ī�� ������ �� ���� ��
					dp[i] = max(dp[j] + 1,dp[i]); // ���� ���������� j��° ��Ʈ���ī�� 1�� ���� �� �� ū ������ ���� 
			}
			ans = max(ans, dp[i]); // ���ݱ��� ã�� �ִ� ������ i��°�� �ִ� ���� �� ū ������ ����
		}

		cout << ans << "\n";
	}
}
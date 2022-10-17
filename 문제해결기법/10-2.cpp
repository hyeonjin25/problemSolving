#include <iostream>
#include <algorithm>

using namespace std;

// 마트료시카 문제 - 배열에 해당 마트료시카가 합쳐질 수 있는 최대 개수를 저장하고, 그걸 이용해서 계속 저장해 나감,
// dynamic programming - 계산값 저장하기

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
		// 마트료시카 크기 받기
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
		}

		int ans = 0;
		// 마트료시카를 돌면서 각 마트로시카별 최대 개수 구하기
		for (int i = 0; i < n; i++) {
			dp[i] = 1; // 기본 개수 1개
			for (int j = 0; j < i; j++) { // 처음부터 본인 이전의 마트료시카까지 비교
				if (mat[j] < mat[i]) // 마트료시카를 조립할 수 있을 때
					dp[i] = max(dp[j] + 1,dp[i]); // 현재 조립개수와 j번째 마트료시카에 1을 더한 값 중 큰 값으로 갱신 
			}
			ans = max(ans, dp[i]); // 지금까지 찾은 최대 개수와 i번째의 최대 개수 중 큰 값으로 갱신
		}

		cout << ans << "\n";
	}
}
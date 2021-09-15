#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 이득이 되는 자원을 가져가야 하므로 자신한테서의 자원의가치 + 상대방한테서의 자원의가치가 가장 높은 자원 가져가기

bool compare(pair <int,int> a, pair <int,int> b) {
	return a.first + a.second > b.first + b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		int n; // 자원의 종류
		cin >> n;

		vector<pair<int, int>> res_vec; // 자원 담는 벡터 < 인하, 비룡>

		int i_sum = 0;
		int b_sum = 0;


		// 각 왕국의 자원의 가치 입력받기
		for (int w = 0; w < n; w++) {

			int i, b; // 자원의 가치
			cin >> i >> b;

			res_vec.push_back({ i,b });
		}

		// 인하+비룡이 큰 순서대로 내림차순 정렬
		sort(res_vec.begin(), res_vec.end(), compare);

		// 자원 가져가기
		for (int w = 0; w < n; w++) {

			if (w % 2 == 0) { // 짝수번째 일때는 인하왕국이 가져가기
				i_sum += res_vec[w].first;
			}
			else { // 홀수번째 일때는 비룡왕국이 가져가기
				b_sum += res_vec[w].second;
			}
		}
			cout << i_sum - b_sum << "\n";
	}

}
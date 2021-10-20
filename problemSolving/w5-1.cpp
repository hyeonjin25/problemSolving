#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // 테스트 케이스 개수
	cin >> T;
	for (int t = 0; t < T; t++) {

		int n; // 수신된 신호의 시간
		cin >> n;

		vector<int>vec;

		int first, s;
		bool same = false; // 비교한 신호가 서로 일치하는 경우에 참
		bool suc = false; // 주기와 전부 일치하면 참
		bool end = false; // 마지막까지 전부 확인하면 참
		int cycle; // 주기의 길이 저장

		cin >> first;
		vec.push_back(first);
		for (int i = 0; i < n - 1; i++) { // 두번째 부터 받기
			cin >> s;
			vec.push_back(s);
		}

		for (int i = 1; i < n; i++) { // 첫번째 건너띄고 시작
			s = vec[i];
			if (s == first) { // 들어온 신호가 주기의 첫 신호와 같을 때
				same = true;
				int j = 0;
				while (same && !end) {
					for (j; j < j + i; j++) { // 첫 신호부터 해당 신호의 바로 앞까지를 주기로 설정
						if (vec[j + i] != vec[j]) { // 해당 주기가 이 전 주기와 같은지 확인
							same = false; 
							break;
						}
						if (j + i == n - 1) { // 마지막까지 모두 확인했을 경우
							suc = true;
							cycle = i;
							end = true;
							break;
						}
					}
					j += i;
				}
				if (suc) break;
				end = false;
			}
		}

		if (suc) { 
			n = cycle;
		}
		// 주기를 찾았을 때 주기만큼 출력, 주기를 못찾았을 때 전부 출력
		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		cout << "\n";
	}
}
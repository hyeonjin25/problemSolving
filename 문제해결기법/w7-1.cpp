#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;


struct ball { // 위치정보를 좌표로 나타냄
	int num; // 공의 번호
	bool check; //공의 subtree에 대한 확인이 끝났으면 true
};

bool ball_check[101] = { 1, }; // 해당하는 번호의 공의 subtree에 대한 확인이 끝났으면 true
vector<int> ball_sub[101]; // 각 번호의 공보다 가벼운 공들을 담는 array

int n; // 공의 개수
int m; // 양팔저울로 측정한 횟수
int a, b; // b번 공에 비해 무거운 공 a

int recurse(int curball) {
	if (ball_check[curball]) // subtree확인이 끝난 공이면
		return curball; // 자신의 번호 리턴

	else { // subtree 확인이 끝나지 않았으면
		int sub_ball;
		for (int i = 0; i < ball_sub[curball].size(); i++) { // subtree 확인
			sub_ball = recurse(ball_sub[curball][i]);
			// check 된 subtree 합치기
			for (int j = 0; j < ball_sub[sub_ball].size(); j++) {
				ball_sub[curball].push_back(ball_sub[sub_ball][j]);
			}
			ball_check[curball] = true;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // 테스트 케이스 개수
	cin >> T;
	for (int t = 0; t < T; t++) {

		cin >> n >> m;

		// ball_check 초기화
		memset(ball_check, true, size(ball_check));

		// ball_sub에 ball 사이의 관계 입력받기
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			ball_sub[a].push_back(b);
			ball_check[a] = false; // subtree에 공이 들어가면 ball_check 필요
		}

		for (int i = 1; i < n + 1; i++) {
			recurse(i);
		}

		for (int i = 1; i < n + 1; i++) {
			cout << ball_sub[i].size();
		}
	}
}
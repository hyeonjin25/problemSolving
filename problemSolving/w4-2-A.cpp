#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int ccw(pair<int, int>a, pair<int, int>b , pair<int,int>c) {
	int res = (a.first*b.second + b.first*c.second + c.first*a.second) - (a.second*b.first + b.second*c.first + c.second*a.first);

	if (res == 0) return 0; //겹칠 때
	else if (res > 0) return 1; //반시계 방향일 때
	else return -1; //시계방향일 때
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // 테스트 케이스 개수
	cin >> T;
	for (int t = 0; t < T; t++) {
		
		pair<int, int> one[2]; //첫번째 선분
		pair<int, int> two[2]; //두번째 선분

		cin >> one[0].first >> one[0].second >> one[1].first >> one[1].second;
		cin >> two[0].first >> two[0].second >> two[1].first >> two[1].second;

		int cc1 = ccw(one[0], one[1], two[0]) * ccw(one[0], one[1], two[1]); // 첫번째 선분 기준
		int cc2 = ccw(two[0], two[1], one[0]) * ccw(two[0], two[1], one[1]); // 두번째 선분 기준

		int ax1 = one[0].first; int ay1 = one[0].second;
		int ax2 = one[1].first; int ay2 = one[1].second;
		int bx1 = two[0].first; int by1 = two[0].second;
		int bx2 = two[1].first; int by2 = two[1].second;

		if (cc1 < 0 && cc2 < 0) // 두 선분이 교차
			cout << 2 << "\n";

		else if ((cc1 == 0 && cc2 == -1) || (cc1 == -1 && cc2 == 0)) //두 선분이 한 선분의 끝으로 교차
			cout << 2 << "\n";

		else if (cc1 == 1 && cc2 == 1) //두 선분이 서로 평행이며 겹치지 않음
			cout << 1 << "\n";

		else if ((cc1 == 1 && cc2 == -1) || (cc1 == -1 && cc2 == 1)) //두 선분이 서로 수직이며 겹치지 않음
			cout << 1 << "\n";

		else if ((cc1 == 1 && cc2 == 0) || (cc1 == 0 && cc2 == 1)) //두 직선이 "ㄴ" 모양이지만 겹치지 않음
			cout << 1 << "\n";

		else if (cc1 == 0 && cc2 == 0) {

			int a1, a2, b1, b2;
			if (ay1 == ay2 && by1 == by2) {// 두 직선이 x축에 평행한 경우
				a1 = ax1; a2 = ax2;
				b1 = bx1; b2 = bx2;
			}
			else if (ax1 == ax2 && bx1 == bx2) { // 두 직선이 y축에 평행한 경우
				a1 = ay1; a2 = ay2;
				b1 = by1; b2 = by2;
			}
			//없어도 테스트 케이스는 통과되지만 있어야 함
			else { //두 직선이 수직이며 끝과 끝이 겹침
				cout << 2 << "\n";
				continue;
			}

			if (a1 > a2) swap(a1, a2);	
			if (b1 > b2) swap(b1, b2);	

			//두 선분의 길이의 합 (ab + cd)
			int len_sum = abs(a1 - a2) + abs(b1 - b2);
			// 두 선분의 끝 점들 중 가장 먼 점들 사이의 길이(ad || cb)
			int max_len = max(abs(a1 - b2), abs(b1 - a2));

			if (max_len > len_sum) { // 두 선분이 한 직선 안에 있지만 만나지 않음
				cout << 1 << "\n";
			}
			else if (a1 <= b1 && a2 >= b2) {
				// 첫번째 선분이 두번째 선분을 포함함
				cout << 4 << "\n";
			}
			else if (a1 >= b1 && a2 <= b2) {
				// 두번째 선분이 첫번째 선분을 포함함
				cout << 4 << "\n";
			}
			else if (a1 == b2 || a2 == b1) { 
				//두 선분이 한 점으로 이어짐
				cout << 2 << "\n";
			}
			else {
				// 두 선분의 일부가 겹침
				cout << 3 << "\n";
			}
		}
	}
}
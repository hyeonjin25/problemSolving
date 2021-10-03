#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

using namespace std;

// 비교연산할 때 같은 경우도 포함 할지 잘 고려하기 -> 선분이 선분을 포함하는 경우

int ccw(pair<int, int>a, pair<int, int>b, pair<int, int>c) {
	int res = (a.first * b.second + b.first * c.second + c.first * a.second) - (a.second * b.first + b.second * c.first + c.second * a.first);

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

		pair<int, int> a; 
		pair<int, int> b;
		pair<int, int> c; 
		pair<int, int> d; 

		cin >> a.first >> a.second >> b.first >> b.second;
		cin >> c.first >> c.second >> d.first >> d.second;

		if (b > a) { // 작은 쪽이 a
			swap(a, b);
		}
		if (d > c) { // 작은 쪽이 c
			swap(c, d);
		}

		int cc1 = ccw(a, b, c) * ccw(a, b, d); // 첫번째 선분 기준
		int cc2 = ccw(c, d, a) * ccw(c, d, b); // 두번째 선분 기준


		if (cc1 == 0 && cc2 == 0) {

			// 선분 a의 길이
			int a_len = sqrt(pow(ax2 - ax1, 2) + pow(ay2 - ay1, 2));
			// 선분 b의 길이
			int b_len = sqrt(pow(bx2 - bx1, 2) + pow(by2 - by1, 2));
			//두 선분의 길이의 합
			int len_sum = a_len + b_len;

			// 선분 a가 앞에 있을 때 a의 처음에서 b의 끝까지의 길이
			int ab_len = sqrt(pow(ax1 - bx2, 2) + pow(ay1 - by2, 2));
			// 선분 b가 앞에 있을 때 b의 처음에서 a의 끝까지의 길이
			int ba_len = sqrt(pow(bx1 - ax2, 2) + pow(by1 - ay2, 2));
			// 두 선분의 끝 점들 중 가장 먼 점들 사이의 길이
			int max_len = max(ab_len, ba_len);

			if (max_len > len_sum) { // 두 선분이 한 직선 안에 있지만 만나지 않음
				cout << 1 << "\n";
			}
			else if (dot == 1) {
				// 두 선분이 직각이거나 평행이고 끝과끝이 접할 경우
				cout << 2 << "\n";
			}
			// 둘 다 y축에 평행 한 경우 ( 밑의 두 케이스는 x를 대소비교 하기 때문에 x가 모두 같은 해당 케이스는 따로 계산)
			else if (ax1 == ax2 && bx1 == bx2) {
				if(ay1 <= by1 && by1 <= ay2 && ay1 <= by2 && by2 <= ay2) {
					// 첫번째 선분이 두번째 선분을 포함함
					cout << 4 << "\n";
				}
				else if (by1 <= ay1 && ay1 <= by2 && by1 <= ay2 && ay2 <= by2) {
					// 두번째 선분이 첫번째 선분을 포함함
					cout << 4 << "\n";
				}
				else {
					// 두 선분의 일부가 겹침
					cout << 3 << "\n";
				}
			}
			else if (ax1 <= bx1 && bx1 <= ax2 && ax1 <= bx2 && bx2 <= ax2) {
				// 첫번째 선분이 두번째 선분을 포함함
					cout << 4 << "\n";
			}
			else if (bx1 <= ax1 && ax1 <= bx2 && bx1 <= ax2 && ax2 <= bx2) {
				// 두번째 선분이 첫번째 선분을 포함함
					cout << 4 << "\n";
			}
			else {
				// 두 선분의 일부가 겹침
				cout << 3 << "\n";
			}
		}
		else if (cc1 <= 0 && cc2 <= 0) // 두 선분이 교차
			cout << 2 << "\n";

		else cout << 1 << "\n";
	}
}
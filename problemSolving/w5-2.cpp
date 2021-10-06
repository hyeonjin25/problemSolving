#include <iostream>
#include <vector>

using namespace std;

int house[1000001];
int n; // 집의 수
int m; // 주민의 수

// 설정한 거리 이상으로 간격을 두었을 경우 모든 주민의 입주가 가능하면 true 리턴
int check(int len) {
	int cur = 1; // 현재 위치 (다음 집은 cur이상의 거리에만 들어올 수 있음)
	int count = 0; // 입주한 주민 수

	// 기준 거리 이상의 집 중 가장 가까운 집 찾기
	for (int i = 0; i < n; i++) {
		if (cur <= house[i]) {
			cur = house[i] + len; // 입주 성공한 집 위치로부터 기준거리만큼 떨어진 곳
			count++;
		}
		if (count == m) { // 모든 주민이 입주했을 경우
			return true;
		}
	}
	return false;
}

// 이진탐색 이용하여 주민간의 최대거리 찾기
int binary(int l, int r) {

	int mid; // 가운데 인덱스
	int cur; // 현재 탐색중인 인덱스

	mid = (l + r) / 2; // 양 끝의 중간 값 -  기준 거리

	if (l == r) { // 구간이 1일 경우
		return l;
	}
	if (l + 1 == r) { // 구간이 2일 경우 
		if (check(r)) return r;
		else return l;
	}

	// 재귀함수로 최적의 기준거리 찾기
	if (check(mid)) {
		return binary(mid, r);
	}
	else {
		return binary(l, mid - 1); 
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
		
	// 집 위치들 입력 받기
	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}
		
	int asn = binary(1, house[n - 1]);
		
	cout << asn;
}
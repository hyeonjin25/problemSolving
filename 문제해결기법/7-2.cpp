#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

// 햄버거 가게 : k만큼의 원소 수를 유지하는 우선순위 큐에서 max값 출력
// 
// 
// 
// 
// 우선 순위 큐

struct Point {
	int x;
	int y;
	double d;
};

struct cmp {
	bool operator()(Point a, Point b){
		if (a.d == b.d) {
			if (a.x == b.x) return a.y < b.y;
			else return a.x < b.x;
		}
		return a.d < b.d;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, m, n, k, x, y;
	cin >> T;

	for (int t = 0; t < T; t++) {
		priority_queue<Point, vector<Point>, cmp>que;

		cin >> m >> n >> k;

		// 기존의 햄버거 가게 정보 받기
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			que.push(Point({ x, y, sqrt(x * x + y * y) }));
			if (que.size() > k) que.pop(); // que안의 햄버거가게 개수가 k를 넘지 않게 하기
		}

		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			que.push(Point({ x, y, sqrt(x * x + y * y) }));
			if (que.size() > k)
				que.pop(); // que안의 햄버거가게 개수가 k를 넘지 않게 하기
			cout << que.top().x << " " << que.top().y << "\n";
		}
	}
}
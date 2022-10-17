#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

// �ܹ��� ���� : k��ŭ�� ���� ���� �����ϴ� �켱���� ť���� max�� ���
// 
// 
// 
// 
// �켱 ���� ť

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

		// ������ �ܹ��� ���� ���� �ޱ�
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			que.push(Point({ x, y, sqrt(x * x + y * y) }));
			if (que.size() > k) que.pop(); // que���� �ܹ��Ű��� ������ k�� ���� �ʰ� �ϱ�
		}

		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			que.push(Point({ x, y, sqrt(x * x + y * y) }));
			if (que.size() > k)
				que.pop(); // que���� �ܹ��Ű��� ������ k�� ���� �ʰ� �ϱ�
			cout << que.top().x << " " << que.top().y << "\n";
		}
	}
}
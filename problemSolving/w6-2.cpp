#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

// �迭 �ʱ�ȭ ����� �����༭ Ʋ��, �ݺ��� ���� n+1���� �����༭ Ʋ��

struct point { // ��ġ������ ��ǥ�� ��Ÿ��
	int x, y; // x ��, y �� 
};

// ��ǥ��鿡�� �� ��ġ�� �����ϱ� ���� �ּ� �̵�Ƚ�� ����
// ������ ������ ���� �� �ִ� ������ -1�� ǥ��
int check[1001][1001];

// �ݺ��� ���鼭 �ȹ� Ȯ���ϱ� ���� �迭��
int dx[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1}; // 1���� ���
int dy[9] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
point inha, safe, gumsa, gunner; // ����, ��������, �˻�, ���Ѽ��� ��ǥ
int n; // nxn ��ǥ���

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // �׽�Ʈ ���̽� ����
	cin >> T;
	for (int t = 0; t < T; t++) {

		cin >> n;
		cin >> inha.x >> inha.y >> safe.x >> safe.y;
		cin >> gumsa.x >> gumsa.y >> gunner.x >> gunner.y;

		for (int i = 0; i < n + 1; i++) { // check �迭 �ʱ�ȭ
			memset(check[i], 0, sizeof(check[i]));
		}
		
		
		int attackX, attackY;
		// ���Ѽ��� ���ݹ��� ǥ��
		for (int i = 1; i < 9; i++) { // �ȹ� ���� ǥ��
			for (int j = 1; j < n + 1; j++) { // �� �������� ������ ǥ��
				// ���� ��ġ���� x������ dx[i], y������ dy[i]��ŭ ������ ��ġ ���ݰ��� 
				// �ش� ��ġ���� x�� y�࿡ ���� j�踦 �� ��ġ�� ���� ���ݰ���
				attackX = gunner.x + dx[i] * j;
				attackY = gunner.y + dy[i] * j;

				// ��ǥ����� 1���� n������ �����̹Ƿ� ����� break
				if (attackX == 0 || attackY == 0 || attackX == n + 1 || attackY == n + 1)
					break;

				// �˻翡 ���θ����� ���
				if (attackX == gumsa.x && attackY == gumsa.y)
					break;

				check[attackX][attackY] = -1;
			}
		}

		// �˻��� ���ݹ��� ǥ��
		for (int i = 1; i < 9; i++) { // �ȹ� ���� ǥ��
			// ���� ��ġ���� x������ dx[i], y������ dy[i]��ŭ ������ ��ġ ���ݰ��� 
			attackX = gumsa.x + dx[i];
			attackY = gumsa.y + dy[i];

			// ��ǥ����� 1���� n������ �����̹Ƿ� ����� continue
			if (attackX == 0 || attackY == 0 || attackX == n + 1 || attackY == n + 1)
				continue;

			check[attackX][attackY] = -1;
		}

		//for (int i = 1; i < n+1; i++) { // �ȹ� ���� ǥ��
		//   for (int j = 1; j < n + 1; j++) { // �� �������� ������ ǥ��
		//      cout << check[i][j] << " ";
		//   }
		//   cout << "\n";
		//}


		// BFS
		int moveX, moveY;
		queue<point>que;
		bool visited[1001][1001] = { 0, };
		que.push({ inha.x, inha.y }); //������ ��ġ���� ����

		while (!que.empty()){
			point now = que.front();
			que.pop();
			visited[now.x][now.y] = true;

			for (int i = 1; i < 9; i++) {
				moveX = now.x + dx[i];
				moveY = now.y + dy[i];

				// ������ ��� ���
				if (moveX == 0 || moveY == 0 || moveX == n + 1 || moveY == n + 1)
					continue;

				// ������ ���� �� �ִ� ��ġ�̰ų� �̹� �湮�� ��ġ�� ���
				// �� check[moveX][moveY] == -1 �� �ȵǴ��� �𸣰����� �ȵ�
				if (check[moveX][moveY] != 0 || visited[moveX][moveY])
					continue;

				// �̵��� �Ÿ� ����
				check[moveX][moveY] = check[now.x][now.y] + 1;
				que.push({ moveX,moveY });
			}
		}

		// �������뿡 ������ �̵��Ÿ� ���
		cout << check[safe.x][safe.y] << "\n";

	}
}
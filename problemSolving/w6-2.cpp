#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

// 배열 초기화 제대로 안해줘서 틀림, 반복문 범위 n+1까지 안해줘서 틀림

struct point { // 위치정보를 좌표로 나타냄
	int x, y; // x 행, y 열 
};

// 좌표평면에서 각 위치에 도착하기 위한 최소 이동횟수 저장
// 적군의 공격이 닿을 수 있는 범위는 -1로 표시
int check[1001][1001];

// 반복문 돌면서 팔방 확인하기 위한 배열들
int dx[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1}; // 1부터 사용
int dy[9] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
point inha, safe, gumsa, gunner; // 인하, 안전지역, 검사, 소총수의 좌표
int n; // nxn 좌표평면

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // 테스트 케이스 개수
	cin >> T;
	for (int t = 0; t < T; t++) {

		cin >> n;
		cin >> inha.x >> inha.y >> safe.x >> safe.y;
		cin >> gumsa.x >> gumsa.y >> gunner.x >> gunner.y;

		for (int i = 0; i < n + 1; i++) { // check 배열 초기화
			memset(check[i], 0, sizeof(check[i]));
		}
		
		
		int attackX, attackY;
		// 소총수의 공격범위 표시
		for (int i = 1; i < 9; i++) { // 팔방 돌며 표시
			for (int j = 1; j < n + 1; j++) { // 한 방향으로 끝까지 표시
				// 원래 위치에서 x축으로 dx[i], y축으로 dy[i]만큼 떨어진 위치 공격가능 
				// 해당 위치에서 x와 y축에 각각 j배를 한 위치도 전부 공격가능
				attackX = gunner.x + dx[i] * j;
				attackY = gunner.y + dy[i] * j;

				// 좌표평면의 1부터 n까지의 범위이므로 벗어나면 break
				if (attackX == 0 || attackY == 0 || attackX == n + 1 || attackY == n + 1)
					break;

				// 검사에 가로막히는 경우
				if (attackX == gumsa.x && attackY == gumsa.y)
					break;

				check[attackX][attackY] = -1;
			}
		}

		// 검사의 공격범위 표시
		for (int i = 1; i < 9; i++) { // 팔방 돌며 표시
			// 원래 위치에서 x축으로 dx[i], y축으로 dy[i]만큼 떨어진 위치 공격가능 
			attackX = gumsa.x + dx[i];
			attackY = gumsa.y + dy[i];

			// 좌표평면의 1부터 n까지의 범위이므로 벗어나면 continue
			if (attackX == 0 || attackY == 0 || attackX == n + 1 || attackY == n + 1)
				continue;

			check[attackX][attackY] = -1;
		}

		//for (int i = 1; i < n+1; i++) { // 팔방 돌며 표시
		//   for (int j = 1; j < n + 1; j++) { // 한 방향으로 끝까지 표시
		//      cout << check[i][j] << " ";
		//   }
		//   cout << "\n";
		//}


		// BFS
		int moveX, moveY;
		queue<point>que;
		bool visited[1001][1001] = { 0, };
		que.push({ inha.x, inha.y }); //인하의 위치에서 시작

		while (!que.empty()){
			point now = que.front();
			que.pop();
			visited[now.x][now.y] = true;

			for (int i = 1; i < 9; i++) {
				moveX = now.x + dx[i];
				moveY = now.y + dy[i];

				// 범위를 벗어난 경우
				if (moveX == 0 || moveY == 0 || moveX == n + 1 || moveY == n + 1)
					continue;

				// 공격을 받을 수 있는 위치이거나 이미 방문한 위치인 경우
				// 왜 check[moveX][moveY] == -1 은 안되는지 모르겠으나 안됨
				if (check[moveX][moveY] != 0 || visited[moveX][moveY])
					continue;

				// 이동한 거리 누적
				check[moveX][moveY] = check[now.x][now.y] + 1;
				que.push({ moveX,moveY });
			}
		}

		// 안전지대에 누적된 이동거리 출력
		cout << check[safe.x][safe.y] << "\n";

	}
}
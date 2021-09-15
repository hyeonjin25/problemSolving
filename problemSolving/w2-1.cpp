#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// break, continue등 헷갈리지 말고 잘 쓰기

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		vector<queue<string>> stu_vec;

		int n; //친구들의 수
		int m; //판별할 문장의 단어 수
		cin >> n >> m;

		// 판별할 문장 받기
		vector<string> str_vec;
		string str;

		for (int w = 0; w < m; w++) {
			cin >> str;
			str_vec.push_back(str);
		}

		int k; //친구들이 적은 단어의 수

		// 친구들이 적은 단어들 받기
		for (int i = 0; i < n; i++) {
			cin >> k;
			queue<string>stu_que;
			for (int j = 0; j < k; j++) {
				cin >> str;
				stu_que.push(str);
			}
			stu_vec.push_back(stu_que);
		}

		int flag = 0;
		for (int w = 0; w < m; w++) {

			str = str_vec[w]; // w번째 단어

			for (int v = 0; v < n; v++) {
				if (stu_vec[v].front().compare(str) == 0) { // str이 학생들 중 한명의 첫번째 원소일 경우
					stu_vec[v].pop();
					flag = 1;
					break;
				}
				else flag = 0;
			}
			
			// 어느 학생의 첫번째 원소도 아닐 경우 
			if (flag == 0) {
				cout << 0 << "\n";
				break; //다음 케이스로
			}
			else if (w == m - 1) { //마지막 단어였을 경우
				cout << 1 << "\n";
			}
		}
	}
}
#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		queue<string> stu_arr[21];
		string str_arr[2001];

		int n, m;

		cin >> n >> m;

		string str;
		for (int i = 0; i < m; i++) {
			cin >> str;
			str_arr[i] = str;
		}

		int k;
		for (int i = 0; i < n; i++) {
			cin >> k;
			for (int j = 0; j < k; j++) {
				cin >> str;
				stu_arr[i].push(str);
			}
		}

		int suc = true;

		for (int i = 0; i < m; i++) {
			str = str_arr[i];
			for (int j = 0; j < n; j++) {
				if (str == stu_arr[j].front()) { // j학생의 첫문장과 일치하면 다음 문장으로
					suc = true;
					stu_arr[j].pop();
					break;
				}
				else { // j학생의 첫문장과 일치하지 않으면 다음 학생으로 넘어감
					suc = false;
				}
			}
			if (!suc) {
				cout << "0\n";
				break;
			}
		}
		if(suc)	cout << "1\n";
	}

}
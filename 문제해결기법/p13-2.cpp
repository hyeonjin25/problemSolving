#include <iostream>
#include <set>
using namespace std;

int sender[500005];
int no_read[500005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,n,m;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        for (int i = 1; i < m+1; i++) {// 메세지 1번부터 m번까지
            cin >> sender[i]; // 해당 메세지를 보낸 사람 저장
        }

        set<int> readers;

        for (int i = m; i > 0; i--) { // 끝에서부터 시작하면서 누적
            readers.insert(sender[i]); // 해당 메시지를 보낸 사람을 읽은 사람그룹에 추가
            no_read[i] = n - readers.size();
        }

        for (int i = 1; i < m + 1; i++) {
            cout << no_read[i] << " ";
        }
        cout << "\n";
    }
}
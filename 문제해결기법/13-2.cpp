#include <iostream>
#include <stack>
#include <memory.h>
#include <set>

using namespace std;

// 메세지 읽지 않은 사람 수 구하기
// 중복 제거되는 set이용해서 밑에서 부터 읽은 사람 수 저장
// 읽지 않은 사람 수 구해야 하므로 n -  읽은 사람 수 저장

int sender[500001]; // 메세지 전송자 저장
int n, m; // 인원 수, 메세지 수
int no_read[500001]; // 읽은 사람 수 각각 저장 (뒤에서 부터)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> n >> m;
        for (int i = 1; i < m + 1; i++) { // 메세지 전송자 입력받기
            cin >> sender[i];
        }
        
        set<int> readers;

        for (int i = m; i > 0; i--) { // 가장 최근에 메세지 보낸 사람부터 시작
            readers.insert(sender[i]); // 해당 메세지를 쓴 사람 set에 저장 (중복 제거됨)
            no_read[i] = n - readers.size(); // 해당 매세지를 읽지 않은 사람 수 저장
        }

        for (int i = 1; i < m + 1; i++) { // 메세지 읽은 사람 수 출력
            cout << no_read[i] << "\n";
        }
    }
}
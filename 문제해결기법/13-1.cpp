#include <iostream>
using namespace std;

// 단어 퍼즐
// kmp문제

string puz[3000];
int fail[3000];

void fail_func(string p) {
    fail[0] = 0; // 0번쨰 에는 무조건 0저장
    int j = 0;
    for (int i = 1; i < p.size(); i++) { // 1번째부터 시작
        while (j > 0 && p[j] != p[i]) { // 실패 함수를 이용한 시프트
            j = fail[j - 1];
        }
        if (p[j] == p[i]) {
            j++;
        }
        fail[i] = j;
    }
}

int kmp(string t, string p) {
    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        while (j>0 && p[j]!=t[i]) { // 실패 함수를 이용한 시프트
            j = fail[j - 1];
        }
        if (p[j] == t[i]) {
            if (j == p.size() - 1) { // 검색 성공
                return 1;
            }
            else{ // 다음 검색  
                j++;
            }
        }
    }
    return 0; // 반복문에서 성공이 리턴되지 않으면 실패로 간주
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 각 줄마다 격자판 알파벳 스트링으로 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> puz[i];
    }
    string text, word; // 격자판을 합친 문자열, 찾을 단어

    // 격자판을 가로로 읽은 문자열
    for (int i = 0; i < n; i++) {
        text += puz[i];
        text += "$";
    }
    // 격자판을 세로로 읽은 문자열
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            text += puz[j][i];
        }
        text += "$";
    }

    // 격자판을 대각선으로 읽은 문자열
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            text += puz[j][j+i];
        }
        text += "$";
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            text += puz[j+i][j];
        }
        text += "$";
    }

    for (int i = 0; i < m; i++) {
        cin >> word; // 찾을 단어 받기

        fail_func(word); // 실패함수 계산

        if (kmp(text, word)) { // 검색성공
            cout << 1 << "\n";
        }
        else cout << 0 << "\n"; //검색실패
    }
}
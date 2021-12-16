#include <iostream>
#include <string>

// 못품

using namespace std;

// 가장 큰 종이에서 시작해서 종이의 모든 색깔이 일치하지 않으면 4면으로 쪼개서 다시 색깔확인 반복 -> 재귀

int n, w, s;
int m; // 단어의 수
char alph[123]; //알파벳 아스키코드 97 ~ 122 까지 사용
string words[24]; //단어 저장
int score[24]; // 영어단어 생성시 얻을 점수 저장
bool visit[24] = { 0, };
int max_sum = 0; // 점수의 합의 최댓값

void recur(int idx, bool visit[], char alph[], int sum) { // 시작할 영어단어 받기
    visit[idx] = 1;
    for (int i = 0; i < m; i++) {
        if (visit[i]) continue; // 이미 확인한 곳은 건너뛰기
        // 단어를 생성할 수 있는지 확인
        for (int j = 0; j < words[i].size(); j++) {
            if (!alph[words[i][j]]) {//알파벳이 부족한 경우 다음 재귀호출 하지 않고 종료
                max_sum = max(max_sum, sum);
                return;
            }
            alph[words[i][j]]--; //알파벳 카드 사용
        }
        // 단어를 생성할 수 있을 시 점수 추가
        sum += score[i];
        recur(i, visit, alph, sum + score[i]);
        if (i == m-1) i = 0; //끝에 도달하면 다시 처음으로 
    }
    visit[alpha]
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // 각 알파벳의 카드의 수 입력받기
    for (int N = 0; N < 26; N++) {
        cin >> n;
        alph[n] = n; //아스키코드에 맞는 위치에 넣음
    }

    cin >> m;
    
    for (int i = 0; i < m; i++) cin >> words[i]; // 영어 단어 받기
    for (int i = 0; i < m; i++) cin >> score[i]; // 영어 단어별 점수 받기


}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
vector<string> board;
int maxLen = 0;

// Up, Down, Left, Right position.
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// BackTracking Functions
// r, c := Current Index 
// mask: Maintain a record of visited characters in a bitmask 
// e.g. Map 'A' to bit index 0.
// cnt: Maintain a count of the total distance traveled

void dfs(int r, int c, int mask, int cnt) {
    // 최대 방문 칸 수 갱신
    if (cnt > maxLen) {
        maxLen = cnt;
    }
    // 상하좌우 4방향 탐색
    for (int i  : {0, 1, 2, 3}) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // 보드의 범위를 벗어나지 않는지 확인
        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
            // 다음 칸에 있는 문자가 무엇인지 숫자로 변환 (A=0, B=1, ...)
            int next_alpha = board[nr][nc] - 'A';
            
            // 해당 알파벳을 아직 방문하지 않았는지 비트 & 연산으로 확인
            if ((mask & (1 << next_alpha)) == 0) {
                // 방문 처리를 위해 비트 | 연산을 하여 다음 탐색 진행
                dfs(nr, nc, mask | (1 << next_alpha), cnt + 1);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    
    board.resize(R);
    for(int i = 0; i < R; i++) {
        cin >> board[i];
    }

    // 시작점 (0, 0)의 알파벳을 확인
    int start_alpha = board[0][0] - 'A'; // 0
    
    // 시작점 방문 처리 후 DFS 탐색 시작
    dfs(0, 0, (1 << start_alpha), 1);

    // 결과 출력
    cout << maxLen << "\n";

    return 0;
}
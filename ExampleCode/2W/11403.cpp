#include <iostream>
#include <bitset>

using namespace std;

bitset<100> reach[100];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    // 1. 인접 행렬
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val) reach[i].set(j);
        }
    }

    // 2. Transitive closure
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            // i에서 k로 갈 수 있다면, i에서 갈 수 있는 곳들에 k에서 갈 수 있는 곳들을 합집합
            if (reach[i].test(k)) {
                reach[i] |= reach[k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << reach[i].test(j) << " ";
        }
        cout << "\n";
    }

    return 0;
}
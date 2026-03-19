#include <iostream>

using namespace std;

// X의 이진수 표현에서 1의 개수를 세는 함수
long long countBits(long long n) {
    long long count = 0;
    while (n > 0) {
        if (n & 1) count++; // 맨 끝 비트가 1인지 확인
        n >>= 1;
        // 오른쪽으로 한 칸씩 밀기
    }
    return count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long long S, X;
    cin >> S >> X;

    // 1. S < X 인 경우
    if (S < X) {
        cout << 0 << "\n";
        return 0;
    }

    // 2. (S - X)가 홀수여서 나누어 떨어지지 않는 경우
    if ((S - X) % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long D = (S - X) / 2;

    // 3. D와 X의 비트가 겹치는 경우, Aka 모순
    if ((D & X) != 0) {
        cout << 0 << "\n";
        return 0;
    }

    // 4. compute pair
    long long onesCount = countBits(X);
    long long ans = 1LL << onesCount;

    // 5. (S, 0), (0, S) 쌍 제외
    if (S == X) {
        ans -= 2;
    }

    // 최종 결과 출력
    cout << ans;

    return 0;
}
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    set<string> S;
    string temp;

    while (N--) {
        cin >> temp;
        S.insert(temp);
    }

    int c = 0;
    while (M--) {
        cin >> temp;
        if (S.count(temp)) c++;
    }

    cout << c;

    return 0;
}
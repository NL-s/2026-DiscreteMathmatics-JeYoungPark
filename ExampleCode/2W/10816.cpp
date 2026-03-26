#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    multiset<int> ms;
    while (n--) {
        int x; cin >> x;
        ms.insert(x);
    }
    int m; cin >> m;
    while (m--) {
        int x; cin >> x;
        cout << ms.count(x) << " ";
    }
    return 0;
}
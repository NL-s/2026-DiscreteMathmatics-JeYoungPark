#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int parent[1000001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    iota(parent, parent + n + 1, 0);

    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            uni(a, b);
        } else {
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
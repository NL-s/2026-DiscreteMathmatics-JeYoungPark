#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; 
    cin >> n >> m;
    set<string> s;
    while (n--) { string x; cin >> x; s.insert(x); }
    vector<string> res;
    while (m--) {
        string x; cin >> x;
        if (s.count(x)) 
            res.push_back(x);
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (auto& x : res) cout << x << "\n";
    return 0;
}
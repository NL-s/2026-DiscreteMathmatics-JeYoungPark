#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    set<string, greater<string>> s;
    while (n--) {
        string name, act; cin >> name >> act;
        if (act == "enter") s.insert(name);
        else s.erase(name);
    }
    for (const auto& name : s) cout << name << "\n";
    return 0;
}
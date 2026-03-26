#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; 
    cin >> n >> m;
    map<string, int> name_to_id;
    vector<string> id_to_name(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> id_to_name[i];
        name_to_id[id_to_name[i]] = i;
    }
    
    while (m--) {
        string q; cin >> q;
        if (isdigit(q[0])) cout << id_to_name[stoi(q)] << "\n";
        else cout << name_to_id[q] << "\n";
    }
    
    return 0;
}
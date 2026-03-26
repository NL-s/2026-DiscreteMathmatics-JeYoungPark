#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

    cin.tie(0)->sync_with_stdio(0);
    string s; 
    
    cin >> s;
    
    set<string> res;

    for (int i = 0; i < s.length(); i++) {
        for (int len = 1; i + len <= s.length(); len++) {
            res.insert(s.substr(i, len));
        }
    }

    
    cout << res.size();
    
    return 0;
}
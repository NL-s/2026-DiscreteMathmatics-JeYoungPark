#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; 
    cin >> n >> m;
    
    set<int> s;
    
    int common = 0;
    for (int i = 0; i < n + m; i++) {
        int x; 
        cin >> x;
        
        if (s.count(x)) //s.count(x) == s에 x라는 원소가 있냐? 
            common++;
        else 
            s.insert(x);
    }
    
    cout << (n + m) - 2 * common;
    return 0;
}
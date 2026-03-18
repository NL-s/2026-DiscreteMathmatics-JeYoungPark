#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m;
    cin >> m;

    unsigned int S = 0;

    while(m--) { 
        string h;
        cin >> h;
        
        int in = 0;

        if(h != "all" && h != "empty") {
            cin >> in;
        }

        if(h == "add") {
            S |= (1 << in);    
        } else if (h == "remove") {
            S &= ~(1 << in);
        } else if (h == "check") {
            cout << (S && (1 << in)) << '\n';
        } else if (h == "toggle") {
            S ^= (1 << in);
        } else if (h == "all") {
            S = (1 << 21) - 1; 
        } else if (h == "empty") {
            S = 0;
        }
    }

    return 0;
}
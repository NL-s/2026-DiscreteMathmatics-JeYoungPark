#include <iostream>
#include <bitset>

using namespace std;

int main()  {
    cin.tie(0)->sync_with_stdio(0);


    int val = 0;

    static unsigned char bitmask[1 << 22] = {0};

    while(cin >> val) {

        int pos1 = val >> 3;
        int pos2 = val % 8;

        if(!(bitmask[pos1] & (1 << pos2))) {
            bitmask[pos1] |= (1 << pos2);
            cout << val << ' ';
        }

    }
    
}
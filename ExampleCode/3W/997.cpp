#include <vector>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> net(n + 1, 0);
        for (auto& t : trust) {
            net[t[0]]--;
            net[t[1]]++;
        }
        for (int v = 1; v <= n; v++) {
            if (net[v] == n - 1) return v;
        }
        return -1;
    }
};
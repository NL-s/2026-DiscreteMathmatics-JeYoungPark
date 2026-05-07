#include <vector>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // 별 그래프에서 중심 정점은 모든 간선에 등장한다 (deg = n-1).
        // 따라서 첫 두 간선만 비교하면 충분, 둘에 공통으로 나타나는
        // 정점이 곧 중심이다. n >= 3 이 보장되므로 edges[1] 은 항상 존재.
        int u0 = edges[0][0], v0 = edges[0][1];
        int u1 = edges[1][0], v1 = edges[1][1];
        
        return (u0 == u1 || u0 == v1) ? u0 : v0;
    }
    /* naive version.
     * // Naive: O(n) 시간, O(n) 공간  모든 간선을 보고 차수 카운트
     *  int findCenter_naive(vector<vector<int>>& edges) {
     *      int n = edges.size() + 1;
     *       vector<int> deg(n + 1, 0);
     *       for (auto& e : edges) { deg[e[0]]++; deg[e[1]]++; }
     *       for (int v = 1; v <= n; v++) if (deg[v] == n - 1) return v;
     *       return -1;
     *   }
     */
};
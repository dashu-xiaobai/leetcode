// Time: O(klog(mn)) with union by size.

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int Find(int x, unordered_map<int, int>& parent) {
    if (x != parent[x]) parent[x] = Find(parent[x], parent);
    return parent[x];
}

int GetIndex(int x, int y, int n) {
    return x * n + y;
}

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        set<std::pair<int, int>> grid;
        unordered_map<int, int> parent;
        unordered_map<int, int> size;

        int cur_count = 0;
        vector<int> island_count;
        for (const auto& position : positions) {
            int x = position[0], y = position[1];
            if (grid.count({x, y})) {
                island_count.push_back(cur_count);
                continue;
            }
            grid.insert({x, y});

            int idx = GetIndex(x, y, n);
            parent[idx] = idx;
            size[idx] = 1;
            
            int union_count = 0;
            for (int d = 0; d < 4; d++) {
                int p = Find(idx, parent);
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid.count({nx, ny})) {
                    int np = Find(GetIndex(nx, ny, n), parent);
                    if (p != np) {
                        if (size[np] < size[p]) {
                            parent[np] = p;
                            size[p] += size[np];
                        }
                        else {                            
                            parent[p] = np;
                            size[np] += size[p];
                        }
                        union_count++;
                    }
                }
            }

            cur_count++;
            cur_count -= union_count;
            island_count.push_back(cur_count);
        }

        return island_count;
    }
};
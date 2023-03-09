// Time: O((k + mn)*log(mn))

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int Find(int x, vector<int>& parent) {
    if (x != parent[x]) parent[x] = Find(parent[x], parent);
    return parent[x];
}

int GetIndex(int x, int y, int n) {
    return x * n + y;
}

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n));
        vector<int> parent(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int index = GetIndex(i, j, n);
                parent[index] = index;
            }
        }

        int count = 0;
        vector<int> island_count;

        for (const auto& position : positions) {
            int x = position[0], y = position[1];
            if (grid[x][y] == 1) {
                island_count.push_back(count);
                continue;
            }

            grid[x][y] = 1;
            int union_count = 0;
            int p = Find(GetIndex(x, y, n), parent);
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    int np = Find(GetIndex(nx, ny, n), parent);
                    if (p != np) {
                        parent[np] = p;
                        union_count++;
                    }
                }
            }

            count += 1 - union_count;
            island_count.push_back(count);
        }

        return island_count;
    }
};
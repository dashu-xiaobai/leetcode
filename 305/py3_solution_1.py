# Time: O((k + mn)*log(mn))

_DX = (0, 0, -1, 1)
_DY = (-1, 1, 0, 0)

def _find(x: int, parent: List[int]) -> int:
    if x != parent[x]:
        parent[x] = _find(parent[x], parent)
    return parent[x]

def _get_index(x: int, y: int, n: int) -> int:
    return x * n + y

class Solution:  
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        grid = [[0 for i in range(n)] for j in range(m)]

        parent: List[int] = []
        for i in range(m):
            for j in range(n):
                parent += [_get_index(i, j, n)]

        cur_count = 0
        island_count: List[int] = []
        
        for x, y in positions:
            if grid[x][y] == 1:
                island_count += [cur_count]
                continue

            grid[x][y] = 1
            p = _find(_get_index(x, y, n), parent)
            union_count = 0

            for d in range(4):
                nx = x + _DX[d]
                ny = y + _DY[d]           

                if nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1:
                    np = _find(_get_index(nx, ny, n), parent)
                    if p != np:
                        parent[np] = p
                        union_count += 1

            cur_count += 1 - union_count
            island_count += [cur_count]

        return island_count
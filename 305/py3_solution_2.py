# Time: O(klog(mn))

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
        grid : Set[tuple[int, int]] = set()
        parent: Dict[int, int] = {}
        size: Dict[int, int] = {}

        cur_count = 0
        island_count: List[int] = []
        
        for x, y in positions:
            if (x, y) in grid:
                island_count += [cur_count]
                continue

            idx = _get_index(x, y, n)
            parent[idx] = idx
            size[idx] = 1
            grid.add((x, y))
            union_count = 0

            for d in range(4):
                p = _find(_get_index(x, y, n), parent)
                nx = x + _DX[d]
                ny = y + _DY[d]           

                if nx >= 0 and nx < m and ny >= 0 and ny < n and (nx, ny) in grid:
                    np = _find(_get_index(nx, ny, n), parent)
                    if p != np:
                        if (size[np] < size[p]):
                            parent[np] = p
                            size[p] += size[np]
                        else:
                            parent[p] = np
                            size[np] += size[p]
                        union_count += 1

            cur_count += 1 - union_count
            island_count += [cur_count]

        return island_count
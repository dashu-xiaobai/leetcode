class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self._m = len(matrix)
        self._n = len(matrix[0])
        self._col_sum = [[0] * (self._n + 1) for _ in range(self._m + 1)]
        self._matrix = [[0] * (self._n + 1) for _ in range(self._m + 1)]
        
        for i in range(1, self._m + 1):
            for j in range(1, self._n + 1):
                self._matrix[i][j] = matrix[i - 1][j - 1]
                self._col_sum[i][j] += self._col_sum[i][j - 1] + matrix[i - 1][j - 1]

    def update(self, row: int, col: int, val: int) -> None:
        row += 1
        col += 1
        diff = val - self._matrix[row][col]
        for i in range(col, self._n + 1):
            self._col_sum[row][i] += diff
        self._matrix[row][col] = val

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sum = 0
        for i in range(row1 + 1, row2 + 2):
            sum += self._col_sum[i][col2 + 1] - self._col_sum[i][col1]
        return sum



# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
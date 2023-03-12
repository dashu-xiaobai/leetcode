using Matrix = vector<vector<int>>;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        col_sum = Matrix(m + 1, vector<int>(n + 1));
        this->matrix = Matrix(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                this->matrix[i][j] = matrix[i - 1][j - 1];
                col_sum[i][j] += col_sum[i][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    void update(int row, int col, int val) {
        row++; col++;
        int diff = val - matrix[row][col];
        for (int i = col; i <= n; i++) {
            col_sum[row][i] += diff;
        }
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += col_sum[i][col2] - col_sum[i][col1 - 1];
        }
        return sum;
    }

private:
    int m = 0, n = 0;
    Matrix col_sum;
    Matrix matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
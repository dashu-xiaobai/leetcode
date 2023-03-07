class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum = { 0 };
        for (int i = 1; i <= nums.size(); i++) {
            sum.push_back(sum.back() + nums[i - 1]);
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }

private:
   vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
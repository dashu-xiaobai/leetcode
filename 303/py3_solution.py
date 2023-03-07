class NumArray:

    def __init__(self, nums: List[int]):
        self._prefix_sum = [ 0 ]
        for num in nums:
            self._prefix_sum += [self._prefix_sum[-1] + num]

    def sumRange(self, left: int, right: int) -> int:
        return self._prefix_sum[right + 1] - self._prefix_sum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
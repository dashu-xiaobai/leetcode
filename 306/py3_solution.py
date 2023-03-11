def _pass_leading_zero_check(s: str) -> bool:
    return s and (len(s) == 1 or s[0] != '0')

class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)

        for i in range(1, n):
            for j in range(1, n - i + 1):
                a, b = num[:i], num[i:i+j]
                if not _pass_leading_zero_check(a) or not _pass_leading_zero_check(b):
                    continue

                right = i + j
                while True:
                    sum = str(int(a) + int(b))
                    sum_len = len(sum)
                    if right + sum_len > n:
                        break
                    if sum != num[right:right+sum_len]:
                        break

                    a, b = b, sum
                    right += sum_len
                    if right == n:
                        return True

        return False
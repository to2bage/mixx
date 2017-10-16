"""
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
"""

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not numbers or len(numbers) < 2:
            return [-1, -1]
        self.rect = []
        left, right = 0, len(numbers) - 1
        while left < right:
            value = numbers[left] + numbers[right]
            if value > target:
                right -= 1
                while left < target and numbers[right] == numbers[right + 1]:
                    right -= 1
            elif value < target:
                left += 1
                while right < target and numbers[left] == numbers[left - 1]:
                    left += 1
            elif value == target:
                self.rect.append([left + 1, right + 1])
                return self.rect

if __name__ == "__main__":
    s = Solution()
    numbers = [2, 7, 11, 15]
    target = 9
    r = s.twoSum(numbers, target)
    print(r)
    
"""
    收费的题目
    Given an array of n integer nums and a target, find the number of index triplets i, j, k 
    with 0 <= j < k < n that satisfy the condition 
    nums[i] + nums[j] + nums[k] < target
    For example, given nums = [-2, 0, 1, 3], and target = 2
    Return 2. Because there are two triplets which sums are less than 2:
        [-2, 0, 1]
        [-2, 0, 3]
"""
class Solution(object):
    def threeSumSmaller(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums or len(nums) < 3:
            return 0
        self.result_count = 0
        nums.sort()
        for i in range(len(nums)):
            left, right = i + 1, len(nums) - 1
            while left < right:
                value = nums[i] + nums[left] + nums[right]
                if value > target:
                    right -= 1
                elif value < target:
                    self.result_count += 1
                    left += 1
                elif value == target:
                    self.result_count += 1
                    left += 1
                    right -= 1
        return self.result_count

if __name__ == "__main__":
    s = Solution()
    nums = [-2, 0, 1, 3]
    target = 2
    r = s.threeSumSmaller(nums, target)
    print(r)

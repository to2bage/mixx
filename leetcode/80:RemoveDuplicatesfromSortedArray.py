"""
    https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
    数组元素可以重复两次
"""
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return 1
        tail = 2
        for i in range(2, len(nums)):
            if nums[i] != nums[tail - 1] or nums[i] != nums[tail - 2]:
                nums[tail] = nums[i]
                tail += 1
        return tail

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,1,2,2,3]
    r = s.removeDuplicates(nums)
    print(nums)
    print(r)


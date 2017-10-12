"""
    14. http://www.lintcode.com/zh-cn/problem/first-position-of-target/
    给定一个排序的整数数组（升序）和一个要查找的整数target，用O(logn)的时间查找到target第一次出现的下标（从0开始），如果target不存在于数组中，返回-1。
    在数组 [1, 2, 3, 3, 4, 5, 10] 中二分查找3，返回2。
"""
class Solution:
    # @param nums: The integer array
    # @param target: Target number to find
    # @return the first position of target in nums, position start from 0 
    def binarySearch(self, nums, target):
        # write your code here
        if not nums:
            return -1
        #nums = list(set(nums))
        left, right = 0, len(nums) - 1
        while left + 1 < right:
            mid = left + (right - left) // 2
            if nums[mid] > target:
                right = mid
            elif nums[mid] < target:
                left = mid
            elif nums[mid] == target:
                #return mid
                right = mid       #处理数组nums中的重复的数据  
        if nums[left] == target:
            return left
        elif nums[right] == target:
            return right
        else:
            return -1

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,3,4,5,10]
    r = s.binarySearch(nums, 3)
    print(r)
"""
    Given an array of integers, find how many paiers in the array such that
    their sum is bigger than a specific target number
    please return the nunber of pairs
    Example:  numbers = [2,7,11,15],target = 24, return 1
    思路: sum的问题通常使用两个指针来解决排序数组
"""
class Solution(object):
    def twoSumGreat(self, nums, target):
        # 边界条件: 
        if not nums or len(nums) < 2:
            return 0
        # 排序nums
        nums.sort()
        # 两个指针
        left, right = 0, len(nums) - 1
        # 返回值
        count = 0
        while left < right:     #两数之和, 这两个数不可能重合
            if nums[left] + nums[right] < target:
                left += 1
            elif nums[left] + nums[right] >= target:
                # 说明此时left指向满足条件的第一个元素
                # (left, right),(left+1,right),(left+2,right)...都满足条件
                count += right - left
                # 注意: 继续获得所有的组合
                # 在right -= 1之后, left不可能在区间[0,left-1]
                right -= 1
        return count

if __name__ == "__main__":
    s = Solution()
    nums = [2,7,11,15]
    target = 24
    r = s.twoSumGreat(nums, target)
    print(r)


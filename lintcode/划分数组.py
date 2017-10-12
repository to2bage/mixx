"""
    31. http://www.lintcode.com/zh-cn/problem/partition-array/
    给出一个整数数组 nums 和一个整数 k。划分数组（即移动数组 nums 中的元素），使得：
        所有小于k的元素移到左边
        所有大于等于k的元素移到右边
        返回数组划分的位置，即数组中第一个位置 i，满足 nums[i] 大于等于 k。
    注意事项
        你应该真正的划分数组 nums，而不仅仅只是计算比 k 小的整数数，如果数组 nums 中的所有元素都比 k 小，则返回 nums.length。
    样例: 给出数组 nums = [3,2,2,1] 和 k = 2，返回 1.
"""
class Solution:
    """
    @param: nums: The integer array you should partition
    @param: k: An integer
    @return: The index after partition
    """
    def partitionArray(self, nums, k):
        # 边界条件
        if not nums or k < 0:
            return 0
        # 定义双指针
        left, right = 0, len(nums) - 1
        while left <= right:
            while left < right and nums[left] < k:
                left += 1
            while right >= left and nums[right] >= k:
                right -= 1
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        return left

if __name__ == "__main__":
    s = Solution()
    nums = [3,2,2,1]
    k = 2
    r = s.partitionArray(nums, k)
    print(r)

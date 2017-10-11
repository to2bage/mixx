"""
    http://www.lintcode.com/zh-cn/problem/subsets-ii/
    给定一个可能具有重复数字的列表，返回其所有可能的子集
    样例
        如果 S = [1,2,2]，一个可能的答案为：

        [
            [2],
            [1],
            [1,2,2],
            [2,2],
            [1,2],
            []
        ]
"""
class Solution:
    """
    @param: nums: A set of numbers.
    @return: A list of lists. All valid subsets.
    """
    def subsetsWithDup(self, nums):
        # write your code here
        self.rect = []
        self.dfs(sorted(nums), [], 0)
        return self.rect
    def dfs(self, nums, temp, startIndex):
        self.rect.append(temp[:])
        for i in range(startIndex, len(nums)):
            if i > startIndex and nums[i] == nums[i - 1]:
                continue
            temp.append(nums[i])
            self.dfs(nums, temp, i + 1)
            temp.pop()

if __name__ == "__main__":
    s = Solution()
    r = s.subsetsWithDup([1,2,2])
    print(r)
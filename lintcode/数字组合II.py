"""
    153: http://www.lintcode.com/zh-cn/problem/combination-sum-ii/
    给出一组候选数字(C)和目标数字(T),找出C中所有的组合，使组合中数字的和为T。C中每个数字在每个组合中只能使用一次。
    注意事项
            所有的数字(包括目标数字)均为正整数。
            元素组合(a1, a2, … , ak)必须是非降序(ie, a1 ≤ a2 ≤ … ≤ ak)。
            解集不能包含重复的组合。
    样例
            给出一个例子，候选数字集合为[10,1,6,7,2,1,5] 和目标数字 8  ,
            解集为：[[1,7],[1,2,5],[2,6],[1,1,6]]
    思路: 与数字组合.py的区别就是不能重复多次的使用一个元素呢
"""
class Solution:
    """
    @param: num: Given the candidate numbers
    @param: target: Given the target number
    @return: All the combinations that sum to target
    """
    def combinationSum2(self, nums, target):
        # edge
        if not nums or target < 0:
            return []
        # 返回的结果集
        self.rect = []
        self.dfs(sorted(nums), target, [], 0)
        return self.rect
    def dfs(self, nums, target, tmp, startIndex):
        if target == 0:
            self.rect.append(tmp[:])
            return
        if target < 0:
            return
        for i in range(startIndex, len(nums)):
            # 去重
            if i > startIndex and nums[i] == nums[i - 1]:
                continue
            tmp.append(nums[i])
            self.dfs(nums, target - nums[i], tmp, i + 1)
            tmp.pop()

if __name__ == "__main__":
    s = Solution()
    nums = [10,1,6,7,2,1,5]
    target = 8
    r = s.combinationSum2(nums, target)
    print(r)
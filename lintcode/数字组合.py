"""
    135: http://www.lintcode.com/zh-cn/problem/combination-sum/
    给出一组候选数字(C)和目标数字(T),找到C中所有的组合，使找出的数字和为T。C中的数字可以无限制重复被选取。
    注意事项
        所有的数字(包括目标数字)均为正整数。
        元素组合(a1, a2, … , ak)必须是非降序(ie, a1 ≤ a2 ≤ … ≤ ak)。
        解集不能包含重复的组合。
    样例
        给出候选数组[2,3,6,7]和目标数字7
        返回 [[7],[2,2,3]]
"""
class Solution:
    """
    @param: candidates: A list of integers
    @param: target: An integer
    @return: A list of lists of integers
    """
    def combinationSum(self, candidates, target):
        # 在python中, 在list前套一个set()就去重了, 然后再将其转换为list
        # 即, candidates = list(set(candidates))
        # 排序很重要, 否则会漏掉结果
        candidates.sort()
        self.rect = []      #最终返回的结果集
        self.dfs(candidates, target, [], 0)
        return self.rect
    # 以深度优先搜索的方法, 从startIndex位置开始探索candidates数组, 探索所有的可能性
    # 尝试将candidates[i]添加到tmp[]中, 或者不将candidates[i]添加到tmp[]中
    def dfs(self, candidates, target, tmp, startIndex):
        # 当证明是一个有效答案时, 将其添加到最终的结果集中
        if target == 0:
            self.rect.append(tmp[:])
            return
        # 因为target一直在做减法, 当证明不是一个有效答案, 并且target小于0时, 返回
        if target < 0:
            return
        # 从startIndex到candidates数组的最后一个元素, 探测每一个元素是否符合要求
        # 注意: 递归的下标没有i+1, 说明可以重复使用当前元素很多次
        for i in range(startIndex, len(candidates)):
            # 去除重复
            if i > startIndex and candidates[i] == candidates[i - 1]:
                continue
            tmp.append(candidates[i])
            self.dfs(candidates, target - candidates[i], tmp, i)
            # 回溯
            tmp.pop()

if __name__ == "__main__":
    s = Solution()
    candidates = [2,3,6,7]
    target = 7
    r = s.combinationSum(candidates, target)
    print(r)

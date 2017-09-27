class Solution:
    
    """
    @param: nums: A set of numbers
    @return: A list of lists
    """
    def subsets(self, nums):
        # write your code here
        ret = []        #返回的集合
        nums.sort()     #题目要求结果必须有序
        for i in range(len(nums) + 1):
            combs = self._subsets(nums, 0, i) #从第0个元素开始, 包含i个元素的子集
            for comb in combs:
                ret.append(comb)
        return ret

    def _subsets(self, numbers, pos, k):
            '''
            n = len(numbers) - pos
            if (not numbers) or (n < k):
                return None
            '''
            ret = []
            if k == 0:  # 0/1特殊情况处理
                return [[]]
            for i in range(pos, len(numbers), 1):
                combs = self._subsets(numbers, i + 1, k - 1)  # 计算i + 1开始位置，包含k - 1个元素的子集
                if combs:
                    if combs != [[]]:
                        for comb in combs:
                            new_comb = [numbers[i]]
                            new_comb.extend(comb)
                            ret.append(new_comb)
                    else:
                        ret.append([numbers[i]])
            return ret

    

nums = [1,2,3]
s = Solution()
r = s.subsets(nums)
print(r)

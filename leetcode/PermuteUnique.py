class Solution(object):
    def permuteUnique1(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.res = []
        def dfs(nums, temp):
            if len(temp) == len(nums):
                self.res.append(temp[:])    #这里一定是temp[:]深拷贝
                
            for i in range(len(nums)):
                if nums[i] in temp:
                    continue 
                temp.append(nums[i])
                dfs(nums, temp)
                temp.pop()
        dfs(nums, [])
        return self.res
    def permuteUnique(self, nums):
        self.res = []
        self.used = [False] * len(nums)
        def dfs(nums, temp):
            if len(temp) == len(nums):
                self.res.append(temp[:])
            for i in range(len(nums)):
                if self.used[i]:
                    continue
                if i > 0 and nums[i] == nums[i - 1] and self.used[i - 1]:
                    continue
                self.used[i] = True
                temp.append(nums[i])
                dfs(nums, temp)
                self.used[i] = False
                temp.pop()
        dfs(sorted(nums), [])
        #dfs(nums, [])
        return self.res
    

if __name__ == "__main__":
    s = Solution()
    r = s.permuteUnique([1,1,2])
    print(r)
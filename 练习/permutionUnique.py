class Solution(object):
    def permuteUnique(self, nums):
        self.rect = []
        self.used = [False] * len(nums)
        def dfs(nums, temp):
            if len(temp) == len(nums):
                self.rect.append(temp[:])
                return
            for i in range(0, len(nums)):
                if self.used[i]:
                    continue
                self.used[i] = True
                temp.append(nums[i])
                dfs(nums, temp)
                self.used[i] = False
                temp.pop()
        dfs(nums, [])
        return self.rect

if __name__ == "__main__":
    s = Solution()
    r = s.permuteUnique([1,2,3])
    print(r)

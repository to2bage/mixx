class Solution(object):
    def combinationSum(self, nums, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.res = []

        #temp: 
        def dfs(nums, temp, remainder, index):
            #Condition:
            if remainder == 0:
                self.res.append(temp[:]);
                return
            if remainder < 0:
                return
            for i in range(index, len(nums)):
                temp.append(nums[i])
                dfs(nums, temp, remainder - nums[i], i)
                temp.pop()
        dfs(nums, [], target, 0);
        return self.res;


if __name__ == "__main__":
    s = Solution();
    nums = [2,3,6,7]
    target = 7
    r = s.combinationSum(nums, target);
    print(r)


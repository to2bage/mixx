"""
    http://www.lintcode.com/zh-cn/problem/3sum/
    给出一个有n个整数的数组S，在S中找到三个整数a, b, c，找到所有使得a + b + c = 0的三元组。
     注意事项
            在三元组(a, b, c)，要求a <= b <= c。
            结果不能包含重复的三元组。
    样例
        如S = {-1 0 1 2 -1 -4}, 你需要返回的三元组集合的是：(-1, 0, 1) (-1, -1, 2)
"""
class Solution:
    """
    @param: numbers: Give an array numbers of n integer
    @return: Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        # write your code here
        #边界判断
        if not numbers or len(numbers) < 3:
            return []
        #各种sum问题, 首先sort
        numbers.sort()   #满足条件a <= b <= c
        result = []     #结果集
        length = len(numbers)
        #固定一个数, 变成求2sum的问题
        #注意: 因为是3个数的和, 所以区间是[0, length - 2)
        for i in range(0, length - 2):
            #如果连着几个num[i], num[i+1]...都一样的话, 就固定一个值
            if i > 0 and numbers[i] == numbers[i - 1]:
                continue
            target = -numbers[i]        #因为三个数的和为0
            #定义双指针, 左指针是从i+1开始的
            left, right = i + 1, length - 1
            while left < right:
                if numbers[left] + numbers[right] == target:
                    result.append([numbers[i], numbers[left], numbers[right]])
                    #因为要找出所有的组合, 继续改变左右指针
                    left += 1
                    right -= 1
                    #此时要继续判断是否有重复的元素
                    while left < right and numbers[left] == numbers[left - 1]:
                        left += 1
                    while left < right and numbers[right] == numbers[right + 1]:
                        right -= 1
                elif numbers[left] + numbers[right] > target:
                    right -= 1
                elif numbers[left] + numbers[right] < target:
                    left += 1
        return result

if __name__ == "__main__":
    s = Solution()
    numbers = [-1, 0, 1, 2, -1, -4]         # [-4, -1, -1, 0, 1, 2]
    r = s.threeSum(numbers)
    print(r)
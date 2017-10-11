"""
    http://www.lintcode.com/zh-cn/problem/two-sum/
    给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。
    你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。
    样例: 给出 numbers = [2, 7, 11, 15], target = 9, 返回 [1, 2].
    使用hash列表记录数组numbers的元素的下标
"""
class Solution:
    """
    @param: numbers: An array of Integer
    @param: target: target = numbers[index1] + numbers[index2]
    @return: [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        # write your code here
        if numbers is None or not numbers:
            return [-1,-1]
        hash = {}           #定义字典(键值对):用数组numbers中的元素表示键, 用数组numbers中元素的索引表示值
        for i in range(len(numbers)):
            if target - numbers[i] in hash:
                return [hash[target - numbers[i]] + 1, i + 1]
            hash[numbers[i]] = i
        return [-1, -1]

if __name__ == "__main__":
    s = Solution()
    numbers = [2,7,11,15]
    target = 9
    r = s.twoSum(numbers, target)
    print(r)

'''
    设计一个算法，找出只含素因子2，3，5 的第 n 小的数。符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12...
    样例:  如果n = 9， 返回 10
    思路:  第n小的数, 首先想到的是堆, python使用模块heapq实现了小堆的排序
          丑数的产生, 丑数 乘以 丑数 == 丑数
'''
class Solution:
    """
    @param: n: An integer
    @return: the nth prime number as description.
    """
    def nthUglyNumber(self, n):
        # write your code here
        if n <= 1:
            return n
        factors = [2,3,5]               #丑数的因子
        heap = factors + [1]            #记录结果
        import heapq
        heapq.heapify(heap)             #此时列表是小堆排序状态: heap = [1,2,5,3]
        while n > 1:
            uglyNumber = heapq.heappop(heap)  #弹出堆顶元素
            for factor in factors:
                tmp = uglyNumber * factor
                if tmp not in heap:
                    heapq.heappush(heap, tmp)
            n -= 1                      #表示每次循环,从堆中弹出一个元素
        return heapq.heappop(heap)

if __name__ == "__main__":
    s = Solution()
    r = s.nthUglyNumber(9)
    print(r)
                
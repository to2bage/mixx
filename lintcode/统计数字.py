'''
    计算数字k在0到n中的出现的次数，k可能是0~9的一个值
    样例
        例如n=12，k=1，在 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]，我们发现1出现了5次 (1, 10, 11, 12)
'''
class Solution:
    """
    @param: : An integer
    @param: : An integer
    @return: An integer denote the count of digit k in 1..n
    """

    def digitCounts(self, k, n):
        # write your code here
        assert(n >= 0 and 0 <= k <= 9)
        count = 0   #记录k出现的次数
        for i in range((n + 1)):        #[0, n]
            tmp = i
            while True:
                if tmp % 10 == k:
                    count += 1
                tmp //= 10
                if tmp == 0:
                    break
        return count

if __name__ == "__main__":
    s = Solution()
    #r = s.digitCounts(1, 12)
    r = s.digitCounts(0, 19)
    print(r)

'''
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
'''
"""
    http://www.lintcode.com/zh-cn/problem/find-peak-element/
    你给出一个整数数组(size为n)，其具有以下特点：
                相邻位置的数字是不同的
                A[0] < A[1] 并且 A[n - 2] > A[n - 1]
                假定P是峰值的位置则满足A[P] > A[P-1]且A[P] > A[P+1]，返回数组中任意一个峰值的位置。
    注意事项:
    It's guaranteed the array has at least one peak.
    The array may contain multiple peeks, find any of them.
    The array has at least 3 numbers in it.
    样例: 给出数组[1, 2, 1, 3, 4, 5, 7, 6]返回1, 即数值 2 所在位置, 或者6, 即数值 7 所在位置.
"""
class Solution:
    """
    @param: A: An integers array.
    @return: return any of peek positions.
    """
    def findPeak(self, A):
        # 边界条件
        if not A or len(A) < 3:
            return 0
        # 局部的峰值不可能出现在数组A的第一个和最后一个元素上
        left, right = 1, len(A) - 2
        while left + 1 < right:
            mid = left + (right - left) // 2
            #假如mid处是单调递增的, 根据题目提示A[n - 2] > A[n - 1], 数组最右侧是单调递减的, 所以峰值在mid的右侧
            if A[mid] < A[mid + 1]:
                left = mid
            #假如mid处是单调递减的, 根据题目提示A[0] < A[1], 数组最左侧是单调递增的, 所以峰值在mid的左侧
            elif A[mid] < A[mid - 1]:
                right = mid
            #假如mid处满足条件, 则直接返回峰值的索引
            elif A[mid] > A[mid - 1] and A[mid] < A[mid + 1]:
                return mid
            #假如遇到相等的情况
            else:
                left = mid
        #while循环结束于只有2个元素时
        return left if A[left] > A[right] else right
                
if __name__ == "__main__":
    s = Solution()
    A = [1,2,1,3,4,5,7,6]
    r = s.findPeak(A)
    print(r)
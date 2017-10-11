"""
    http://www.lintcode.com/zh-cn/problem/search-a-2d-matrix/
    写出一个高效的算法来搜索 m × n矩阵中的值。
    这个矩阵具有以下特性：
                        每行中的整数从左到右是排序的。
                        每行的第一个数大于上一行的最后一个整数

    样例
        考虑下列矩阵：

        [
            [1, 3, 5, 7],
            [10, 11, 16, 20],
            [23, 30, 34, 50]
        ]
    思路: 将矩阵线性化: [1,3,5,7,10,11,16,20,23,30,34,50]
"""
class Solution:
    """
    @param: matrix: matrix, a list of lists of integers
    @param: target: An integer
    @return: a boolean, indicate whether matrix contains target
    """
    def searchMatrix(self, matrix, target):
        # write your code here
        if len(matrix) == 0:
            return False
        #获得矩阵的行数rows和列数cols
        rows, cols = len(matrix), len(matrix[0])
        start = 0   #定义线性化后的列表的起始索引
        end = rows * cols - 1   #定义线性化后的列表的最后一个元素的索引
        #首先判断target是否在start和end位置上
        if matrix[start // cols][start % cols] == target:
            return True
        if matrix[end // cols][end % cols] == target:
            return True
        #判断其他位置是否包含target
        while start <= end:
            mid = (start + end) // 2
            if matrix[mid // cols][mid % cols] > target:
                end = mid - 1
            elif matrix[mid // cols][mid % cols] < target:
                start = mid + 1
            else:
                return True
        
        return False

if __name__ == "__main__":
    s = Solution()
    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
    r = s.searchMatrix(matrix, 50)
    print(r)
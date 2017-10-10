'''
    在数组中找到第k大的元素
    样例
        给出数组 [9,3,2,4,8]，第三大的元素是 4
        给出数组 [1,2,3,4,5]，第一大的元素是 5，第二大的元素是 4，第三大的元素是 3，以此类推
    思路: 第k大元素, 使用堆排序完成
'''
class Solution:
    def kthLargestElement(self, n, nums):
        import heapq
        heap = []
        for i in range(len(nums)):
            heapq.heappush(heap, nums[i])
            if i >= n:
                heapq.heappop(heap)
        return heap[0]

if __name__ == "__main__":
    s = Solution()
    r = s.kthLargestElement(3, [9,3,2,4,8])
    print(r)
    r = s.kthLargestElement(3, [1,2,3,4,5])
    print(r)

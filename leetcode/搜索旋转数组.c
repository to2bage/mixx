#include <stdio.h>
#include <stdlib.h>
//完美
int binSearch(int *nums, int start, int end, int target)
{
    int left = start;
    int right = end;
    int mid = 0;

    while(left < right)
    {
        mid = (left + right) / 2;
        if(target > nums[mid])
        {
            left = mid + 1;
        }
        else if(target < nums[mid])
        {
            right = mid - 1;
        }
        else if(target == nums[mid])
        {
            return mid;
        }
    }
    return nums[left] == target ? left : -1;      //没有找到
}

int search(int* nums, int numsSize, int target) 
{
    if(nums == NULL || numsSize <= 0)
    {
        return -1;
    }
    if(numsSize == 1)
    {
        return nums[0] == target ? 0 : -1;
    }
    //找到拐点, 即数组nums的最小值, 显然最小值在旋转区间内
    int start = 0;
    int end = numsSize - 1;
    int mid = 0;
    while(start < end)
    {
        mid = (start + end) / 2;
        if(nums[mid] < nums[end])
        {
            end = mid;
        }
        else if(nums[mid] > nums[end])
        {
            start = mid + 1;
        }
    }
    //此时start指向数组nums最小值的索引
    printf("nums[%d] = %d\n", start, nums[start]);
    if(nums[start] == target)
    {
        return start;
    }
    else if(target >= nums[0] && target <= nums[start - 1] && start - 1 >= 0)
    {
        return binSearch(nums, 0, start - 1, target);
    }
    else if(target >= nums[start + 1] && target <= nums[numsSize - 1] && start + 1 <= numsSize - 1)
    {
        return binSearch(nums, start + 1, numsSize - 1, target);
    }
    else
    {
        return -1;
    }

    return start;
}

int search1(int *nums, int numsSize, int target)
{
    if(nums == NULL || numsSize <= 0)
    {
        return -1;
    }

    int start = 0;
    int end = numsSize - 1;
    int mid = 0;
    while(start < end)
    {
        mid = (start + end) / 2;
        if(nums[mid] < nums[end])
        {
            end = mid;
        }
        else if(nums[mid] > nums[end])
        {
            start = mid + 1;
        }
    }
    return start;
}

int main(int argc, char *argv[])
{
    {
        
        //int nums[] = {4,5,6,7,0,1,2};
        //int nums[] = {6,7,0,1,2,4,5};
        //int nums[] = {1};
        //int nums[] = {1,3};
        int nums[] = {3,1};
        int numsSize = sizeof(nums) / sizeof(int);
        int target = 0;
        int rect = search(nums, numsSize, target);
        printf("rect = %d\n", rect);
        
    }
    {
        /*
        //test binsearch
        //int nums[] = {0,1,2,4,5,6,7};
        int nums[] = {1,3};
        int numsSize = sizeof(nums) / sizeof(int);
        int idx = binSearch(nums, 0, numsSize - 1, 0);
        printf("idx = %d\n", idx);
        */
    }

    return 0;
}
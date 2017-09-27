#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) 
{
    if(target < nums[0])
    {
        return 0;
    }
    if(target > nums[numsSize - 1])
    {
        return numsSize;
    }
    int start = 0;
    int end = numsSize - 1;
    int mid = 0;

    while(start < end)
    {
        mid = (start + end) / 2;
        if(nums[mid] > target)
        {
            end = mid - 1;
        }
        else if(nums[mid] < target)
        {
            start = mid + 1;
        }
        else if(nums[mid] == target)
        {
            return mid;
        }
    }
    printf("start = %d\n", start);
    return target > nums[start] ? start + 1 : start;
}

int main(int argc, char *argv[])
{
    //int nums[] = {1,3,5,6};
    int nums[] = {1,3,5,8,9};
    int numsSize = sizeof(nums) / sizeof(int);
    //int target = 5;             //2
    int target = 2;             //1
    //int target = 7;             //4
    //int target = 0;            //0
    //int target = 7;

    int ret = searchInsert(nums, numsSize, target);
    printf("ret = %d\n", ret);
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void nextPermutation(int* nums, int numsSize) 
{
    //idx指向要交换的元素索引
    int idx = numsSize - 1;
    for(; idx > 0; idx--)
    {
        if(nums[idx - 1] >= nums[idx])              //注意是nums[idx-1] >= nums[idx]
        {
            continue;
        }
        else
        {
            break;
        }
    }
    if(idx == 0)
    {
        //直接reverse
        int *pstart = nums + idx;
        int *pend = nums + numsSize - 1;
        //printf("*pstart = %d, *pend = %d\n", *pstart, *pend);
        while(pstart < pend)
        {
            int tmp = *pstart;
            *pstart = *pend;
            *pend = tmp;
            ++pstart;
            --pend;
        }
        return;
    }
    else
    {
        idx -= 1;
    }
    printf("idx = %d\n", idx);
    //[idx + 1, numsSize - 1]区间之间的大于nums[idx], 且是区间中最小的值
    int min = INT_MAX;
    int min_idx = 0;
    for(int i = idx + 1; i <= numsSize - 1; i++)
    {
        if(nums[i] <= min && nums[i] > nums[idx])               //注意: nums[i] <= min
        {
            min = nums[i];
            min_idx = i;
        }
    }
    //swap(min_idx, idx)
    int tmp = nums[idx];
    nums[idx] =  nums[min_idx];
    nums[min_idx] = tmp;
    //reverse区间[idx + 1, numsSize - 1]
    int *pstart = nums + idx + 1;
    int *pend = nums + numsSize - 1;
    while (pstart <= pend)
    {
        int tmp = *pstart;
        *pstart = *pend;
        *pend = tmp;
        ++pstart;
        --pend;
    }
}

int main(int argc, char *argv[])
{
    //int nums[] = {1,2,3};
    //int nums[] = {1,1,5};
    //int nums[] = {3,2,1};
    //int nums[] = {1};
    //int nums[] = {5,1,1};
    int nums[] = {2,3,1,3,3};
    int numsSize = sizeof(nums) / sizeof(int);
    nextPermutation(nums, numsSize);
    for(int i = 0; i < numsSize; i++)
    {
        printf("%3d", nums[i]);
    }
    printf("\n");

    return 0;
}
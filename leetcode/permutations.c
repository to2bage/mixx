#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//求[idx...numsSize-1]的全排列
void process(int *nums, int numsSize, int idx)
{
    if(idx >= numsSize)
    {
        for(int i = 0; i < numsSize; i++)
        {
            printf("%4d", nums[i]);
        }
        printf("\n");
        return;
    }

    for(int i = idx; i < numsSize; i++)
    {
        int tmp = nums[idx];
        nums[idx] = nums[i];
        nums[i] = tmp;

        process(nums, numsSize, idx + 1);

        tmp = nums[idx];
        nums[idx] = nums[i];
        nums[i] = tmp;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) 
{
    if(nums == NULL || numsSize <= 0)
    {
        return NULL;
    }

    
    process(nums, numsSize, 0);
    return NULL; 
}

int main(int argc, char *argv[])
{
    int nums[] = {1,1,3};
    int returnSize = 0;
    permuteUnique(nums, sizeof(nums)/sizeof(int), &returnSize);

    return 0;
}
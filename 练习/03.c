#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

int isDuplicate(int *nums, int start, int end)
{
    for(int i = start; i < end; i++)
    {
        if(nums[i] == nums[end])
        {
            return 1;
        }
    }
    return 0;
}

void process(int idx, int *nums, int numsSize, int **pp)
{
    if(idx >= numsSize)
    {
        //
        for(int i = 0; i < numsSize; i++)
        {
            printf("%3d", nums[i]);
        }
        printf("\n");
        return;
    }

    for(int i = idx; i < numsSize; i++)
    {
        if(isDuplicate(nums, idx, i) == 0)
        {
            int tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;
    
            process(idx + 1, nums, numsSize, pp);
    
            tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;
        }
    }
}

int **subset(int *nums, int numsSize, int *rows)
{
    if(nums == NULL || numsSize <= 0)
    {
        return NULL;
    }

    cnt = 0;
    int **pp = (int **)malloc(1000 * sizeof(int *));
    process(0, nums, numsSize, pp);
    return pp;
}

int main(int argc, char *argv[])
{
    int nums[] = {1,2,2,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int rows = 0;
    int **pprect = subset(nums, numsSize, &rows);

    

    return 0;
}
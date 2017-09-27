#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m = 9, n = 3;       //从5位数中, 取出3位进行排列
int source[] = {1,2,3,4,5,6,7,8,9};
int data[10] = {0};

void print(int level)
{
    if(level >= n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%3d", data[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < m; i++)
    {
        data[level] = source[i];
        print(level + 1);
    }
}

int cnt = 0;
void permutation(int level, int *nums, int numsSize, int count, int *data)
{
    if(level == count)
    {
        //show
        for(int i = 0; i < count; i++)
        {
            printf("%3d", data[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < numsSize; i++)
    {
        data[level] = nums[i];
        permutation(level + 1, nums, numsSize, count, data);
    }
}

int main(int argc, char *argv[])
{
    {
        //print(0);
    }
    {
        int nums[] = {1,2,3,4,5,6,7,8,9};
        int numsSize = sizeof(nums) / sizeof(int);
        int count = 3;
        int *data = (int *)malloc(count * sizeof(int));
        memset(data, 0, count * sizeof(int));
        permutation(0, nums, numsSize, count, data);
    }

    return 0;
}
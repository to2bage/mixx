#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

bool containsDuplicate(int* nums, int numsSize) 
{
    if(nums == NULL || numsSize <= 0)
    {
        return false;
    }
    if(numsSize == 1)
    {
        return false;
    }
    
    int **map = (int **)malloc(INT_MAX * sizeof(int *));
    for(int i = 0; i < INT_MAX; i++)
    {
        map[i] = NULL;
    }
    int flag = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(map[abs(nums[i])] == NULL)
        {
            int *px = (int *)malloc(2 * sizeof(int));       //px[0]存放正数的个数, px[1]存放负数的个数
            memset(px, 0, 2 * sizeof(int));
            map[abs(nums[i])] = px;
        }
        
        nums[i] >= 0 ? ++(map[abs(nums[i])][0]) : ++(map[abs(nums[i])][1]);
        
        if(map[abs(nums[i])][0] > 1 || map[abs(nums[i])][1] > 1)
        {
            //return true;
            flag = 1;
            break;
        }
        
    }
    //用于测试
    /*
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            if(map[row])
            {
                printf("%3d ):", row);
                printf("%4d", map[row][col]);
            }
        }
        printf("\n");
    }
    */
    for(int i = 0; i < INT_MAX; i++)
    {
        if(map[i])
        {
            free(map[i]);
        }
    }
    free(map);

    return flag == 0 ? false : true;
}

bool containsDuplicate1(int* nums, int numsSize) 
{
    if(nums == NULL || numsSize <= 0)
    {
        return false;
    }
    
    int **map = (int **)malloc(numsSize * sizeof(int *));
    for(int i = 0; i < numsSize; i++)
    {
        map[i] = NULL;
    }
    int flag = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(map[i] == NULL)
        {
            int *px = (int *)malloc(2 * sizeof(int));       //px[0]存放正数的个数, px[1]存放负数的个数
            memset(px, 0, 2 * sizeof(int));
            map[i] = px;
        }
        
        nums[i] >= 0 ? ++(map[i][0]) : ++(map[i][1]);
        
        if(map[i][0] > 1 || map[i][1] > 1)
        {
            //return true;
            flag = 1;
            break;
        }
        
    }
    //用于测试
    
    for(int row = 0; row < numsSize; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            if(map[row])
            {
                printf("%3d ):", row);
                printf("%4d", map[row][col]);
            }
        }
        printf("\n");
    }
    

    return flag == 0 ? false : true;
}

int main(int argc, char *argv[])
{
    int nums[] = {-6, -6};
    //int nums[] = {-1200000005,-1200000005};
    int numsSize = sizeof(nums) / sizeof(int);
    bool br = containsDuplicate(nums, numsSize);
    printf("br = %d\n", br);

    return 0;
}

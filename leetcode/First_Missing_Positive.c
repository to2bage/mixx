#include <stdio.h>
#include <stdlib.h>

//这种写法, 对于数组nums中没有重复的数字是可以的
int firstMissingPositive1(int* nums, int numsSize) 
{
    if(nums == NULL || numsSize <= 0)
    {
        return 1;
    }

    nums--;
    int i = 1;
    while(i <= numsSize)
    {
        if(nums[i] < i || nums[i] > numsSize)
        {
            nums[i] = nums[numsSize];
            numsSize--;
        }
        else if(nums[i] > i /*&& nums[i] != nums[nums[i]]*/)
        {
            //交换nums[i] 和 nums[nums[i]]的值
            int tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;
        }
        else if(nums[i] == i)
        {
            i++;
        }
        
    }
    return i;
}

int firstMissingPositive(int* nums, int numsSize) 
{
    if(nums == NULL || numsSize <= 0)
    {
        return 1;
    }

    nums--;
    int i = 1;
    while(i <= numsSize)
    {
        if(nums[i] < i || nums[i] > numsSize)
        {
            nums[i] = nums[numsSize];
            numsSize--;
        }
        else if(nums[i] > i)
        {
            if(nums[i] == nums[nums[i]])
            {
                nums[i] = nums[numsSize];
                numsSize--; 
            }
            else
            {
                //交换nums[i] 和 nums[nums[i]]的值
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        else if(nums[i] == i)
        {
            i++;
        }
        
    }
    return i;
}

int main(int arg, char *argv[])
{
    int nums[] = {1,2,0};                 //3
    //int nums[] = {3,4,-1,1};              //2
    //int nums[] = {3,5,1,2,-3,7,14,8};     //4
    //int nums[] = {3,5,2,1,-3,5,8};        //4
    //int nums[] = {2,2};                   //1
    //int nums[] = {5,5,5,5};               //1
    //int nums[] = {5,5,5,5,5};            //1
    //int nums[] = {5,5,5,5,5,5,5,5,5,5,5};   //1
    //int nums[] = {3,3,1,4,0};           //2
    //int nums[] = {0,2,2,4,0,1,0,1,3};       //5
    int numsSize = sizeof(nums) / sizeof(int);
    int missing_number = firstMissingPositive(nums, numsSize);
    printf("missing_number = %d\n", missing_number);

    return 0;
}
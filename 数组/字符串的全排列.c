#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Permutation(int idx, int *arr, int sz)
{
    if(idx >= sz)
    {
        //打印
        for(int i = 0; i < sz; i++)
        {
            printf("%4d", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = idx; i < sz; i++)
    {
        //交换
        int tmp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = tmp;

        Permutation(idx + 1, arr, sz);

        //返回现场
        tmp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = tmp;
    }
}

int isDuplication(int *arr, int start, int end)
{
    //[start, end)
    for(int i = start; i < end; i++)
    {
        if(arr[end] == arr[i])
        {
            return 1;       //有重复
        }
    }
    return 0;       //没有重复
}

void PermutationDup(int idx, int *arr, int sz)
{
    if(idx == sz - 1)
    {
        for(int i = 0; i < sz; i++)
        {
            printf("%4d", arr[i]);
        }
        printf("\n");
    }

    for(int i = idx; i < sz; i++)
    {
        //判断arr[i]与arr[idx, i)中是否有重复的
        //有重复的就不需要交换和下一层的递归
        //没有重复的就继续
        //为什么要与idx索引开始的元素比较, 因为idx的索引位置是要交换的开始位置
        if(isDuplication(arr, idx, i) == 0)
        {
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;

            PermutationDup(idx + 1, arr, sz);

            tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
}

void PermutationDup1(int idx, int *arr, int sz)
{
    if(idx == sz - 1)
    {
        for(int i = 0; i < sz; i++)
        {
            printf("%4d", arr[i]);
        }
        printf("\n");
    }

    int dup[256] = {0};   //动态的,每一次的PermutationDup1调用都是不一样的
    for(int i = idx; i < sz; i++)
    {
        if(dup[arr[i]] == 1)
        {
            continue;
        }
        dup[arr[i]] = 1;
        int tmp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = tmp;

        PermutationDup1(idx + 1, arr, sz);

        tmp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = tmp;
    }
}

int main(int argc, char *argv[])
{
    {
        
        //没有重复的数字
        int arr[] = {1,2,3,4};
        int size = sizeof(arr)/sizeof(int);
        Permutation(0, arr, size);
        
    }
    {
        /* 
        //有重复的数字
        int arr[] = {1,2,2,3};
        int size = sizeof(arr)/sizeof(int);
        PermutationDup(0, arr, size);
        */
    }
    {
        /*
        //有重复的数字
        int arr[] = {1,2,2,3};
        int size = sizeof(arr)/sizeof(int);
        PermutationDup1(0, arr, size);
        */
    }

    return 0;
}
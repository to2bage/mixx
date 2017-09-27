/*
    给定一个数组A[0..N-1], 找到从1开始, 第一个不在数组中的正整数
    如: 3, 5, 1, 2, -3, 7, 14, 8 输出4

    假定前i-1个数已经找到了, 并且依次存放于A[1,2,3...,i-1]中, 继续考察A[i]:
    1. 若A[i] < i 且 A[i] >= 1, 则A[i]在A[1,2...i-1]中已经出现过了, 可以直接丢弃; 如果A[i]为负值, 可以直接丢弃;
    2. 若A[i] > i 且 A[i] < N, 则A[i]应该位于后面的位置上, 则将A[A[i]]和A[i]交换
        如果A[i] >= N, 则直接丢弃
    3. 若A[i] == i, 则A[i]位于正确的位置上, 则i++, 继续后面的代码
*/

#include <stdio.h>
#include <stdlib.h>

int MissingNumber(int *arr, int sz)
{
    int i = 0;
    while(i <= sz)
    {
        if(arr[i] > i+1 && arr[i] < sz)
        {
            int tmp = arr[i];
            arr[i] = arr[tmp - 1];
            arr[tmp - 1] = tmp;
        }
        else if(arr[i] < i+1 || arr[i] > sz)
        {
            //丢弃
            arr[i] = arr[sz - 1];
            --sz;
        }
        else if(arr[i] == i+1)
        {
            ++i;
        }
        //test
        for(int i = 0; i < sz; i++)
        {
            printf("%3d", arr[i]);
        }
        printf("\n");
    }
    return i + 1;
}

int FirstMissNumber(int *arr, int sz)
{
    arr--;
    int i = 1;
    while(i <= sz)
    {
        if(arr[i] < i || arr[i] > sz)
        {
            arr[i] = arr[sz];
            sz--;
        }
        else if(arr[i] > i)
        {
            /*
            int tmp = arr[i];
            arr[i] = arr[arr[i]];
            arr[arr[i]] = tmp;
            */
            //int k = arr[i];
            int tmp = arr[i];
            arr[i] = arr[tmp];
            arr[tmp] = tmp;

        }
        else if(arr[i] == i)
        {
            i++;
        }
        //test
        printf("sz = %d\n", sz);
        for(int i = 0; i < sz; i++)
        {
            printf("%3d", arr[i]);
        }
        printf("\n");
    }
    return i;
}

int main(int argc, char *argv[])
{
    int arr[] = {3,5,1,2,-3,7,14,8};
    int size = sizeof(arr)/sizeof(int);
    //int r = MissingNumber(arr, size);
    int r = FirstMissNumber(arr, size);
    printf("%4d\n", r);

    return 0;
}
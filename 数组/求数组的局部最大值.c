/*
    给定一个无重复元素的数组A[0..N-1], 求找到一个该数组的局部最大值,即大于前后的值
    规定: 在数组边界外的值无穷小. 即A[0] > A[-1], A[N-1] > A[N]
    显然遍历一遍能找到全局的最大值, 而全局的最大值显然也是局部的最大值
    显然一个数组中的局部最大值可能不止一个: 4, 76, 32, 6, 34, 3中的局部最大值是76(也是全局最大值)和34

    根据规定, 数组A[]就是一个"高原数组"
    使用索引left, right分别指向数组的首尾
    求重点mid = (left + right) / 2;
    如果, A[mid] > A[mid + 1]  ===>  A[left, mid]是高原数组
    如果, A[mid] > A[mid - 1] ===>  A[mid, right]是高原数组
    一直循环到left == right;
*/

#include <stdio.h>
#include <stdlib.h>

int MaxOfPart(int *arr, int sz)
{
    int left = 0;
    int right = sz - 1;
    int mid = 0;

    while(left < right)
    {
        mid = (left + right) / 2;
        if(arr[mid] > arr[mid + 1])
        {
            right = mid;
        }
        else if(arr[mid] > arr[mid - 1])
        {
            left = mid;
        }
    }
    return arr[left];
}

int main(int argc, char *argv[])
{
    int arr[] = {4, 76,32, 6, 34, 3};
    int r = MaxOfPart(arr, sizeof(arr)/sizeof(int));
    printf("%d\n", r);

    return 0;
}
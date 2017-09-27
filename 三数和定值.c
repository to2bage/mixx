#include <stdio.h>
#include <stdlib.h>

//数组中三个数和为定值: aim:定值, count:几个数之和
void threeSum(int *arr, int size, int aim, int count)
{
    for(int i = 0; i <= size - count; i++)
    {
        for(int j = i + 1; j <= size - count + 1; j++)
        {
            int ret = aim - (arr[i] + arr[j]);
            for(int k = j + 1; k <= size - 1; k++)
            {
                if(arr[k] == ret)
                {
                    printf("(%4d,%4d,%4d) ", arr[i], arr[j], arr[k]);
                    break;
                }
            } 
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {-1, 0, 1, 2, -1, -4};
    //int arr[] = {-1, 1, 0};
    int size = sizeof(arr)/sizeof(int);
    int count = 3;
    int aim = 0;
    threeSum(arr, size, aim, count);

    return 0;
}



//a b c d e f g h i j k l m n
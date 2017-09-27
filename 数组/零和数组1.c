#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node
{
    int idx;
    int val;
} Node;

int ZeroOfSum(int *arr, int sz, int *idx1, int *idx2)
{
    Node *dpnode = (Node *)malloc(sz * sizeof(Node));
    memset(dpnode, 0, sz * sizeof(Node));

    for(int i = 0; i < sz; i++)
    {
        if(i == 0)
        {
            dpnode[i].idx = i;
            dpnode[i].val = arr[i];
        }
        else
        {
            dpnode[i].idx = i;
            dpnode[i].val = dpnode[i - 1].val + arr[i];
        }
    }

    for(int i = 0; i < sz - 1; i++)
    {
        for(int j = 0; j < sz - i - 1; j++)
        {
            if(dpnode[j].val > dpnode[j + 1].val)
            {
                int tmp = dpnode[j].val;
                dpnode[j].val = dpnode[j + 1].val;
                dpnode[j + 1].val = tmp;

                tmp = dpnode[j].idx;
                dpnode[j].idx = dpnode[j + 1].idx;
                dpnode[j + 1].idx = tmp;
            }
        }
    }

    int min = INT_MAX;
    for(int i = 0; i < sz; i++)
    {
        if(abs(dpnode[i + 1].val - dpnode[i].val) < min)
        {
            min = abs(dpnode[i + 1].val - dpnode[i].val);
            *idx1 = dpnode[i].idx;
            *idx2 = dpnode[i + 1].idx;
        }
    }

    return min;    
}

int main(int argc, char *argv[])
{
    int arr[] = {1,-2,3,10,-4,7,2,-5};
    int idx1, idx2;
    int r = ZeroOfSum(arr, sizeof(arr)/sizeof(int), &idx1, &idx2);
    printf("sum = %d, idx1 = %d, idx2 = %d\n", r, idx1, idx2);

    return 0;
}
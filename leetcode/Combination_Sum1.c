#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int val;
    struct node *next;
} Node;

void append(Node **pphead, int val)
{
    Node *pnode = (Node *)malloc(sizeof(Node));
    pnode->val = val;
    pnode->next = NULL;

    if(*pphead == NULL)
    {
        *pphead = pnode;
    }
    else
    {
        Node *px = *pphead;
        while(px->next)
        {
            px = px->next;
        }
        px->next = pnode;
    }
}

int cnt = 0;

void process(int idx, int *candidatas, int candidatesSize, int target, int *data, int **result,
    int **columnSizes, int *returnSize)
{
    if(idx >= candidatesSize)
    {
        //
        if(target == 0)
        {
            int cols = 0;
            for(int i = 0; i < candidatesSize; i++)
            {
                if(data[i] != 0)
                {
                    cols += data[i] / candidatas[i];
                }
            }
            (*columnSizes)[cnt] = cols;
            int *px = (int *)malloc(cols * sizeof(int));
            memset(px, 0, cols * sizeof(int));
            int j = 0;
            for(int i = 0; i < candidatesSize; i++)
            {
                if(data[i] != 0)
                {
                    for(int k = 0; k < data[i] / candidatas[i]; k++)
                    {
                        px[j++] = candidatas[i];
                    }
                }
            }
            result[cnt] = px;
            cnt++;
        }
        return;
    }

    for(int i = 0; i * candidatas[idx] <= target; i++)
    {
        data[idx] = i * candidatas[idx];
        process(idx + 1, candidatas, candidatesSize, target - i * candidatas[idx], data, result, columnSizes, returnSize);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, 
    int** columnSizes, int* returnSize) 
{
    if(candidates == NULL || candidatesSize <= 0 || target <= 0)
    {
        return NULL;
    }
    cnt = 0;
    
    *columnSizes = (int *)malloc(100 * sizeof(int));
    memset(*columnSizes, 0, 100 * sizeof(int));
    
    int *data = (int *)malloc(candidatesSize * sizeof(int));
    memset(data, 0, candidatesSize * sizeof(int));

    int **result = (int **)malloc(1000 * sizeof(int *));
    process(0, candidates, candidatesSize, target, data, result, columnSizes, returnSize);
    *returnSize = cnt;
    return result;
}

int main(int argc, char *argv[])
{
    //int candidates[] = {2,3,6,7};
    //int candidates[] = {5,10,25,1};
    int candidates[] = {8,10,6,3,4,12,11,5,9};
    int candidatesSize = sizeof(candidates) / sizeof(int);
    int target = 28;
    int returnSize = 0;
    int *columnSizes = NULL;
    //int *columnSizes = (int *)malloc(100 * sizeof(int));
    //memset(columnSizes, 0, 100 * sizeof(int));

    int **pprect = combinationSum(candidates, candidatesSize, target, &columnSizes, &returnSize);
    for(int i = 0; i < returnSize; i++)
    {
        for(int j = 0; j < columnSizes[i]; j++)
        {
            printf("%3d", pprect[i][j]);
        }
        printf("\n");
    }

    return 0;
}
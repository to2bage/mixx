/*
    假定N个数的最大最小值为max, min. 则这N个数形成N - 1个间隔. 其最小值是(max - min)/(N - 1)
    1. 如果N个数完全均匀分布, 则间距全部是(max - min)/(N - 1),且最小
    2. 如果N个数不是均匀分布, 间距不均衡, 则最大间距必然大于(max - min)/(N - 1)

    思路:
        将N个数用间距(max - min)/(N - 1)分成N - 1个区间, 则落在同一个区间内的数不可能有最大间距.
        统计后一个区间的最小值与前一个区间的最大值的差即可.
        若没有任何的数据落在某个区间内, 则该区间无效.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct sbucket
{
    bool bValid;        //是否有值落在了桶内
    int nMin;
    int nMax;
}SBucket;

void Add(SBucket *sb, int n)     //将数n加入桶中
{
    if(sb->bValid == true)
    {
        if(n > sb->nMax)
        {
            sb->nMax = n;
        }
        else if(n < sb->nMin)
        {
            sb->nMin = n;
        }
    }
    else
    {
        sb->nMin = sb->nMax = n;
        sb->bValid = true; 
    }
}

int CalcMaxGap(int *arr, int size)
{
    SBucket *pBucket = (SBucket *)malloc(size * sizeof(SBucket));
    memset(pBucket, 0, size * sizeof(SBucket));
    //获得数组arr中的最大值和最小值
    int nMax = arr[0];
    int nMin = arr[0];
    int i = 0;
    for(i = 0; i < size; i++)
    {
        if(arr[i] > nMax)
        {
            nMax = arr[i];
        }
        if(arr[i] < nMin)
        {
            nMin = arr[i];
        }
    }
    printf("min = %d, max = %d\n", nMin, nMax);         //test
    //依次将数据放入桶中
    int delta = nMax - nMin;
    int nBucket;            //某个数放入哪个桶中
    for(int i = 0; i < size; i++)
    {
        nBucket = (arr[i] - nMin) * size / delta;
        if(nBucket >= size)
        {
            nBucket = size - 1;
        }
        Add(&pBucket[nBucket], arr[i]);
    }
    //显示桶数据                                         test
    for(int i = 0; i < size; i++)
    {
        SBucket sb = pBucket[i];
        printf("No.%d号桶: [%3d, %3d]\n", i, sb.nMin, sb.nMax);
    }
    //计算有效桶的间距
    int gap = delta / size;         //平均分配的最小间距
    int j = 0;                      //首个桶一定是有效的, 因为数组arr的最小值一定在首个桶中
    for(int i = 1; i < size; i++)
    {
        if(pBucket[i].bValid)
        {
            if(pBucket[i].nMin - pBucket[j].nMax > gap)
            {
                gap = pBucket[i].nMin - pBucket[j].nMax;
            }
            j = i;
        }
    }
    return gap;
}



int main(int argc, char *argv[])
{
    int arr[] = {1,7,14,9,4,13};
    int size = sizeof(arr)/sizeof(int);
    int r = CalcMaxGap(arr, size);
    printf("r = %d\n", r);

    return 0;
}
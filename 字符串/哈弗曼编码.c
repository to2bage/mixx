#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

typedef struct HuffmanNode
{
    int nWeight;
    int nleft;
    int nright;
    int nparent;

}HuffmanNode;

void CalcFrequency(char *str, int *pWeight)
{
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        pWeight[str[i]]++;
    }
}

void CalcExistChar(int *pWeight, int cnt, int *pChar, int *pCharCnt)
{
    int j = 0;
    int count = 0;
    for(int i = 0; i < cnt; i++)
    {
        if(pWeight[i] != 0)
        {
            pChar[j] = i;
            j++;
            if(i != count)
            {
                pWeight[count++] = pWeight[i];
            }
        }
    }
    *pCharCnt = j;
}

void SelectNode(HuffmanNode *huffmanTree, int n, int *s1, int *s2)
{
    int idx1 = 0;      //最小值的索引
    int idx2 = 0;      //第二小值的索引
    int nMin1 = 10000;
    int nMin2 = 10000;

    for(int i  =0; i < n; i++)
    {
        if(huffmanTree[i].nparent == 0)
        {
            if(huffmanTree[i].nWeight <= nMin1)
            {
                nMin2 = nMin1;
                nMin1 = huffmanTree[i].nWeight;
                *s2 = *s1;
                *s1 = i;
            }
            else if(huffmanTree[i].nWeight <= nMin2)
            {
                nMin2 = huffmanTree[i].nWeight;
                *s2 = i;
            }
        }
    }

}

void HuffmanCoding(int *pWeight, int cnt)
{
    if(cnt < 0)
    {
        return;
    }
    int m = 2 * cnt - 1;      //二叉树总共需要m个节点

    HuffmanNode *pHuffmanTree = (HuffmanNode *)malloc(m * sizeof(HuffmanNode));
    memset(pHuffmanTree, 0, m * sizeof(HuffmanNode));

    //leaf
    for(int i = 0; i < cnt; i++)
    {
        pHuffmanTree[i].nWeight = pWeight[i];
    }
    //每次选择权值最小的两个数建树
    int s1, s2;
    for(int i = cnt; i < m; i++)
    {
        SelectNode(pHuffmanTree, i, &s1, &s2);
        printf("s1 = %d, s2 = %d\n", s1, s2);           //test
        pHuffmanTree[i].nleft = s1;
        pHuffmanTree[i].nright = s2;
        pHuffmanTree[i].nparent = 0;
        pHuffmanTree[i].nWeight = pHuffmanTree[s1].nWeight + pHuffmanTree[s2].nWeight;
        pHuffmanTree[s1].nparent = i;
        pHuffmanTree[s2].nparent = i;
    }
    //show
    for(int i = 0; i < m; i++)
    {
        printf("=>wieght: %4d, =>left: %2d, =>right:%2d, =>parent: %2d\n", pHuffmanTree[i].nWeight, pHuffmanTree[i].nleft, pHuffmanTree[i].nright, pHuffmanTree[i].nparent);
    }

    //打印哈弗曼树
    int nParent;
    int curnode;
    for(int i = 0; i < cnt; i++)
    {
        curnode = i;
        nParent = pHuffmanTree[curnode].nparent;
        while(nParent)
        {
            if(pHuffmanTree[nParent].nleft == curnode)
            {
                printf("%2c", '0');
            }
            if(pHuffmanTree[nParent].nright == curnode)
            {
                printf("%2c", '1');
            }

            curnode = nParent;
            nParent = pHuffmanTree[curnode].nparent;
        }
        printf("\n");
    }
}



void showArry(int *arr, int cnt)
{
    for(int i = 0; i < cnt; i++)
    {
        printf("%4d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    //char str[] = "Planet Stories was an American pulp science fiction magazine, published by Fiction House between 1939 and 1955. It featured adventures in space and on other ";
    char str[] = "abcdabecdacabac";
    int pWeight[N] = {0};
    CalcFrequency(str, pWeight);
    //showArry(pWeight, N);                               //test
    
    int *pChar = (int *)malloc(N * sizeof(int));
    memset(pChar, 0, N * sizeof(int));
    int cnt = 0;        //pChar的长度
    CalcExistChar(pWeight, N, pChar, &cnt);
    pChar = realloc(pChar, cnt * sizeof(int));
    showArry(pWeight, cnt);                                 //test
    
    //printf("cnt = %d\n", cnt) ;                          //test


    HuffmanCoding(pWeight, cnt);

    return 0;
}
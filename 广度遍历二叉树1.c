#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
}TreeNode;

//获得二叉树的节点个数
int nodesOfTree(TreeNode *root)
{
    int left = 0, right = 0;
    if(root == NULL)
    {
        return 0;
    }
    if(root->left)
    {
        left = nodesOfTree(root->left);
    }
    if(root->right)
    {
        right = nodesOfTree(root->right);
    }

    return left + right + 1;
}


//二叉树广度遍历, 按层打印
void BFSOfTreeAndPrint(TreeNode *root, int size)
{
    if(root == NULL)
    {
        return;
    }
    //用数组实现队列
    TreeNode **pptreeNodes = (TreeNode **)malloc(size * sizeof(TreeNode *));
    int head = 0;
    int tail = 1; //不包括
    //将根节点入队
    pptreeNodes[head] = root;

    TreeNode *parentTreeNode = root;
    TreeNode *curTreeNode = NULL;
    TreeNode *lastTreeNode = root;
    
    while(head < tail)
    {
        curTreeNode = pptreeNodes[head];        //取出队首元素
        ++head;                                 //模拟取走对手元素
        printf("%3d", curTreeNode->val);
        //free(curTreeNode);
        //curTreeNode = NULL;


        if(curTreeNode->left)
        {
            pptreeNodes[tail] = curTreeNode->left;      //模拟实现入队
            tail++;
            lastTreeNode = curTreeNode->left;
        }
        if(curTreeNode->right)
        {
            pptreeNodes[tail] = curTreeNode->right;     //模拟实现入队
            tail++;
            lastTreeNode = curTreeNode->right;
        }

        if(parentTreeNode->right == lastTreeNode)
        {
            printf("\n");
            parentTreeNode = lastTreeNode;
        }
    }
    //printf("\n");           
}
  

int main(int argc, char *argv[])
{

    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 3;
    TreeNode *p1 = (TreeNode*)malloc(sizeof(TreeNode));
    p1->val = 9;
    p1->left = NULL;
    p1->right = NULL;
    TreeNode *p2 = (TreeNode*)malloc(sizeof(TreeNode));
    p2->val = 20;
    TreeNode *p3 = (TreeNode*)malloc(sizeof(TreeNode));
    p3->val = 15;
    p3->left = NULL;
    p3->right = NULL;
    TreeNode *p4 = (TreeNode*)malloc(sizeof(TreeNode));
    p4->val = 7;
    p4->left = NULL;
    p4->right = NULL;
   
    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;



    int size = nodesOfTree(root);
    BFSOfTreeAndPrint(root, size);
    return 0;
}
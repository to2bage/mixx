#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
}TreeNode;

typedef struct node
{
    TreeNode *treeNode;
    struct node *next;
}ListNode;

void enque(ListNode **pphead, TreeNode *treeNode)
{
    ListNode *pnode = (ListNode *)malloc(sizeof(ListNode));
    pnode->treeNode = treeNode;
    pnode->next = NULL;

    if(*pphead == NULL)
    {
        *pphead = pnode;
    }
    else
    {
        ListNode *px = *pphead;
        while(px->next)
        {
            px = px->next;
        }
        px->next = pnode;
    }
}

void deque(ListNode **pphead, TreeNode **ppTreeNode)
{
    if(*pphead == NULL)
    {
        *ppTreeNode = NULL;
    }
    else
    {
        *ppTreeNode = (*pphead)->treeNode;
        *pphead = (*pphead)->next;
    }
}

int isEmptyOfQue(ListNode *phead)
{
    return phead == NULL ? 0 : 1;   //0是空, 1是非空
}

void showQue(ListNode *phead)
{
    if(phead == NULL)
    {
        return;
    }

    ListNode *px = phead;
    while(px)
    {
        printf("%3d", px->treeNode->val);
        px = px->next;
    }
}

//二叉树的广度遍历(按层遍历)
void BFSOfTree(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    ListNode *phead = NULL;
    enque(&phead, root);
    TreeNode *parentTreeNode = root;
    TreeNode *curTreeNode = NULL;
    
    while(isEmptyOfQue(phead) == 1)
    {
        deque(&phead, &curTreeNode);        //取出队首元素
        printf("%3d", curTreeNode->val);
        //free(curTreeNode);
        //curTreeNode = NULL;

        if(curTreeNode->left)
        {
            enque(&phead, curTreeNode->left);
        }
        if(curTreeNode->right)
        {
            enque(&phead, curTreeNode->right);
        }
    }
}

//二叉树广度遍历, 按层打印
void BFSOfTreeAndPrint(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    ListNode *phead = NULL;
    enque(&phead, root);

    TreeNode *parentTreeNode = root;
    TreeNode *curTreeNode = NULL;
    TreeNode *lastTreeNode = root;
    
    while(isEmptyOfQue(phead) == 1)
    {
        deque(&phead, &curTreeNode);        //取出队首元素
        printf("%3d", curTreeNode->val);
        //free(curTreeNode);
        //curTreeNode = NULL;


        if(curTreeNode->left)
        {
            enque(&phead, curTreeNode->left);
            lastTreeNode = curTreeNode->left;
        }
        if(curTreeNode->right)
        {
            enque(&phead, curTreeNode->right);
            lastTreeNode = curTreeNode->right;
        }

        if(parentTreeNode->right == lastTreeNode)
        {
            printf("\n");
            parentTreeNode = lastTreeNode;
        }
    }
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

    //BFSOfTree(root);
    BFSOfTreeAndPrint(root);
    return 0;
}
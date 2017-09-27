#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//{"2", "2", "5", "#", "#", "5", "7"}
struct TreeNode *createBTree(struct TreeNode *root, char **ppstr, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        
    }
    
    return NULL;
}

void dfs(struct TreeNode *root, int min, int *ret)
{
    if(root != NULL)
    {
        if(root->val > min && root->val < *ret)
        {
            *ret = root->val;
        }
        else if(root->val == min)
        {
            dfs(root->left, min, ret);
            dfs(root->right, min, ret);
        }
    }
}

int findSecondMinimumValue(struct TreeNode* root) 
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return -1;
    }
    int min = root->val;
    int ret = INT_MAX;
    dfs(root, min, &ret);
    return ret < INT_MAX ? ret : -1;
}

int main(int argc, char *argv[])
{
    char *str[] = {"2", "2", "5", "#", "#", "5", "7"};
    int rows = sizeof(str)/sizeof(char *);
    struct TreeNode *root = NULL;
    root = createBTree(root, str, rows);
    
    //printf("sizeof(str) = %d\n", sizeof(str)/sizeof(char *));   //7
    return 0;
}
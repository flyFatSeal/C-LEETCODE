#include "tree.h";
#include <stdio.h>

//中序遍历模板，要带着答案数组ans，和显示答案长度的returnSize一起递归
void find(struct TreeNode *root, int *ans, int *returnSize)
{
    if (root == NULL)
        return NULL;
    find(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->val;
    find(root->right, ans, returnSize);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * 101);
    *returnSize = 0;
    find(root, ans, returnSize);
    return ans;
}

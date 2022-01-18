#include "tree.h";
#include <stdio.h>

bool dfs(struct TreeNode *left, struct TreeNode *right)
{
    if (left == NULL && right == NULL)
        return 1;
    if (left == NULL || right == NULL)
        return 0;
    if (left->val != right->val)
        return 0;
    return dfs(left->left, right->right) && dfs(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
    if (root == NULL)
        return 1;

    return dfs(root->left, root->right);
}

// stack
bool isSymmetricStack(struct TreeNode *root)
{
    /* 根节点为空，即对称 */
    if (root == NULL)
    {
        return true;
    }
    /* 创建队列，保存节点 */
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
    int head = 0, rear = 0;
    queue[rear++] = root->left;
    queue[rear++] = root->right;
    /* 迭代遍历二叉树 */
    while (head != rear)
    {
        struct TreeNode *left = queue[head++];
        struct TreeNode *right = queue[head++];
        /* 若两者都为空，则当前节点的左右孩子匹配，继续 */
        if (!left && !right)
        {
            continue;
        }
        /* 有一个为空另一个不为空，或者两者都不为空但是节点值不相等 */
        if (!left || !right || left->val != right->val)
        {
            return false;
        }
        /* 到这里则表示当前两节点匹配，再添加当前节点的左右节点入队列 */
        queue[rear++] = left->left;
        queue[rear++] = right->right;
        queue[rear++] = left->right;
        queue[rear++] = right->left;
    }
    return true;
}

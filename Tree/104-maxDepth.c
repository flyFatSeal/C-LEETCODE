#include "tree.h";
#include <stdio.h>

// 层序遍历
int maxDepth(struct TreeNode *root)
{
    /* 创建队列，保存节点 */
    if (root == NULL)
        return 0;
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
    int head, tail, deep = 0;
    queue[tail++] = root;
    while (head != tail)
    {
        int start = head;
        int end = tail;

        for (; start < end; start++)
        {
            struct TreeNode *left = queue[start]->left;
            struct TreeNode *right = queue[start]->right;
            if (left)
            {
                queue[tail++] = left;
            }
            if (right)
            {
                queue[tail++] = right;
            }
        }
        head = end;

        deep += 1;
    }

    return deep;
}
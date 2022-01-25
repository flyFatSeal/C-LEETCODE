#include "tree.h";
#include <stdio.h>

// 自底向上，每个子项先构建一个二叉搜索树，然后再添加父节点。
// 要点在如何挑选子项，尽量保证二叉树的平衡性，数组是升序，即中序遍历的结果。
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){

}
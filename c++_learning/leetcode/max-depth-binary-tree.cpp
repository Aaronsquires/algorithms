#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // If tree is empty then return 0
        if (root == NULL)
            return 0;

        else
        {
            //max returns the largest of a and b
            // get the max between the maxdepths of left and right
            // then add 1 to it to get the current node.
            // i.e. max_depth = max(max dept of left subtree, max depth of               // right subtree) + 1
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }
};
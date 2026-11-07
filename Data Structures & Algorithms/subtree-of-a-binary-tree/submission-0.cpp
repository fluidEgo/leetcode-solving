class Solution {
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;

        if (p == nullptr || q == nullptr || p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        // Fixed 'subroot' to 'subRoot' below:
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
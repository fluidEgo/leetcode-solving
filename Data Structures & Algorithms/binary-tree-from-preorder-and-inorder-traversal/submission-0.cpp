/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(const std::vector<int>& preorder,
                        const std::vector<int>& inorder) {
        std::unordered_map<int, int> inIndex;
        inIndex.reserve(inorder.size());
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            inIndex[inorder[i]] = i;
        }

        int preIdx = 0;
        return build(preorder, inIndex, preIdx, 0, static_cast<int>(inorder.size()));
    }

private:
    TreeNode* build(const std::vector<int>& preorder,
                    const std::unordered_map<int, int>& inIndex,
                    int& preIdx,
                    int lo,
                    int hi) {
        if (lo >= hi) {
            return nullptr;
        }

        int rootVal = preorder[preIdx++];
        auto* root = new TreeNode(rootVal);

        int mid = inIndex.at(rootVal);
        root->left  = build(preorder, inIndex, preIdx, lo, mid);
        root->right = build(preorder, inIndex, preIdx, mid + 1, hi);

        return root;
    }
};

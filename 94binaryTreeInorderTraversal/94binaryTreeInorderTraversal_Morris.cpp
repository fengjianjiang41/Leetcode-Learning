#include "../common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* predecessor = nullptr;

        while (root != nullptr){
            if (root->left != nullptr){
                predecessor=root->left;
                while (predecessor->right!=nullptr && predecessor->right!=root){
                    predecessor=predecessor->right;
                }
                if (predecessor->right==nullptr){
                    predecessor->right=root;
                    root=root->left;
                }
                else{
                    res.push_back(root->val);
                    predecessor->right=nullptr;
                    root=root->right;
                }
            }
            else{
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = s.inorderTraversal(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
#include "../common.h"
#include <queue>

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
    bool check(TreeNode* u, TreeNode* v) {
        queue <TreeNode*> q;
        q.push(u);q.push(v);
        while(!q.empty()){
            u = q.front();q.pop();
            v=q.front();q.pop();
            if(!u&&!v)continue;
            if((!u||!v)||(u->val!=v->val))return false;
            q.push(u->left);
            q.push(v->right);
            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

int main() {
    Solution s;
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->left = new TreeNode(4);
    p->right->right = new TreeNode(3);
    cout << s.isSymmetric(p) << endl;
    return 0;
}
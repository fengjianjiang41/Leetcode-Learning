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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }
        queue <TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);
        while (!queue1.empty() && !queue2.empty()) {
            auto node1 = queue1.front();
            queue1.pop();
            auto node2 = queue2.front();
            queue2.pop();
            if (node1->val != node2->val) {
                return false;
            }
            auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
            if ((left1 == nullptr) ^ (left2 == nullptr)) {
                return false;
            }
            if ((right1 == nullptr) ^ (right2 == nullptr)) {
                return false;
            }
            if (left1 != nullptr) {
                queue1.push(left1);
            }
            if (right1 != nullptr) {
                queue1.push(right1);
            }
            if (left2 != nullptr) {
                queue2.push(left2);
            }
            if (right2 != nullptr) {
                queue2.push(right2);
            }
        }
        return queue1.empty() && queue2.empty();
    }
};

int main() {
    Solution s;
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    cout << s.isSameTree(p, q) << endl;
    return 0;
}
#include "../common.h"
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*, hash<ListNode*>> seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> test = {3, 2, 0, -4};
    ListNode* head = createLinkedList(test);
    head->next->next->next->next = head->next;
    cout << s.hasCycle(head);
    return 0;
}
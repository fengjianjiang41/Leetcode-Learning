#include "../common.h"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dum = new ListNode(0);
        ListNode* cur = dum;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 != nullptr ? list1 : list2;
        return dum->next;
    }
};

ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    Solution s;
    vector<int> test1 = {1, 2, 4};
    vector<int> test2 = {1, 3, 4};
    ListNode* head1 = createLinkedList(test1);
    ListNode* head2 = createLinkedList(test2);
    ListNode* res = s.mergeTwoLists(head1, head2);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
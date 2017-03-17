#include <vector>
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        if (head == nullptr) { return nullptr; }

        ListNode dummy_lo = ListNode{-1};
        ListNode dummy_hi = ListNode{-1};
        ListNode* t1{&dummy_lo};
        ListNode* t2{&dummy_hi};
        ListNode* t3{head};

        while (t3 != nullptr) {
            if (t3->val < x) {
                t1->next = t3;
                if (t1->next) { t1 = t1->next; }
            } else {
                t2->next = t3;
                if (t2->next) { t2 = t2->next; }
            }
            t3 = t3->next;
        }
        t1->next = dummy_hi.next;
        t2->next = nullptr;
        return dummy_lo.next;
    }
};

int main()
{
    ListNode* head{new ListNode{1}};
    ListNode* tmp{head};
    std::vector<int> vals{4, 3, 2, 5, 2};
    for (auto i : vals) {
        tmp->next = new ListNode{i};
        tmp = tmp->next;
    }

    tmp = Solution{}.partition(head, 3);
    while (tmp != nullptr) {
        std::cout << tmp->val << " ";
        tmp = tmp->next;
    }

    return 0;
}
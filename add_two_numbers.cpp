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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head{new ListNode{0}};
        ListNode* t1{l1};
        ListNode* t2{l2};
        ListNode* t3{head};

        int carry{0};
        while (t1 != nullptr || t2 != nullptr) {
            int tmp{0};
            if (t1 != nullptr) {
                tmp += t1->val;
                t1 = t1->next;
            }
            if (t2 != nullptr) {
                tmp += t2->val;
                t2 = t2->next;
            }
            tmp += carry;
            carry = tmp >= 10 ? 1 : 0;
            t3->val = tmp % 10;
            if (t1 != nullptr || t2 != nullptr) {
                t3->next = new ListNode{0};
                t3 = t3->next;
            } else if (carry) {
                t3->next = new ListNode{carry};
                carry = 0;
            }
        }
        return head;
    }
};

int main()
{
    ListNode* d1{new ListNode{2}};
    d1->next = new ListNode{4};
    d1->next->next = new ListNode{3};

    ListNode* d2{new ListNode{5}};
    d2->next = new ListNode{6};
    d2->next->next = new ListNode{4};

    ListNode* sol{Solution{}.addTwoNumbers(d1, d2)};

    ListNode* tmp{sol};
    while (tmp != nullptr) {
        std::cout << tmp->val << " ";
        tmp = tmp->next;
    }

    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode dummy{0};
    ListNode* p{l1};
    ListNode* q{l2};
    ListNode* curr{&dummy};
    int carry{0};
    while (p != nullptr || q != nullptr) {
        int x{(p != nullptr) ? p->val : 0};
        int y{(q != nullptr) ? q->val : 0};
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode{sum % 10};
        curr = curr->next;
        if (p != nullptr) { p = p->next; }
        if (q != nullptr) { q = q->next; }
    }
    if (carry > 0) { curr->next = new ListNode(carry); }
    return dummy.next;
}
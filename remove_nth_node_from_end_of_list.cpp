struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        auto prev = head;
        auto current = head;

        for (; n >= 0; --n) { current = current->next; }
        while (current != nullptr) {
            prev = prev->next;
            current = current->next;
        }

        auto tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;

        return head;
    }
};

int main() {
    ListNode dummy{0};
    auto tmp = &dummy;
    for (int i{1}; i < 6; ++i) {
        tmp->next = new ListNode{i};
        tmp = tmp->next;
    }

    Solution{}.removeNthFromEnd(dummy.next, 2);
    return 0;
}
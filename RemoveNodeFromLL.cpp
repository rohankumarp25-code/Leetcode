/*
=========================================================
Problem: Remove Linked List Elements
Difficulty: Easy

My Approach:
- First removed all matching nodes from the beginning of the
  linked list by updating the head pointer.
- Traversed the remaining list using two pointers:
  - prev: last valid node
  - temp: current node
- When a node matched the target value, bypassed it by
  updating the previous node's next pointer.
- Otherwise, advanced both pointers.

Key Concept(s):
- Linked Lists
- Pointer Manipulation
- Two-Pointer Traversal
- In-place Deletion

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Removing nodes from the head requires special handling
  because the head pointer itself changes.
- Pointer order is important when modifying linked lists.
- AddressSanitizer helped identify a heap-use-after-free bug,
  reinforcing the importance of careful pointer management.

Revision Note:
1. Remove matching head nodes.
2. Initialize prev and temp pointers.
3. If current node matches the target, bypass it.
4. Otherwise, move both pointers forward.
5. Return the updated head.
=========================================================
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr || (head->next == nullptr && head->val == val))
            return nullptr;
        while (head->val == val) {
            // ListNode* m=head;
            head = head->next;
            if (head == nullptr)
                return nullptr;
            // delete m;
        }
        if (head == nullptr || (head->next == nullptr && head->val == val))
            return nullptr;
        if (head->next == nullptr && head->val != val)
            return head;
        ListNode* prev = head;
        ListNode* temp = head->next;
        while (temp != nullptr) {
            if (temp->val == val) {
                // ListNode* k=temp;
                prev->next = temp->next;
                // delete k;
            } else
                prev = temp;
            temp = temp->next;
        }

        return head;
    }
};
/*
=========================================================
Problem: Middle of the Linked List
Difficulty: Easy

My Approach:
- Used the slow and fast pointer technique.
- Initialized both pointers at the head of the list.
- Moved the slow pointer one step and the fast pointer two
  steps at a time.
- When the fast pointer reached the end of the list, the
  slow pointer was positioned at the middle node.
- Correctly returned the second middle node for even-length
  linked lists.

Key Concept(s):
- Linked Lists
- Slow and Fast Pointers
- Two-Pointer Technique

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Moving one pointer twice as fast as the other allows the
  middle node to be found in a single traversal.
- Careful handling of stopping conditions ensures correct
  behavior for both odd and even-length linked lists.

Revision Note:
1. Initialize slow and fast pointers.
2. Move slow by one step.
3. Move fast by two steps.
4. Stop when fast reaches the end.
5. Return the slow pointer.

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
c/**
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
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr)
            return head;
        else if (head->next->next == nullptr)
            return head->next;
        ListNode* slow = head;
        ListNode* fast = head;
        while (1) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast->next == nullptr)
                return slow;
            else if (fast->next->next == nullptr)
                return slow->next;
        }
        return head;
    }
};
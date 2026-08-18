/*
=========================================================
Problem: Rotate List
Difficulty: Medium

My Approach:
- First calculated the length of the linked list.
- Used k % len to eliminate unnecessary complete rotations.
- If k becomes 0, returned the original list.
- Located the node that should become the new tail at
  position len - k.
- Stored the node after it as the new head.
- Connected the original tail to the original head,
  temporarily forming a circular list.
- Broke the circle at the new tail by setting its next
  pointer to nullptr.
- Returned the new head.

Key Concept(s):
- Linked List
- Two-Pass Traversal
- Pointer Manipulation
- Circular Linked List
- Modulo Optimization

Core Observation:
Rotating a list by its length produces the same list.

Therefore:

    k = k % len

After reducing k, the new head is located at:

    len - k

The original tail can then be connected to the original
head, and the list can be broken at the new tail.

Example:

    1 → 2 → 3 → 4 → 5
    k = 2

Result:

    4 → 5 → 1 → 2 → 3

Time Complexity:
O(n)

Space Complexity:
O(1)

Why This Is Optimal:
Every node may need to be visited to determine the length
and locate the rotation point, so O(n) time is necessary.
Only a constant number of pointers are used.

What I Learned:
- Modulo can eliminate redundant operations when a process
  repeats after a fixed number of steps.
- Linked-list rotations can be simplified by temporarily
  connecting the tail to the head.
- The key to rotating a linked list is identifying the new
  head and new tail rather than physically moving every node.
- Careful pointer manipulation allows the operation to be
  performed in O(1) extra space.

Problem Solving Status:
🟢 Independently Solved
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        temp = head;
        ListNode* newhead;
        ListNode* note;
        int i = 0;
        while (temp != nullptr) {
            i++;
            if (i == len - k) {
                newhead = temp->next;
                note = temp;
            }
            if (temp->next == nullptr) {
                temp->next = head;
                note->next = nullptr;
                return newhead;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
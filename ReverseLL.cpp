/*
=========================================================
Problem: Reverse Linked List
Difficulty: Easy

My Approach:
- Handled empty and single-node linked lists as special
  cases.
- Used three pointers to reverse the links in-place:
  - prev: previous node
  - temp: current node
  - mover: next node
- Broke the original head's next pointer before starting
  the reversal to avoid cycles.
- Repeatedly reversed each link until reaching the last node.

Key Concept(s):
- Linked Lists
- Pointer Manipulation
- In-place Reversal
- Three Pointer Technique

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Reversing a linked list requires preserving the next node
  before changing any pointers.
- Updating pointers in the correct order prevents losing
  access to the remaining list.
- Breaking the original head's next pointer avoids creating
  cycles during reversal.

Revision Note:
1. Handle edge cases.
2. Initialize previous, current, and next pointers.
3. Reverse the current node's next pointer.
4. Move all pointers one step forward.
5. Return the new head.

=========================================================
*//**
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        else if (head->next == nullptr)
            return head;
        else if (head->next->next == nullptr) {
            ListNode* temp = head->next;
            temp->next = head;
            head->next = nullptr;
            return temp;
        }
        ListNode* prev = head;
        ListNode* temp = head->next;
        ListNode* mover;
        head->next = nullptr;
        while (1) {
            if (temp->next == nullptr) {
                temp->next = prev;
                break;
            }
            mover = temp->next;
            temp->next = prev;
            prev = temp;
            temp = mover;
        }
        return temp;
    }
};
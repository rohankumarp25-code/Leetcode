/*
=========================================================
Problem: Reverse Linked List II
Difficulty: Medium

My Approach:
- Traversed the linked list while keeping track of the
  current position.
- Found the node immediately before the `left` position.
- Stored the first node of the section to be reversed.
- Reversed the nodes between `left` and `right` in-place
  using pointer manipulation.
- Used an extra pointer (`mover`) to preserve the next
  node before changing the current node's `next` pointer.
- After reaching the `right` position, reconnected the
  reversed portion with the remaining linked list.
- Handled the special case where `left == 1`, since the
  head of the linked list changes after reversal.

Example:

    1 → 2 → 3 → 4 → 5
        ↑       ↑
      left    right

Reverse the portion from position 2 to 4:

    1 → 4 → 3 → 2 → 5

Key Concepts:
- Singly Linked List
- In-place Linked List Reversal
- Pointer Manipulation
- Previous and Current Pointers
- Saving the Next Node
- Reconnecting a Reversed Sublist
- Edge Case Handling

Core Observation:
The required portion of the linked list can be reversed
directly by changing the `next` pointers.

There is no need to create another linked list or store
the nodes in an array.

The important connections after reversal are:

    Node before left → New first node of reversed section

    Original first node of reversed section
        → Node after right

Initial Approach:
- Not applicable.
- Solved directly using in-place pointer manipulation.

Optimized Approach:
- Traverse the list until the `left` position.
- Reverse the nodes from `left` to `right`.
- Reconnect the reversed portion with the nodes before
  and after it.
- Handle `left == 1` separately because the new head
  becomes the node originally at position `right`.

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

Why This Is Optimal:
Every node up to the required portion may need to be
visited, so O(n) time is necessary.

The reversal is performed directly on the linked list
using pointers, so no additional data structure is
required.

Therefore, O(n) time and O(1) auxiliary space are optimal.

What I Learned:
- How to reverse only a specific portion of a linked list.
- How to preserve the remaining part of the linked list
  while reversing a sublist.
- Why the next node must be saved before changing a
  node's `next` pointer.
- How to reconnect the reversed portion correctly.
- How the `left == 1` case changes the head of the list.
- Strengthened my understanding of in-place pointer
  manipulation.

Problem Solving Progress:
Previous Linked List Reversal:
    Reverse the entire linked list

Current Problem:
    Reverse only the portion from `left` to `right`

Optimized approach:
    O(n) time + O(1) space

Problem Solving Status:
🟢 Independently Solved
🟢 In-place Reversal
🟢 O(1) Extra Space
🟢 Optimal Complexity

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        int i = 0;
        ListNode* temp = head;
        ListNode* first;
        ListNode* last;
        ListNode* mover;
        ListNode* prev;
        ListNode* bef;
        while (temp != nullptr) {
            i++;
            if (i < left) {
                if (i + 1 == left)
                    bef = temp;
                temp = temp->next;
            } else if (i == left) {
                first = temp;
                prev = temp;
                temp = temp->next;
            } else if (i > left && i < right) {
                mover = temp->next;
                temp->next = prev;
                prev = temp;
                temp = mover;
            } else if (i == right) {
                last = temp;
                first->next = temp->next;
                temp->next = prev;
                if (bef != nullptr)
                    bef->next = temp;
                if (left == 1)
                    return last;
                return head;
            }
        }
        return head;
    }
};
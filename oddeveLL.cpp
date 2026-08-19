/*
=========================================================
Problem: Odd Even Linked List
Difficulty: Medium

My Approach:
- Rearranged the linked list in-place using pointer
  manipulation.
- Kept track of the beginning of the even-positioned nodes
  using `firsteven`.
- Traversed the list while reconnecting the odd-positioned
  nodes together.
- Preserved the even portion and attached it after the final
  odd-positioned node.
- Did not create a separate linked list or array.

Example:

Input:
1 → 2 → 3 → 4 → 5

Output:
1 → 3 → 5 → 2 → 4

Key Concept(s):
- Linked List
- Pointer Manipulation
- In-Place Rearrangement
- Odd/Even Position Tracking

Core Observation:
The required arrangement is based on the POSITION of nodes,
not their values.

All odd-positioned nodes must appear first, followed by all
even-positioned nodes.

I preserved the beginning of the even portion and repeatedly
rewired the next pointers to build the odd portion.

Time Complexity:
O(n)

Space Complexity:
O(1)

Why This Is Optimal:
Every node needs to be processed at least once, so O(n) time
is necessary. The list is rearranged using only pointers,
requiring O(1) auxiliary space.

What I Learned:
- Linked-list problems can often be solved by carefully
  rewiring existing next pointers rather than creating new
  data structures.
- When modifying linked lists in-place, preserving references
  to important portions of the list is essential.
- Understanding exactly what each pointer represents is more
  important than memorizing a linked-list template.

Problem Solving Status:
🟢 Independently Solved
🟢 O(1) Extra Space

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr)
            return head;
        ListNode* mover = head;
        ListNode* temp = head;
        ListNode* firsteven = head->next;
        while (temp != nullptr && temp->next != nullptr) {
            mover = temp->next->next;
            if (mover != nullptr)
                temp->next->next = mover->next;
            temp->next = mover;
            if (mover == nullptr) {
                temp->next = firsteven;
                break;
            } else if (mover->next == nullptr) {
                mover->next = firsteven;
                break;
            }
            temp = mover;
        }
        return head;
    }
};
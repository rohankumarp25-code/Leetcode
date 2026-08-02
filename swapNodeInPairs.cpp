/*
=========================================================
Problem: Swap Nodes in Pairs
Difficulty: Medium

My Approach:
- Handled edge cases for empty and single-node linked lists.
- Updated the head to the second node, which becomes the
  new head after swapping the first pair.
- Traversed the linked list pair by pair.
- Maintained pointers to:
    - Current pair
    - Next pair
    - Remaining part of the list
- Swapped adjacent nodes by updating only the next
  pointers without modifying node values.
- Repeated the process until all possible pairs were
  swapped.

Key Concept(s):
- Linked Lists
- Pointer Manipulation
- In-place Node Swapping

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Swapping nodes in a linked list requires careful planning
  of pointer updates to avoid losing access to the
  remaining nodes.
- Giving pointers meaningful names (such as nextPair)
  makes complex pointer manipulations easier to understand
  and debug.
- Solving pointer problems becomes easier by visualizing
  the links before writing code.

Future Improvement:
- Explore the dummy-node approach to simplify pointer
  updates and reduce the number of special-case branches
  while maintaining the same O(n) time and O(1) space.

Revision Note:
1. Handle edge cases.
2. Update the head after the first swap.
3. Identify the current pair.
4. Store the next pair.
5. Swap the current pair.
6. Connect to the remaining list.
7. Repeat until all pairs are processed.
=========================================================
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* mover = head;
        head = mover->next;
        while (mover != nullptr) {
            if (mover->next == nullptr)
                break;
            ListNode* nextPair = mover->next->next;
            if (nextPair == nullptr) {
                mover->next->next = mover;
                mover->next = nullptr;
                break;
            }
            ListNode* node1 = mover;
            ListNode* node2 = mover->next;
            ListNode* temp = node2->next->next;
            if (temp == nullptr)
                temp = node2->next;
            node2->next = node1;
            node1->next = temp;
            mover = nextPair;
        }
        return head;
    }
};
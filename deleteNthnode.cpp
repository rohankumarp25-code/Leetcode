/*
=========================================================
Problem: Remove Nth Node From End of List
Difficulty: Medium

My Approach:
- Traversed the linked list once to determine its total
  length.
- Converted the problem of removing the nth node from the
  end into removing the (length - n + 1)th node from the
  beginning.
- Handled the special case where the head node needs to be
  removed.
- Traversed the list a second time to reach the node just
  before the target node.
- Updated the next pointer to bypass the target node.

Key Concept(s):
- Linked Lists
- Pointer Manipulation
- Two-Pass Traversal
- Index Conversion

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Problems involving the nth node from the end can be
  transformed into a position from the beginning after
  counting the total number of nodes.
- Deleting a node in a singly linked list requires access
  to the previous node.
- Correct pointer updates are essential to maintain the
  integrity of the linked list.
- Although this solution handles the head separately, a
  dummy node can simplify the implementation by removing
  special-case handling.

Future Improvement:
- Learn and implement the dummy node technique to simplify
  edge cases.
- Solve the problem using the one-pass slow and fast
  pointer approach.

Revision Note:
1. Count the total number of nodes.
2. Convert the target position from the end to the
   beginning.
3. Handle deletion of the head separately.
4. Traverse to the previous node.
5. Update pointers to remove the target node.
6. Return the modified head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        if (length - n == 0) {
            head = head->next;
        }
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            i++;
            if (i == length - n) {
                ListNode* got = temp->next;
                temp->next = got->next;
            } else
                temp = temp->next;
        }
        return head;
    }
}; 
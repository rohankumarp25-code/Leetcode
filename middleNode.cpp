/*
=========================================================
Problem: Delete the Middle Node of a Linked List
Difficulty: Medium

My Approach:
- Traversed the linked list once to count the total number
  of nodes.
- Traversed the list a second time to locate the node just
  before the middle.
- Updated the previous node's next pointer to bypass the
  middle node, effectively deleting it.

Key Concept(s):
- Linked Lists
- Pointer Traversal
- Two-Pass Algorithm
- In-place Deletion

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Counting the total number of nodes helps determine the
  middle position in a linked list.
- Deleting a node in a singly linked list requires access
  to the previous node.
- A correct solution can often be obtained with multiple
  traversals before optimizing to a single-pass approach.

Future Improvement:
- Learn the slow and fast pointer technique to locate the
  middle node in a single traversal.

Revision Note:
1. Count the total number of nodes.
2. Traverse to the node before the middle.
3. Update the previous node's next pointer.
4. Return the modified head.
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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        int count = 0;
        if (head->next == nullptr)
            return nullptr;
        ListNode* mover = head;
        while (mover != nullptr) {
            n++;
            mover = mover->next;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            if (count == n / 2) {
                prev->next = temp->next;
                break;
            } else {
                count++;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
/*
=========================================================
Problem: Middle of the Linked List
Difficulty: Easy

My Approach:
- Traversed the linked list once to count the total number
  of nodes.
- Traversed the list again until reaching the middle node.
- Returned the second middle node when the list length was
  even, as required by the problem.

Key Concept(s):
- Linked Lists
- Pointer Traversal
- Two-Pass Algorithm

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Counting the number of nodes helps determine the exact
  middle position in a linked list.
- Integer division naturally handles both odd and even
  length lists when calculating the middle index.
- A correct two-pass solution can later be optimized using
  the slow and fast pointer technique.

Future Improvement:
- Learn the slow and fast pointer approach to find the
  middle node in a single traversal.

Revision Note:
1. Count the total number of nodes.
2. Compute the middle position.
3. Traverse to the middle node.
4. Return the middle node.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        //  ListNode* ans;
        int n = 0;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        ListNode* ans = head;
        int count = 0;
        while (ans != nullptr) {
            count++;
            if (count == (n / 2) + 1) {
                break;
            }
            ans = ans->next;
        }
        return ans;
    }
};
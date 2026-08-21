/*
=========================================================
Problem: Maximum Twin Sum of a Linked List
Difficulty: Medium

My Approach:
- Used the slow and fast pointer technique to find the
  middle of the linked list.
- Split the linked list into two halves.
- Reversed the second half in-place.
- Traversed the first half and the reversed second half
  simultaneously.
- Calculated the sum of corresponding twin nodes and kept
  track of the maximum sum.

Example:

    1 → 2 → 3 → 4

First half:
    1 → 2

Second half:
    3 → 4

After reversing second half:
    4 → 3

Twin sums:
    1 + 4 = 5
    2 + 3 = 5

Maximum Twin Sum = 5

Key Concepts:
- Slow and Fast Pointers
- Finding the Middle of a Linked List
- Splitting a Linked List
- In-place Linked List Reversal
- Two-Pointer Traversal
- Pointer Manipulation

Core Observation:
Instead of storing all node values in a vector, the second
half of the linked list can be reversed in-place.

This allows the first half and reversed second half to be
traversed simultaneously without using an additional array.

Initial Approach:
- Store all node values in a vector.
- Use two pointers on the vector.
- Time: O(n)
- Space: O(n)

Optimized Approach:
- Find the middle using slow/fast pointers.
- Reverse the second half.
- Compare corresponding nodes directly.
- Time: O(n)
- Extra Space: O(1)

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

Why This Is Optimal:
Every node may need to be visited, so O(n) time is necessary.
The list itself is used for the reversal, eliminating the
need for an additional vector.

What I Learned:
- A linked-list problem that initially required O(n) extra
  space can sometimes be optimized by modifying the list
  itself.
- Slow/fast pointers can locate the middle efficiently.
- In-place reversal is a powerful technique for processing
  the second half of a linked list.
- Multiple linked-list techniques can be combined to create
  an optimal solution.

Problem Solving Progress:
Vector approach:
    O(n) time + O(n) space

Optimized approach:
    O(n) time + O(1) space

Problem Solving Status:
🟢 Independently Optimized
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
    int pairSum(ListNode* head) {
        int sum = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp;
        while(fast!=nullptr){
            fast=fast->next->next;
            if(fast==nullptr){
             temp = slow->next;
            slow->next=nullptr;
            }
            slow=slow->next;
        }
        ListNode*prevnode=nullptr;
        ListNode*forwnode;
        while(temp!=nullptr){
         forwnode=temp->next;
         temp->next=prevnode;
         prevnode=temp;
         temp=forwnode;
        }
        fast = head;
        while(fast!=nullptr){
            sum=max(sum,fast->val+prevnode->val);
            fast=fast->next;
            prevnode=prevnode->next;
        }
        return sum;
    }
};
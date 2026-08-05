/*
=========================================================
Problem: Linked List Cycle
Difficulty: Easy

My Approach:
- Used Floyd's Cycle Detection Algorithm (Fast & Slow
  Pointers).
- Initialized two pointers at the head of the linked list.
- Moved:
    - Slow pointer by one node.
    - Fast pointer by two nodes.
- If the two pointers ever meet, a cycle exists.
- If the fast pointer reaches the end of the list, there is
  no cycle.

Key Concept(s):
- Fast & Slow Pointers
- Floyd's Cycle Detection Algorithm
- Linked Lists

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Two pointers moving at different speeds can detect
  cycles without modifying the linked list.
- Floyd's Cycle Detection Algorithm is both time and space
  optimal for cycle detection.
- Carefully checking pointer validity prevents null pointer
  dereferencing.

Future Improvement:
- Learn why Floyd's algorithm mathematically guarantees
  that the two pointers meet if a cycle exists.
- Extend this concept to finding the starting node of the
  cycle (Linked List Cycle II).

Revision Note:
1. Initialize slow and fast pointers.
2. Move slow by one step.
3. Move fast by two steps.
4. If they meet, return true.
5. If fast reaches nullptr, return false.
=========================================================
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
           slow=slow->next;
           fast=fast->next->next;
           if(fast==slow)
           return true;
        }
        return false;
    }
};
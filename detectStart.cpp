/*
=========================================================
Problem: Linked List Cycle II
Difficulty: Medium

My Approach:
- First used the slow and fast pointer technique to detect
  whether a cycle exists.
- Slow moves one node at a time while fast moves two nodes
  at a time.
- If they meet, a cycle exists.
- After the meeting point is found, reset the fast pointer
  to the head.
- Move both pointers one node at a time.
- The node where they meet again is the starting node of
  the cycle.
- If no cycle exists, return nullptr.

Key Concept(s):
- Floyd's Cycle Detection Algorithm
- Fast and Slow Pointers
- Linked Lists
- Mathematical Distance Relationship
- O(1) Space Cycle Detection

Core Observation:
Let:
    X = distance from head to the cycle entrance.

After slow and fast meet inside the cycle, the distance
relationship between the head, cycle entrance, and meeting
point allows the cycle entrance to be found by placing one
pointer at the head and moving both pointers one step at
a time.

This relationship was derived independently by analyzing
the position of the slow and fast pointers when they meet.

Time Complexity:
O(n)

Space Complexity:
O(1)

Why This Is Optimal:
Every node may need to be visited, so O(n) time is necessary
in the worst case. The algorithm uses only two pointers and
requires no hash map or additional data structure.

What I Learned:
- Floyd's algorithm can detect a cycle and also locate its
  starting node.
- Fast and slow pointer movement can reveal mathematical
  relationships between positions in a linked list.
- A problem initially solved using O(n) extra space with a
  hash map can be optimized to O(1) space.
- Deriving the mathematical relationship myself made the
  algorithm much easier to understand than memorizing it.

Problem Solving Status:
🟢 Independently Derived
🟢 Independently Optimized

Time:
O(n)

Space:
O(1)

=========================================================
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && slow != nullptr) {
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                if (fast == head)
                    return head;
                else
                    fast = head;
                break;
            }
        }
        while (fast != nullptr && slow != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
                return fast;
        }
        return nullptr;
    }
};
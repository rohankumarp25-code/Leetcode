/*
=========================================================
Problem: Leaders in an Array
Difficulty: Easy

My Approach:
- For each element, assumed it to be a potential leader.
- Used another pointer to scan all elements to its right.
- If a larger element was found, updated the candidate and
  continued checking from that position.
- If no larger element existed to the right, added the
  current element to the answer.
- Handled the last one/two elements separately to complete
  the result.

Key Concept(s):
- Arrays
- Two Pointers
- Sequential Traversal
- Brute Force Observation

Time Complexity:
Best Case : O(n)
Average Case : O(n²)
Worst Case : O(n²)

Space Complexity:
O(1)
(Excluding the output array)

What I Learned:
- A brute-force solution can still be logically correct if
  all cases are handled carefully.
- Time complexity depends on how many times the inner pointer
  traverses the remaining elements.
- Analyzing best, average, and worst cases gives a deeper
  understanding of an algorithm's efficiency.
- Before learning the optimal solution, deriving a working
  approach independently strengthens problem-solving skills.

Future Improvement:
- Explore an O(n) solution by utilizing the properties of
  leaders while traversing the array in a different direction.

Revision Note:
1. Consider each element as a potential leader.
2. Scan the elements to its right.
3. If a greater element exists, discard the current candidate.
4. Otherwise, add it to the answer.
5. Handle the remaining element(s).
=========================================================
*/
class Solution {
	public:
	vector<int> leaders(vector<int>& arr) {
		// code here
		vector<int>ans;
		int leader;
		int i = 0;
		int j = 1;
		if (arr.size()>2) {
			while (1) {
				leader = arr[i];
				if (arr[j]>leader) {
					leader = arr[j];
					i = j;
					j = i + 1;
				}
				else if (arr[j]<leader) {
					j++;
				}
				if (i != arr.size() - 2 && j == arr.size() - 1) {
					ans.push_back(arr[i]);
					i++;
					j = i + 1;
				}
				
				if (i == arr.size() - 2)
					break;
			}
			
		}
		if (arr[arr.size() - 2]>arr[arr.size() - 1]) {
			ans.push_back(arr[arr.size() - 2]);
			ans.push_back(arr[arr.size() - 1]);
		}
		else
			ans.push_back(arr[arr.size() - 1]);
		return ans;
	}
};

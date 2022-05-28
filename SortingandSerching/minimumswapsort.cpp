#include <bits/stdc++.h>
using namespace std;
// Function returns the
// minimum number of swaps
// required to sort the array
int minSwaps(int nums[], int n)
{
	int len = n;
	map<int, int> map;
	for (int i = 0; i < len; i++)
		map[nums[i]] = i;

	sort(nums, nums + n);

	// To keep track of visited elements. Initialize
	// all elements as not visited or false.
	bool visited[len] = { 0 };

	// Initialize result
	int ans = 0;
	for (int i = 0; i < len; i++) {

		// already swapped and corrected or
		// already present at correct pos
		if (visited[i] || map[nums[i]] == i)
			continue;

		int j = i, cycle_size = 0;
		while (!visited[j]) {
			visited[j] = true;

			// move to next node
			j = map[nums[j]];
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0) {
			ans += (cycle_size - 1);
		}
	}
	return ans;
}
int main()
{
	// Driver program to test the above function
	int a[] = { 1, 5, 4, 3, 2 };
	int n = 5;
	cout << minSwaps(a, n);
	return 0;
}



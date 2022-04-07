// Pair sum in array

// You have been given an integer array / list(ARR) and a number 'num'. Find and return the total number of pairs in the array / list which sum to 'num'.
//         Note:
//         Given array / list can contain duplicate elements.
//         Input format :
//         The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

//         First line of each test case or query contains an integer 'N' representing the size of the first array/list.

// 	        Second line contains 'N' single space separated integers representing the elements in the array / list.

// 	        Third line contains an integer 'num'.
// 	        Output format :
// For each test case, print the total number of pairs present in the array / list.

// Output for every test case will be printed in a separate line.
// 	Constraints :
// 1 <= t <= 10 ^ 2
// 0 <= N <= 10 ^ 4
// 0 <= num <= 10 ^ 9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 9
// 1 3 6 2 5 4 3 2 4
// 7
// Sample Output 1:
// 7
// Sample Input 2:
// 2
// 9
// 1 3 6 2 5 4 3 2 4
// 12
// 6
// 2 8 10 5 - 2 5
// 10
// Sample Output 2:
// 0
// 2


// Explanation for Input 2 :
// Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

// For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).


//Time Complexity: O(n*logn)
int pairSum(int *a, int n, int num) {
	sort(a, a + n);
	int i = 0, j = n - 1;
	int ans = 0, count = 0;
	while (i < j) {
		while (a[i] + a[j] > num) {
			if (i >= j) break;
			j--;
		}
		while (a[i] + a[j] < num) {
			if (i >= j) break;
			i++;
		}
		if (a[i] + a[j] == num) {
			if (a[i] != a[j]) {
				int x = i + 1;
				int firstRepeatCount = 1;
				while (a[x] == a[i]) {
					x++;
					firstRepeatCount++;
				}
				i = x;
				x = j - 1;
				int secondRepeatCount = 1;
				while (a[x] == a[j]) {
					x--;
					secondRepeatCount++;
				}
				j = x;
				count += firstRepeatCount * secondRepeatCount;
			} else if (a[i] == a[j]) {
				int x = j - i + 1;
				count += (x - 1) * x / 2;
				break;
			}
		}
	}
	return count;
}


//Time Complexity: O(n^2)
int pairSum(int *a, int n, int num) {
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == num) {
				count++;
			}
		}
	}
	return count;
}



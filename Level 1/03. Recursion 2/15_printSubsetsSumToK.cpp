// Print Subset Sum to K

// Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print them in different lines.
// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K
// Sample Input:
// 9
// 5 12 3 17 1 18 15 3 17
// 6
// Sample Output:
// 3 3
// 5 1


void helper(int input[], int start, int n, int output[], int os, int k) {
	// Base case begin
	if (k < 0) {
		return;
	}
	if (start == n) {
		if (k == 0) {
			for (int i = 0; i < os; i++) {
				cout << output[i] << " ";
			}
			cout << endl;
			return;
		}
		return;
	}
	//Base Case end

	int newOutput[os + 1];
	int i = 0;
	for (; i < os; i++) {
		newOutput[i] = output[i];
	}
	newOutput[i] = input[start];
	helper(input, start + 1, n, newOutput, os + 1, k - input[start]);
	helper(input, start + 1, n, output, os, k);
}

void printSubsetSumToK(int input[], int size, int k) {
	int output[50];
	helper(input, 0, size, output, 0, k);
}

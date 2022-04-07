// Return subsets sum to K

// Given an array A of size n and an integer K, return all subsets of A which sum to K.
//         Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
//         Note : The order of subsets are not important.
//         Input format :
//         Line 1 : Integer n, Size of input array
//         Line 2 : Array elements separated by space
//         Line 3 : K
//         Constraints :
//         1 <= n <= 20
//         Sample Input :
//         9
//         5 12 3 17 1 18 15 3 17
//         6
//         Sample Output :
//         3 3
//         5 1


/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int helper(int input[], int start, int n, int output[][50], int val) {

	//Base case begin
	if (val < 0) {
		return 0;
	}
	if (start == n) {
		if (val == 0) {
			output[0][0] = 0;
			return 1;
		}
		return 0;
	}
	//Base case end

	int so1[5000][50], so2[5000][50];
	int s1 = helper(input, start + 1, n, so1, val - input[start]);
	int s2 = helper(input, start + 1, n, so2, val);
	int k = 0;
	for (int i = 0; i < s1; i++) {
		output[k][0] = so1[i][0] + 1;
		output[k][1] = input[start];
		for (int j = 1; j <= so1[i][0]; j++) {
			output[k][j + 1] = so1[i][j];
		}
		k++;
	}
	for (int i = 0; i < s2; i++) {
		for (int j = 0; j <= so2[i][0]; j++) {
			output[k][j] = so2[i][j];
		}
		k++;
	}
	return k;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
	return helper(input, 0, n, output, k);
}




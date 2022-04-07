// Merge Sort Code

// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
//         Input format :
//         Line 1 : Integer n i.e. Array size
//         Line 2 : Array elements (separated by space)
//         Output format :
//         Array elements in increasing order (separated by space)
//         Constraints :
//         1 <= n <= 10 ^ 3
//         Sample Input 1 :
//         6
//         2 6 8 5 4 3
//         Sample Output 1 :
//         2 3 4 5 6 8
//         Sample Input 2 :
//         5
//         2 1 5 2 3
//         Sample Output 2 :
//         1 2 2 3 5


void merge(int* input, int s, int m, int e) {
	int i = s, j = m + 1, k = 0;
	int ans[e + 1];
	while (i <= m && j <= e) {
		if (input[i] <= input[j]) {
			ans[k] = input[i];
			i++;
		} else {
			ans[k] = input[j];
			j++;
		}
		k++;
	}
	while (i <= m) {
		ans[k] = input[i];
		i++;
		k++;
	}
	while (j <= e) {
		ans[k] = input[j];
		j++;
		k++;
	}
	int idx = 0;
	for (int itr = s; itr <= e; itr++) {
		input[itr] = ans[idx];
		idx++;
	}
}

void mergeSort(int* input, int s, int e) {
	if (s >= e) return;
	int m = s + (e - s) / 2;
	mergeSort(input, s, m);
	mergeSort(input, m + 1, e);
	merge(input, s, m, e);
}

void mergeSort(int input[], int size) {
	mergeSort(input, 0, size - 1);
}




















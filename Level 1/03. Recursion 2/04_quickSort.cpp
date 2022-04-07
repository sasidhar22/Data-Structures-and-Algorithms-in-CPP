// Quick Sort Code

// Sort an array A using Quick Sort.
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
//         1 5 2 7 3
//         Sample Output 2 :
//         1 2 3 5 7


int partition(int* input, int s, int e) {
	int x = input[s];
	int c = 0;
	for (int i = s; i <= e; i++) {
		if (input[i] < x) c++;
	}
	int partitionIndex = s + c;
	int temp = input[partitionIndex];
	input[partitionIndex] = input[s];
	input[s] = temp;
	int i = s, j = e;
	while (i < partitionIndex && j > partitionIndex) {
		if (input[i] < input[partitionIndex])i++;
		else if (input[j] >= input[partitionIndex])j--;
		else {
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++; j--;
		}
	}
	return partitionIndex;
}

void quickSort(int* input, int s, int e) {
	if (s >= e) return;
	int partitionIndex = partition(input, s, e);
	quickSort(input, s, partitionIndex - 1);
	quickSort(input, partitionIndex + 1, e);
}

void quickSort(int input[], int size) {
	quickSort(input, 0, size - 1);
}
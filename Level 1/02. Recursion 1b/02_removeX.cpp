// Remove X

// Given a string, compute recursively a new string where all 'x' chars have been removed.
// Input format :
// String S
// Output format :
// Modified String
// Constraints :
// 1 <= | S | <= 10 ^ 3
// where | S | represents the length of string S.
// Sample Input 1 :
// xaxb
// Sample Output 1:
// ab
// Sample Input 2 :
// abc
// Sample Output 2:
// abc
// Sample Input 3 :
// xx
// Sample Output 3:


// Change in the given string itself. So no need to return or print anything

int len(char* input) {
	int l = 0;
	for (int i = 0; input[i] != '\0'; i++)l++;
	return l;
}

void helper(char* input, int len) {
	if (len == 0) {
		return;
	}
	if (input[0] == 'x') {
		int i = 1;

		// for(;i<=len;i++){
		//     input[i-1] = input[i];
		// }

		for (; i < len; i++) {
			input[i - 1] = input[i];
		}
		input[i - 1] = '\0';
		helper(input, len - 1);
	}
	helper(input + 1, len - 1);
}

void removeX(char input[]) {
	int l = len(input);
	helper(input, l);
}

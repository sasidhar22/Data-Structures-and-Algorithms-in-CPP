// Pair Star

// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
// Input format :
// String S
// Output format :
// Modified string
// Constraints :
// 0 <= | S | <= 1000
// where | S | represents length of string S.
// Sample Input 1 :
// hello
// Sample Output 1:
// hel*lo
// Sample Input 2 :
// aaaa
// Sample Output 2 :
// a*a*a*a


// Change in the given string itself. So no need to return or print the changed string.

int len(char* input) {
	int l = 0;
	for (int i = 0; input[i] != '\0'; i++) {
		l++;
	}
	return l;
}

void helper(char* input, int len) {
	if (len == 1) {
		return;
	}
	if (input[0] == input[1]) {
		int i = len;
		for (; i >= 1; i--) {
			input[i] = input[i - 1];
		}
		input[1] = '*';
		input[len + 1] = '\0';
		helper(input + 2, len - 1);
	}
	helper(input + 1, len - 1);
}

void pairStar(char input[]) {
	int l = len(input);
	helper(input, l);
}

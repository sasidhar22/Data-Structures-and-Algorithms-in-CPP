// Check Palindrome (recursive)

// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= | S | <= 1000
// where | S | represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// ninja
// Sample Output 2:
// false

int len(char* input) {
	int l = 0;
	for (int i = 0; input[i] != '\0'; i++) l++;
	return l;
}

bool helper(char* input, int start, int end) {
	if (start >= end) {
		return true;
	}
	if (input[start] != input[end]) {
		return false;
	}
	return helper(input, start + 1, end - 1);
}

bool checkPalindrome(char input[]) {
	// Write your code here
	int l = len(input);
	return helper(input, 0, l - 1);
}



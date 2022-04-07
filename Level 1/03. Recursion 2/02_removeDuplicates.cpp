// Remove Duplicates Recursively

// Given a string S, remove consecutive duplicates from it recursively.
// Input Format :
// String S
// Output Format :
// Output string
// Constraints :
// 1 <= | S | <= 10 ^ 3
// where | S | represents the length of string
// Sample Input 1 :
// aabccba
// Sample Output 1 :
// abcba
// Sample Input 2 :
// xxxyyyzwwzzz
// Sample Output 2 :
// xyzwz

void removeConsecutiveDuplicates(char *input) {
	if (input[0] == '\0') return;
	if (input[1] == input[0]) {
		int i = 1;
		while (input[i] != '\0') {
			input[i - 1] = input[i];
			i++;
		}
		input[i - 1] = input[i];
		removeConsecutiveDuplicates(input);
	}
	removeConsecutiveDuplicates(input + 1);
}
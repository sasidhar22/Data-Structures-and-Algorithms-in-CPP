// Replace pi (recursive)

// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// Constraints :
// 1 <= | S | <= 50
// where | S | represents the length of string S.
// Sample Input 1 :
// xpix
// Sample Output :
// x3.14x
// Sample Input 2 :
// pipi
// Sample Output :
// 3.143.14
// Sample Input 3 :
// pip
// Sample Output :
// 3.14p
// Constraints: -
// 1 <= | S | <= 50

int len(char* input) {
	int l = 0;
	for (int i = 0; input[i] != '\0'; i++)l++;
	return l;
}

void helper(char* input, int len) {
	if (len == 1) {
		return;
	}
	if (input[0] == 'p' && input[1] == 'i') {
		for (int i = len - 1; i >= 2; i--) {
			input[i + 2] = input[i];
		}
		input[len + 2] = '\0';
		input[0] = '3';
		input[1] = '.';
		input[2] = '1';
		input[3] = '4';
		helper(input + 4, len - 1);
	}
	helper(input + 1, len - 1);
}

void replacePi(char input[]) {
	int l = len(input);
	helper(input, l);
}


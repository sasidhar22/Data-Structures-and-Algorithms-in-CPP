// String to Integer

// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
//         Input format :
//         Numeric string S (string, Eg. "1234")
//         Output format :
//         Corresponding integer N (int, Eg. 1234)
//         Constraints :
//         0 <= | S | <= 9
//         where | S | represents length of string S.
//         Sample Input 1 :
//         00001231
//         Sample Output 1 :
//         1231
//         Sample Input 2 :
//         12567
//         Sample Output 2 :
//         12567

int len(char* input) {
	int l = 0;
	for (int i = 0; input[i] != '\0'; i++)l++;
	return l;
}

void helper(char* input, int &val) {
	if (len(input) == 0) return;
	val = val * 10 + int(input[0] - '0');
	helper(input + 1, val);
}

int stringToNumber(char input[]) {
	int val = 0;
	helper(input, val);
	return val;
}



// Print all Codes - String

// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
//                                     Note : The order of codes are not important. Just print them in different lines.
//                                     Input format :
//                                     A numeric string S
//                                     Output Format :
//                                     All possible codes in different lines
//                                     Constraints :
//                                     1 <= Length of String S <= 10
//                                     Sample Input:
//                                     1123
//                                     Sample Output:
//                                     aabc
//                                     kbc
//                                     alc
//                                     aaw
//                                     kw


#include <string.h>
using namespace std;

void helper(string input, string output) {
	if (input[0] == '\0') {
		cout << output << endl;
		return;
	}
	int n = input[0] - 48;
	char ch = n + 'a' - 1;
	helper(input.substr(1), output + ch);
	if (input[1] != '\0') {
		n = n * 10 + input[1] - 48;
		if (n >= 10 && n <= 26) {
			ch = n + 'a' - 1;
			helper(input.substr(2), output + ch);
		}
	}
}

void printAllPossibleCodes(string input) {
	/*
	Given the input as a string, print all its possible combinations. You do not need to return anything.
	*/
	// string output="";
	helper(input, "");
}


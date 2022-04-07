// Return all codes - String

// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
//                                     Note : The order of codes are not important. And input string does not contain 0s.
//                                     Input format :
//                                     A numeric string
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

int helper(string input, int start, string output[100]) {
	// if(start == input.length()){
	// output[0]="";
	// return 1;
	// }
	if (input[start] == '\0') {
		output[0] = "";
		return 1;
	}

	int n = input[start] - 48;
	char ch = n + 'a' - 1;

	string smallOutput1[100];
	int s1 = helper(input, start + 1, smallOutput1);
	int k = 0;
	for (int i = 0; i < s1; i++) {
		output[k] = ch + smallOutput1[i];
		k++;
	}

	string smallOutput2[100];
	int s2 = 0;
	if (input[start + 1] != '\0') {
		n *= 10;
		n += input[start + 1] - 48;
		if (n >= 10 && n <= 26) {
			ch = n + 'a' - 1;
			s2 = helper(input, start + 2, smallOutput2);
			for (int i = 0; i < s2; i++) {
				output[k] = ch + smallOutput2[i];
				k++;
			}
		}
	}
	return k;
}

int getCodes(string input, string output[10000]) {
	/*
	You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
	Also, return the number of codes return to the output string. You do not need to print anything.
	*/
	int ans = helper(input, 0, output);
	return ans;
}

/*-------------------------------------------OR-------------------------------------------*/

// Without using a helper function and using the same output array for recursive calls
int getCodes(string input, string output[10000]) {
	/*
	You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
	Also, return the number of codes return to the output string. You do not need to print anything.
	*/
	if (input.length() == 0) {
		output[0] = "";
		return 1;
	}
	int n = int(input[0] - '0');
	char ch = n + 'a' - 1;
	int s1 = getCodes(input.substr(1), output);
	for (int i = 0; i < s1; i++) {
		output[i] = ch + output[i];
	}
	int s2 = 0;
	if (input[1] != '\0') {
		n *= 10;
		n += input[1] - '0';
		ch = n + 'a' - 1;
		if (n >= 10 && n <= 26) {
			s2 = getCodes(input.substr(2), output + s1);
			for (int i = 0; i < s2; i++) {
				output[s1 + i] = ch + output[s1 + i];
			}
		}
	}
	return s1 + s2;
}



// Print Keypad Combinations Code

// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10 ^ 6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include <iostream>
#include <string>
using namespace std;

string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helper(int n, string output) {
	if (n == 0) {
		cout << output << endl;
		return;
	}
	string s = keys[n % 10];
	for (int i = 0; i < s.length(); i++) {
		helper(n / 10, s[i] + output);
	}
}

void printKeypad(int num) {
	string output = "";
	helper(num, output);
}

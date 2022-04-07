// Return Keypad Code

// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
//         Input Format :
// 	        Integer n
//         Output Format :
// 	        All possible strings in different lines
//         Constraints :
// 	        1 <= n <= 10 ^ 6
//         Sample Input :
// 	        23
//         Sample Output :
// 	        ad
// 	        ae
// 	        af
// 	        bd
// 	        be
// 	        bf
// 	        cd
// 	        ce
// 	        cf

#include <string>
using namespace std;

string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int n, string* output) {
	if (n == 0 || n == 1) {
		output[0] = "";
		return 1;
	}
	string curr = keys[n % 10];
	string smallOutput[500];
	int ssize = keypad(n / 10, smallOutput);
	int k = 0;
	for (int i = 0; i < curr.length(); i++) {
		for (int j = 0; j < ssize; j++) {
			output[k] = smallOutput[j] + curr[i];
			k++;
		}
	}
	return k;
}
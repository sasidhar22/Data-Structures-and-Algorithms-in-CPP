// Return Permutations - String

// Given a string S, find and return all the possible permutations of the input string.
//                                   Note 1 : The order of permutations is not important.
//                                   Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
//                                   Input Format :
//                                   String S
//                                   Output Format :
//                                   All permutations (in different lines)
//                                   Sample Input :
//                                   abc
//                                   Sample Output :
//                                   abc
//                                   acb
//                                   bac
//                                   bca
//                                   cab
//                                   cba


#include <string>
using namespace std;

//Approach: 1
int returnPermutations(string input, string output[]) {
	if (input.length() == 1) {
		output[0] = input;
		return 1;
	}
	char firstCharacter;
	string smallOutput[10000];
	int k = 0;
	int s;
	for (int i = 0; i < input.length(); i++) {
		firstCharacter = input[i];
		s = returnPermutations(input.substr(0, i) + input.substr(i + 1), smallOutput);
		for (int j = 0; j < s; j++) {
			output[k] = firstCharacter + smallOutput[j];
			k++;
		}
	}
	return k;
}


//Approach: 2
int returnPermutations(string input, string output[]) {
	if (input.length() == 1) {
		output[0] = input;
		return 1;
	}
	char character = input[0];
	int k = 0;
	int s;
	string smallOutput[100000];
	s = returnPermutations(input.substr(1), smallOutput);
	for (int j = 0; j < s; j++) {
		for (int l = 0; l <= smallOutput[j].length(); l++) {
			output[k] = smallOutput[j].substr(0, l) + character + smallOutput[j].substr(l);
			k++;
		}
	}
	return k;
}



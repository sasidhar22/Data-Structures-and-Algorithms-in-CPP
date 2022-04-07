int subs(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		reutrn 1;
	}
	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}







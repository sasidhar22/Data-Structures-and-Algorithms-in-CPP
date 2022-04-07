void subsequences(string input, string output = "") {
	if (input.empty()) {
		cout << output << endl;
	}
	subsequences(input.substr(1), output);
	subsequences(input.substr(1), output + input[0]);
}


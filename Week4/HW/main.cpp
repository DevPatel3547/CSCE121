#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
	cout << "String Calculator" << endl;
	cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

	bool Quit = false;

	while (!Quit) {

		cout << ">> ";
		string userinput;
		getline(cin, userinput);

		if (userinput == "quit" || userinput == "q") {
			Quit = true;
		}
		else {

			string str1;
			string str2;
			char op;
			int opPosition;
			int userinputLen = userinput.length();
			for (int i = 0; i < userinputLen; i++) {
				if (userinput.at(i) == ' ') {
					opPosition = i;
					i = userinputLen;
				}if (i == userinputLen) {
					continue;
				}
				else {
					str1.push_back(userinput.at(i));
				}
			}
			op = userinput.at(opPosition + 1);
			for (int i = opPosition + 3; i < userinputLen; i++) {
				str2.push_back(userinput.at(i));
			}

			string ans;
			if (op == '+') {
				ans = add(str1, str2);
			}
			if (op == '*') {
				ans = multiply(str1, str2);
			}
			cout << endl;
			cout << "ans =" << endl;
			cout << endl;
			cout << "    " << ans << endl;
			cout << endl;
		}
	}

	cout << "\nfarvel!" << endl;
}


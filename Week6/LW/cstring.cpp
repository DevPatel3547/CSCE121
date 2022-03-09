#include <iostream>
#include "cstring.h"

using namespace std;

unsigned int length(char str[]) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		count += 1;
	}
	return count;

}

unsigned int find(char str[], char character) {
	// returns 
	//  - the index of the first occurence of character in str
	//  - the size if the character is not found
	int toiterate = length(str);
	for (int i = 0; i < toiterate; ++i) {
		if (str[i] == character) {
			return i;
		}
	}
	return toiterate;
}
	


bool equalStr(char str1[], char str2[]) {

	int toiterate = length(str1);
	int toiterate1 = length(str2);
	if (toiterate != toiterate1) {
		return false;
	}
	for (int i = 0; i < toiterate; i) {
		if (str1[i] == str2[i]) {
			i = i + 1;
		}
		else {
			return false;
		}

		
	}
	return true;
}
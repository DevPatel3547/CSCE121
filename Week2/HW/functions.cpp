#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	if (a < 10 || a > 10000) {
		return false;
	}
	else if (b < 10 || b >= 10000) {
		return false;
	}
	else if (b < a) {
		return false;
	}
	else {
		return true;
	}
}


int countDigit(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return count;
}





char classify_mv_range_type(int number) {
	int digit, digit2;



	char identifier = 'N';
	while (number / 10 != 0) {
		digit = number % 10;
		number = number / 10;
		if (countDigit(number) != 1) {
			digit2 = number % 10;
		}
		else {
			digit2 = number;
		}

		if (digit2 < digit) {
			if (identifier == 'M') {
				return 'N';
			}
			else {
				identifier = 'M';
			}
		}
		else if (digit2 > digit) {
			if (identifier == 'V') {
				return 'N';
			}
			else {
				identifier = 'V';
			}
		}
		else if (digit2 == digit) {
			return 'N';
		}

	}
	return identifier;
}


void count_valid_mv_numbers(int a, int b) {
	int mcount = 0;
	int vcount = 0;
	int i = a;
	while (i != b + 1) {
		if (classify_mv_range_type(i) == 'M') {
			mcount = mcount + 1;
		}
		else if (classify_mv_range_type(i) == 'V') {
			vcount = vcount + 1;
		}
		i = i + 1;
	}
	cout << "There are " << mcount << " mountain ranges and " << vcount << " valley ranges between " << a << " and " << b << "." << endl;
}



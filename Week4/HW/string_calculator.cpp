#include <iostream>
#include <string>


using namespace std;

unsigned int digit_to_decimal(char digit) {
	if (digit == '1' || digit == '2' || digit == '3' || digit == '4' || digit == '5' || digit == '6' || digit == '7' || digit == '8' || digit == '9' || digit == '0') {
		int cti = (int)digit - 48;
		return cti;

	}
	else {
		throw std::invalid_argument("The argument is invalid");
	}
}

char decimal_to_digit(unsigned int decimal) {
	char aChar;

	switch (decimal)
	{
	case 0:
		aChar = '0';
		break;
	case 1:
		aChar = '1';
		break;
	case 2:
		aChar = '2';
		break;
	case 3:
		aChar = '3';
		break;
	case 4:
		aChar = '4';
		break;
	case 5:
		aChar = '5';
		break;
	case 6:
		aChar = '6';
		break;
	case 7:
		aChar = '7';
		break;
	case 8:
		aChar = '8';
		break;
	case 9:
		aChar = '9';
		break;
	default:
		throw std::invalid_argument("The argument is invalid");
	}
	return aChar;

}



string trim_leading_zeros(string num) {
	if (num == "-00000") {
		return "0";
	}
	else if (num.at(0) == '-') {
		num.at(0) = '0';
		num.erase(0, min(num.find_first_not_of('0'), num.size() - 1));
		string str2 = "-";
		num.insert(0, str2);
		return num;
	}
	else {
		num.erase(0, min(num.find_first_not_of('0'), num.size() - 1));
		return num;
	}
}




string reverseStr(string str) {
	int n = str.length();


	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
	return str;
}





string add(string lhs, string rhs) {

	if (lhs.length() > rhs.length())
		swap(lhs, rhs);

	string str = "";

	int n1 = lhs.length(), n2 = rhs.length();





	lhs = reverseStr(lhs);
	rhs = reverseStr(rhs);

	int carryover = 0;
	for (int i = 0; i < n1; i++)
	{
		int sum = ((lhs[i] - '0') + (rhs[i] - '0') + carryover);
		str.push_back(sum % 10 + '0');
		carryover = sum / 10;
	}

	for (int i = n1; i < n2; i++)
	{
		int sum = ((rhs[i] - '0') + carryover);
		str.push_back(sum % 10 + '0');
		carryover = sum / 10;
	}
	if (carryover)
		str.push_back(carryover + '0');


	return reverseStr(str);
}

















string multiply(string lhs, string rhs) {
	if (lhs.at(0) == '-' && rhs.at(0) == '-') {
		lhs.at(0) = '0';
		rhs.at(0) = '0';

	}
	int o = lhs.size();
	int l = rhs.size();
	string Ans(o + l, '0');
	for (int i = o - 1; i >= 0; --i) {
		for (int j = l - 1; j >= 0; --j) {
			int p = (lhs[i] - '0') * (rhs[j] - '0') + (Ans[i + j +
				1] - '0');
			Ans[i + j + 1] = p % 10 + '0';
			Ans[i + j] += p / 10;
		}
	}
	for (int i = 0; i < l + o; i++) {
		if (Ans[i] != '0')return Ans.substr(i);
	}
	return "0";
}




string subtract(string lhs, string rhs)
{
	string str = "";
	int n1 = lhs.length(), n2 = rhs.length();
	reverseStr(lhs);
	reverseStr(rhs);
	int carryover = 0;
	for (int i = 0; i < n2; i++) {
		int sub
			= ((lhs[i] - '0') - (rhs[i] - '0') - carryover);
		if (sub < 0) {
			sub = sub + 10;
			carryover = 1;
		}
		else
			carryover = 0;
		str.push_back(sub + '0');
	}
	for (int i = n2; i < n1; i++) {
		int sub = ((lhs[i] - '0') - carryover);
		if (sub < 0) {
			sub = sub + 10;
			carryover = 1;
		}
		else
			carryover = 0;
		str.push_back(sub + '0');
	}
	return str;
}








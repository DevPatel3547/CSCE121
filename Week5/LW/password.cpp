#include <iostream>
#include <string>
using namespace std;


string reverseStr(string str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}





int main() {
    string userinput;
    cout << "Please enter your text input: ";
    cin >> userinput;
    cout << "input: " << userinput << endl;
    for (int i = 0; i < userinput.length(); i++) {
        switch (userinput[i]) {
        case 'a':
            userinput.at(i) = '@';
            break;
        case 'e':
            userinput.at(i) = '3';
            break;
        case 'i':
            userinput.at(i) = '!';
            break;
        case 'o':
            userinput.at(i) = '0';
            break;
        case 'u':
            userinput.at(i) = '^';
            break;

        }
    }
    string str2 = reverseStr(userinput);
    userinput.append(str2);
    cout << "output: " << userinput;
    return 0;
}

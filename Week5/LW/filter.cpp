#include <iostream>
#include <string>
using namespace std;

void findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr)
{
    size_t pos = data.find(toSearch);
    while (pos != std::string::npos)
    {
        data.replace(pos, toSearch.size(), replaceStr);
        pos = data.find(toSearch, pos + replaceStr.size());
    }
}



int main() {
    string userinput;
    string userword;
    cout << "Please enter the sentence: ";
    getline(cin, userinput);
    cout << "Please enter the filter word: ";
    cin >> userword;
    int lengthword = userword.length();
    string replaceword(lengthword, '#');
    findAndReplaceAll(userinput, userword, replaceword);
    cout<< "Filtered sentence: " << userinput << endl;
    return 0;

}








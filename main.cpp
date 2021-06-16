#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "IntentType.h"

using namespace std; 

vector<string> pharseStringToWords(string str)
{
    istringstream ss(str);
    string single_word;
    vector<string> words;

    while( ss >> single_word )
    {
        words.push_back(single_word);
    }

    return words;

}


int main()
{
    string str;
    // bool extended;
    // set value of extended

    cout << "Enter a sentence" << endl;
    getline(cin, str);

    vector<string> words = pharseStringToWords(str);
    IntentType intent(words);
    cout << intent.getType() << endl;
  
    return 0;
}
#ifndef INTENT_TYPE_H
#define INTENT_TYPE_H 
#include <string>
#include <vector>

using namespace std;

/*
To change the clues, edit the the relevant vector values 
*/

static vector<string> weatherClues{"weather", "forecast"};
static vector<string> factClues{"interesting", "tell", "something"};
static vector<string> timeClues{"today", "tomorrow", "yesterday"};
static vector<string> expectedTime{"next", "last", "on", "at"};


class IntentType
{
private:
    string type;
    string city;
    string time;
    
public:
    explicit IntentType(const string & sentence);
    ~IntentType();
    string getType();
    string getCity();
    string getTime();
    static vector<string> sentenceToParams(const vector<string> & words);
    static vector<string> pharseStringToWords(const string & str);
};

#endif //INTENT_TYPE_H

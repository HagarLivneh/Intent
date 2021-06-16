#ifndef INTENT_TYPE_H
#define INTENT_TYPE_H
#include <string>
#include <vector>

using namespace std;

class IntentType
{
private:
    string type = "Intent Not Found";
    string city;
    string time;
    
public:
    explicit IntentType(const vector<string> & words);
    ~IntentType();
    string getType();
    string getCity();
    string getTime();
    static vector<string> sentenceToParams(const vector<string> & words);
};

#endif //INTENT_TYPE_H

#include "IntentType.h"
#include <iostream>

IntentType::IntentType(const vector<string> & words)
{
    vector<string> params = sentenceToParams(words);
    this->type = params[0];
    this->city = params[1];
    this->time = params[2];
}

vector<string> IntentType::sentenceToParams(const vector<string> & words)
{
    vector<string> params;
    string city = "";
    //Basic case
    bool expect_city = false;
    bool expect_time = false;
    string timePhrase = "";
    bool hasWeather = false;
    bool hasFactClue = false;
    string chars = "!?-,.()";

    for (auto word : words)
    {
        for (int i = 0; i < word.size(); i++) 
        {
            //for case-insensitive comparison
            if (word[i] >= 'A' && word[i] <= 'Z')
                word[i]= tolower(word[i]);
            
            //special character
            else if (word[i] < 'a' || word[i] > 'z')
            {
                word.erase(i, 1);
                i--;
            }
        }

        if(expect_city)
        {
            expect_city = false;
            city = word;
        }
        else if(expect_time)
        {
            expect_time = false;
            timePhrase += " "+ word;
        }
        if(word.compare("fact") == 0 || word.compare("interesting") == 0 || word.compare("tell") == 0 || word.compare("something") == 0)
            hasFactClue = true;
        
        else if(word.compare("weather") == 0 || word.compare("forecast") == 0)
            hasWeather= true;
        
        else if(word.compare("in") == 0)
            expect_city = true;
        
        else if(word.compare("at") == 0 || word.compare("on") == 0 || word.compare("next") == 0 || word.compare("last") == 0)
        {
            expect_time = true;
            timePhrase =word;
        }
        else if(word.compare("today") == 0 || word.compare("tomorrow") == 0 || word.compare("yesterday") == 0)
        {
            timePhrase = word;
        }    
    }
    string type= hasWeather ? city.empty() ? "Get Weather" : "Get Weather City": hasFactClue? "Get Fact": "Intent Not Found";
    //params: 0-type 1-city 2-timePhrase
    params.push_back(type);
    params.push_back(city);
    params.push_back(timePhrase);
    return params;
}

IntentType::~IntentType()
{}

string IntentType::getType()
{
    return type;
}
string IntentType::getCity()
{
    return city;
}

string IntentType::getTime()
{
    return time;
}


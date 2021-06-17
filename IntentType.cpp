#include "IntentType.h"
#include <iostream>
#include <sstream>
#include <vector>


vector<string> IntentType:: pharseStringToWords(const string & str)
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

IntentType::IntentType(const string & sentence)
{
    vector<string> words = pharseStringToWords(sentence);
    vector<string> params = sentenceToParams(words);
    this->type = params[0];
    this->city = params[1];
    this->time = params[2];
}

vector<string> IntentType::sentenceToParams(const vector<string> & words)
{
    vector<string> params;
    string city;
    string type;
    //init flags for finding words
    bool expect_city = false;
    bool expect_time = false;
    bool hasWeather = false;
    bool hasFactClue = false;
    string timePhrase = "";

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

        if (find(factClues.begin(), factClues.end(), word) != factClues.end() )
            hasFactClue = true;
        
        else if (find(weatherClues.begin(), weatherClues.end(), word) != weatherClues.end() )
            hasWeather= true;
        
        else if(word.compare("in") == 0)
            expect_city = true;
        
        else if (find(expectedTime.begin(), expectedTime.end(), word) != expectedTime.end() )
        {
            expect_time = true;
            timePhrase = word;
        }
        else if (find(timeClues.begin(), timeClues.end(), word) != timeClues.end() )
        {
            timePhrase = word;
        }    
    }
    type= hasWeather ? city.empty() ? "Get Weather" : "Get Weather City": hasFactClue? "Get Fact": "Intent Not Found";
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
    return this->type;
}
string IntentType::getCity()
{
    return this->city;
}

string IntentType::getTime()
{
    return this->time;
}


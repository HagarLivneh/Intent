#include <iostream>
#include <string>
#include "../IntentType.h"

using namespace std; 

int main()
{
    string str;

    cout << "Enter a sentence" << endl;
    getline(cin, str);
    IntentType intent(str);
    cout << intent.getType() << endl;
  
    return 0;
}
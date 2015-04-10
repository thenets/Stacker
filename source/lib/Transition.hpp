#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Transition Class
    
    Constructor Params:
        @ string name;
        @ string input;
        @ string check;
        @ string modification;
        @ string go_to;
*/
class Transition {
    public:
        string input;
        string check;
        string modification;
        string go_to;
        
        Transition (string a_input, string a_check, string a_modification, string a_go_to) {
            input.assign(a_input);
            check.assign(a_check);
            modification.assign(a_modification);
            go_to.assign(a_go_to);
        }
        
        void debug () {
            // cout << "--DEBUG--" << endl;
            //cout << "|-- DEBUG Transitions" << endl;
            // cout << "--DEBUG--" << endl;
            
            cout << "  |-- " << input << endl;
            cout << "  |-- " << check << endl;
            cout << "  |-- " << modification << endl;
            cout << "  |-- " << go_to << endl << endl;
        }
};

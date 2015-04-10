#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Transition.hpp"

using namespace std;


class State {
    vector<Transition> transitions;
    
    public:
        string name;
        int id;
        
        void setName (string a_name) {
            name = a_name;
        }
        
        vector<Transition> getTransitions () {
            return transitions;
        }
    
        void add (string a_input, string a_check, string a_modification, string a_go_to) {
            Transition tmp (a_input, a_check, a_modification, a_go_to);
            transitions.push_back ( tmp );
        }
        
        void debug() {
            cout <<  "|-- " << name << endl;
            for (int i=0; i<transitions.size(); i++) {
                transitions.at(i).debug();
            }
        }
};
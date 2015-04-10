#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void loadStates(vector<string> &vec);
void removeComments(string &txt);



/*
    Get file content and pass to a array
    @pass &vector<string>
*/
void loadStates (vector<State> &states) {
    // Open file
    ifstream ifs("stack.txt");
    string content;
    content.assign( (istreambuf_iterator<char>(ifs) ),
                    (istreambuf_iterator<char>()    )
    );
    
    // Remove all comments
    removeComments(content);
    
    // Remove all break lines
    content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());
    
    // Remove all spaces
    content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
    
    
    
    // Current state
    State stateTmp;
    
    // Transition attributes
    vector<string> attr;
    
    // Transitions of current state
    vector<string> transitionsTmp;
    
    // Tokens
    string tokenState;
    istringstream ssState(content);
    istringstream ssTransition;
    
    // STATE Get each state to a line
    int stateTmp_id=0;
    while(std::getline(ssState, tokenState, ';')) {
        //std::replace( s.begin(), s.end(), 'x', 'y'); // replace all 'x' to 'y'
        //vec.push_back( State  );
        
        // Actual state
        State stateTmp;
        
        // TRANSITION Get each transition to a line
        ssTransition.str(tokenState);
        string tokenTransition;
        int i=0;
        
        // After while, the "transitionsTmp" will be filled with all
        // transitions of actual state
        while(std::getline(ssTransition , tokenTransition, '(') ) {
            tokenTransition.erase(std::remove(tokenTransition.begin(), tokenTransition.end(), ')'), tokenTransition.end());
            
            // Is name of state
            if (i == 0) { 
                stateTmp.setName( tokenTransition );
            }
            
            // Is a transition
            else {
                transitionsTmp.push_back(tokenTransition);    
                
                //cout << transitionsTmp.back() << " ";
            }
            
            i++;
        }
        
        // Set State ID to "stateTmp"
        stateTmp.id = stateTmp_id;
        stateTmp_id++;
        
        
        // Add a transtition to "stateTmp"
        for (int i=0; i<transitionsTmp.size(); i++) {
            
            // Create a vector of current transition with each attr
            string tokenAttr;
            istringstream ssAttr;
            ssAttr.str( transitionsTmp.at(i) );
            vector<string> transitionTmp;
            while(std::getline(ssAttr , tokenAttr, ',') ) {
                transitionTmp.push_back (tokenAttr);
            }
            
            // Add "transitionTmp" to "stateTmp"
            stateTmp.add (transitionTmp.at(0), transitionTmp.at(1), transitionTmp.at(2), transitionTmp.at(3));
        }
        
        // Add "stateTmp" to main vector "states"
        states.push_back (stateTmp);
        
        // Clear transitions data to return the loop
        ssTransition.clear();
        transitionsTmp.clear();
    }
    
}


/*
    Get word from file "word.txt"
*/
void loadWord (string &word) {
    // Open file
    ifstream ifs("word.txt");
    string content;
    word.assign( (istreambuf_iterator<char>(ifs) ),
                    (istreambuf_iterator<char>()    )
    );
    word = "*"+word+"*";
}

/*
// Remove all comments
*/
void removeComments (string &txt) {
    
}
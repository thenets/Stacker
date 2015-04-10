#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


void debug (vector<State> &states);
int findState (vector<State> &states, string stateName);


/*
    getStateId
    
    Params:
        @ vector<State> &states; // array of states and transitions
        @ string stateName; // state name that want to be find
        
    Return:
        int state_id // ID of state.at(state_id)
        int -1 // If not found
        
    Example:
        int id = getStateId (states, "q2");
*/
int getStateId (vector<State> &states, string stateName) {
    int state_id = -1;
    
    for (int i=0; i<states.size(); i++) {
        // If two string is equals
        if (states.at(i).name.compare(stateName) == 0) {
            state_id = i;
        }
    }
    
    return state_id;
}


/*
    getStateById
    
    Params:
        @ vector<State> &states; // array of states and transitions
        @ int id; // id that want to be find
        
    Return:
        State state // State if correspondent id
        
    Example:
        State state = getStateById (states, 1);
*/
State getStateById (vector<State> &states, int id) {
    
    for (int i=0; i<states.size(); i++) {
        // If ID was found, return the state
        if (states.at(i).id == id) {
            return states.at(i);
        }
    }
    
}



/*
    Debug
*/
void debug (vector<State> &states, string &stack, string &word, bool &finish, string &errors) {
    if (errors.size() > 0) {
        cout << "|== Debug" << endl;
        cout << "| Word:  " << word << endl;
        cout << "| Stack: " << stack << endl;
        cout << "| Erros: " << errors << endl;
        
        cout << endl;
        
        // Lista todos os estados e transições
        for (int i=0; i<states.size(); i++) {
            //states.at(i).debug();
        }
            
    }
}
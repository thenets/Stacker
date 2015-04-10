#include "lib/State.hpp"
#include "lib/Thread.hpp"
#include "lib/format.hpp"
#include "lib/help.hpp"


int init ();


/*
    Init function
    
    Params:
        @ vector<State> &states; // array of states and transitions
        @ vector<string> &stack; // main stack
        @ string &word; // word
        @ int &state; // actual state ID
        
        @ bool &finish; // check if app get the end
        @ string &errors; // store any error messages
*/
int init (vector<State> &states, string &stack, string &word, bool &finish, string &errors) {
    // Get content from file
    loadStates(states);
    
    // Load word
    loadWord(word);
    
    
    // ========================================================================
    cout << "|== Compiling stack..." << endl << endl;
    
    // Create a new thread
    Thread thread (states, word, stack, finish, errors);
    
    // Run all transitions until get finished
    //cout << "|= Make transitions...\n|" << endl;
    int i=0;
    while (finish == false) {
        //states.at(0).debug();
        thread.runTransition(states, word, stack, finish, errors);
        
        
        // Check infinity loop
        if(i==1000) {
            cout << "| ERROR Infinity loop!" << endl;
            finish = true;
        }
        i++;
    }
    
    
    
    cout << endl;
    // ========================================================================
    
    return 0;
}

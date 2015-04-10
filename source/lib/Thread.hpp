#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


/*
    Thread Class
*/
class Thread {
    private:
        int next; // Id of current position in mat
        State state; // Current state
        int state_id;
        
        
        /* 
            Get current position at word to be processed
        */
        int current () { return next-1; }
        
        
        
    public:
        /*
            Constructor
        */
        Thread (vector<State> &states, string &word, string &stack, bool &finish, string &errors) {
            this->next = 1;
            this->state_id = 0;
            //cout << "| LOG Starting thread..." << endl << endl;
        }
        
        
        /*
            Make a transition
        */
        void runTransition (vector<State> &states, string &word, string &stack, bool &finish, string &errors) {
            state = states.at(state_id);
            
            bool hasTransition = false; // Check if has a transition
            bool success = false; // Check if get a success compile
            string wordTmp = word; // Word with letters processed removed
            vector<Transition> t = state.getTransitions(); // Shortcut
            char letter = wordTmp.at(current());
            string nextStateName;
            
            // Get stack last char
            char stackLastChar = stack.at( stack.size()-1 );
            string stackOperation = " ";
            
            // Format wordTmp
            wordTmp.replace(0, current(), std::string(current(), ' '));
            
            // If first transition
            if (current() == 0) {
                cout << "| " << wordTmp << " | " << letter << " | S  -> " << state.name << " | "+stackOperation+" "+stack << endl;
            } 
            
            // If isn't first transition
            else {
                // == Find a combination
                for (int i=0; i<t.size(); i++) {
                    // If find a transition
                    if (t.at(i).input.at(0) == letter && t.at(i).check.at(0) == stackLastChar) {
                        
                        // ==== Update Stack ========
                        // Keep data
                        if ( t.at(i).modification.at(0) == string("=").at(0) ){
                            // do nothing...
                            stackOperation = "=";
                        }
                            
                        // Remove data
                        if ( t.at(i).modification.at(0) == string("-").at(0) ) {
                            stackOperation = "-";
                            
                            stack = stack.substr(0, stack.size()-1);
                        }
                        
                        // Add data
                        if (t.at(i).modification.at(0) != '=' && t.at(i).modification.at(0) != '-' ) {
                            stackOperation = "+";
                            
                            stack = stack + t.at(i).modification ;
                        }
                        
                        // ==========================
                        
                        
                        // Check if get the end
                        //cout << stack << endl;
                        if ( t.at(i).go_to.find(string("end")) != string::npos ) {
                            finish = true;
                            success = true;
                            cout << "\n| SUCCESS! Word recognized!" << endl;
                        }
                        
                        // Set next state
                        state_id = Thread::getStateId(states, t.at(i).go_to);
                        
                        // Set next state name just for console output
                        nextStateName = t.at(i).go_to;
                        
                        hasTransition = true;
                   }
                }
                // == end
                
                
                
                
                
                // ============== Output ==============
                // Console log if all ok in transition
                if (!success && hasTransition && wordTmp.size() != next)
                    cout << "| " << wordTmp << " | " << letter << " | " << state.name+" -> "+nextStateName << " | "+stackOperation+" "+stack << endl;
                // Error message if hasn't a transition
                if (!hasTransition) {
                    cout << "| " << wordTmp << " | " << letter << " | " << state.name+" -> "+"NULL" << endl;
                    errors = errors + "\n|-- ERROR Hasn't a transition!";
                    finish = true;
                }
                // Check if finish and word hasn't been recoginized
                if (!success && hasTransition && wordTmp.size() == next) {
                    errors = errors + "\n|-- ERROR Word not recoginized!";
                    finish = true;
                }
                // ====================================    
            }
            
                
            // Go to next letter and next state
            //if (current() != 0)
            next++;
        }
        
        
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
        
};
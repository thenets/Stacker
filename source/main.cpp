/*
    Stacker
    
    Simulador de execução de automatos de pilha.
    
    by Luiz Felipe F M Costa - contact@thenets.org
*/
#include <iostream>
#include "init.cpp"

using namespace std;


/*
    Main function
*/
int main (int argc, char** argv) {
    /*
        Main vars
    */
    vector<State> states; // array of states and transitions
    string stack = "*"; // main stack
    string word = ""; // word
    
    bool finish = false; // check if app get the end
    string errors = ""; // store any error messages
    
    
    
    /*
        Initialize the compiller
    */
    init (states, stack, word, finish, errors);
    
    
    
    
    /*
        Debug states content
    */
    debug (states, stack, word, finish, errors);
    
    
    
    return 0;
}
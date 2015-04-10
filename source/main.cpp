/*
    Stacker
    
    Simulador de execução de automatos de pilha.
    
    by Luiz Felipe F M Costa - contact@thenets.org
*/
#include <iostream>
#include <chrono>
#include <thread>
#include "init.cpp"

using namespace std;


/*
    Main function
*/
int main (int argc, char** argv) {
    // BENCHMARK Time 1
    auto t1 = std::chrono::high_resolution_clock::now();
    
    
    
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
    
    
    
    
    // BENCHMARK Time 1
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "| Execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " seconds\n";
    
    return 0;
}
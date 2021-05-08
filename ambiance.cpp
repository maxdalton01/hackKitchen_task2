#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int main() {
    
    string file = "ambiance.mp3";
    
    // trouble figuring out how to terminate background commands, so play only 5 times
    // shell command for running afplay in a loop 5 times in the background
    string command = "(for i in {1..5}; do afplay " + file + " &>/dev/null; done &) & RUNNING_PID=$!";
    system(command.c_str()); // runs above command
}

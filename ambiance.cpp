#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string file = "ambiance.mp3";
    string command = "while :; do afplay " + file + " &>/dev/null &; done";
    system(command.c_str());
    cout << "Sound is playing! do you like?" << endl;
    string userInput;
    getline(cin, userInput);
    cout << "You said " + userInput << endl;
    
    command = "killall afplay";
    system(command.c_str());
}

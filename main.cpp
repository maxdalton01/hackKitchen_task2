// include statements
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "ambiance.cpp"

using namespace std;

class foodItem{
    public:
        foodItem(){
            price = 0;
            name = "";
            course = '0';
        }
        foodItem(string food, int cost, char type){
            price = cost;
            name = food;
            course = type;
        }
        int price;
        string name;
        char course;
};


void displayStarters(foodItem menu[]) {
    cout << "Please choose an entree number\n";
   for (int i = 0; i < 5; i++){
       cout << i + 1 << ". " << menu[i].name << "\n";
    }
    cout << "\n";
}

void displayEntrees(foodItem menu[]) {
    cout << "Please choose a side number\n";
    int j = 1;
   for (int i = 5; i < 10; i++){
       cout << j << ". " << menu[i].name << "\n";
       j++;
    }
    cout << "\n";
}

void displayDesserts(foodItem menu[]) {
    cout << "Please choose a dessert number\n";
   int j = 1;
   for (int i = 10; i < 15; i++){
       cout << j << ". " << menu[i].name << "\n";
       j++;
    }
    cout << "\n";
}


string getFileContents(ifstream& file)
{
    string lines = ""; // all lines
    if (file)          // check if everything is good
    {
	    while (file.good())
	    {
	        string templine;                  //Temp line
	        getline (file , templine);        //Get temp line
	        templine += "\n";                      //Add newline character
	        lines += templine;                     //Add newline
	    }
	    return lines;
    }
    else //Return error
    {
	    return "ERROR File does not exist.";
    }
}

void printArt(const string& file)
{
    string art;
    ifstream myfile;
    myfile.open(file.c_str()); //Open file
    art = getFileContents(myfile); //Get file
    cout << art << endl;             //Print it to the screen
    myfile.close();                           //Close file
}

int main()
{
    playAmbiance();
    //system ("CLS"); // clear the screen
    chrono::milliseconds timespan(3000);
    std::this_thread::sleep_for(timespan); // in milliseconds
    cout << "Hello! Welcome to the Beaver Restaurant!" << endl;
    printArt("restaurant.txt");
    std::this_thread::sleep_for(timespan);
    //system("CLS");
    printArt("waiter.txt");
    cout << "Master Ramsey will take you to your table." << endl;
    std::this_thread::sleep_for(timespan);
    
    
    
    
    string foodName[15] = {"Corned Beef", "BBQ Pork Sliders", "Grilled Chicken Sandwich", "Jumbo Hot Dog", "Rack of Ribs", "Home Fries", "Fruit Salad", "Caeser Salad", "Coleslaw", "Tater Tots", "Bread Pudding", "Chocolate Ice Cream", "Vanilla Ice Cream", "Apple Pie", "Blueberry Cobbler"};
    int foodCost[15] = {25, 23, 21, 15, 42, 8, 6, 7, 5, 8, 15, 12, 12, 15, 15};
    foodItem menu[15];
    for (int i = 0; i < 15; i++){
        if (i < 5){
            menu[i] = foodItem(foodName[i], foodCost[i], 'a');
        }else if(i < 10){
            menu[i] = foodItem(foodName[i], foodCost[i], 'b');
        }else{
            menu[i] = foodItem(foodName[i], foodCost[i], 'c');
        }
    }
    
    int userNumber[3];
    displayStarters(menu);
    cin >> userNumber[0];
    cout << "Excellent choice, monsieur." << endl;
    displayEntrees(menu);
    cin >> userNumber[1];
    cout << "I would've gone a different route, but to each his own." << endl;
    displayDesserts(menu);
    cin >> userNumber[2];
    cout << "It's dessert, so you can't really go wrong." << endl;
    
    
    double finalBill = (double) (menu[userNumber[0] - 1].price + menu[4 + userNumber[1]].price + menu[userNumber[2] + 9].price);
    
    cout << "Now for the fun part. Your final bill is: " << finalBill << endl;
    cout << "What percentage would you like to tip?" << endl;
    double userDouble;
    cin >> userDouble;
    finalBill = (userDouble / 100) * finalBill + finalBill;
    cout << "Excellent, so with tip, your bill is now " << finalBill << endl;
    
    cout << "Thank you for dining at the Beaver Restaurant!" << endl;
    
}


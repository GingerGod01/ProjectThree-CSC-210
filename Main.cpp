//Andrew Michael Robles
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

void createItemMap(map<string, int>& groceryList){
    //creates the map by opening input file and looping through and adding one for every duplicate item
    string itemFromFile;
    ifstream inFS;                                      //input file stream

    inFS.open("CS210_Project_Three_Input_File.txt");
    while (!inFS.fail()){     
        inFS >> itemFromFile;
        if (groceryList.count(itemFromFile) == 0){
            groceryList.emplace(itemFromFile, 1);
        }
        else {
            groceryList.at(itemFromFile) += 1;
        }
    }
    inFS.close();
}

void outputItemFrequency(map<string, int>& groceryList){
    //gets info from map and outputs the item and total number of items to Frequency.dat file
    //****ALWAYS RUNS SO IT CAN GET ACCURATE COUNT****        
    ofstream outFS;                                     //output file stream
    outFS.open("Frequency.dat");                        //opens file

    for (const auto& x : groceryList){                  // for loop that prints out each part of the map into .dat file
        outFS << x.first << ": " << x.second << endl;
    }
    outFS.close();                  //closes file
}

int main(){  
    map<string, int> groceryList;               //map creation
    createItemMap(groceryList);
    outputItemFrequency(groceryList);
    //global variables
    int menuChoice = 0;

    while (menuChoice != 4){
        cin >> menuChoice;                            

        if (menuChoice == 1){
            //only returns a numerical value
            string itemChoice;
            cin >> itemChoice;                                     
            try {
                cout << groceryList.at(itemChoice);}
            catch (const out_of_range &error){
                cout << itemChoice << " is not in list." << endl;
                }                 
        } 

        else if (menuChoice == 2){
            //returns a long string of input file with name of item and how many times it appears in file
            for (const auto& x : groceryList){                  // for loop that prints out each part of the map
                cout << x.first << " " << x.second << endl;
                }
        }

        else if (menuChoice == 3){
            //outputs a hisogram of items in file
            for (const auto& x : groceryList){                  // for loop that prints out each part of the map
                cout << x.first << " " << string(x.second, '*') << endl;
                }
        }
        
        else {
            //outputs if user does not input a number 1-4 inclusive
            cout << "INVALID MENU OPTION";
        }
    }


}

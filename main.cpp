//test file for monte carlo tree

//it works tho // the text file is sourced from my DSA class

#include<iostream>
#include<fstream>
#include "MonteCarlo.h"

using namespace std;

int main() {

    MonteCarlo mcTree;

    ifstream inFile;
    string fileName = "win_loss_streaks.txt";
    string line = "";

    mcTree.buildTree(3,2);
    cout << mcTree.print(0, mcTree.getRoot());

    inFile.open(fileName);

    if (inFile.is_open())
    {
        // read through file
        while (getline(inFile, line))
        {
            bool result = line == "win" ? true : false;
            mcTree.select();
            mcTree.backpropagate(result);
        }

        inFile.close();
    }


    cout <<"after\n" << mcTree.print(0, mcTree.getRoot());
    return 0;
}
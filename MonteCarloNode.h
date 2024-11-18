#ifndef MONTECARLONODE_H
#define MONTECARLONODE_H

#include <string>
#include <vector>

class MonteCarloNode {
    private:
        std::string label;
        int numChildren;
        int visits;     
        int wins;    
        MonteCarloNode* parent; // Pointer to the parent node
        MonteCarloNode** childNodes; // Pointer to Array of child nodes pointers

    public:
        MonteCarloNode(int visits = 0, int wins = 0, int numChildren = 0, std::string l = "");

        int getVisits();

        int getWins();

        int getNumChildren();

        bool hasChildren();

        MonteCarloNode* getParent();

        MonteCarloNode* getChild(int index); 

        bool setParent(MonteCarloNode* newParent);
        
        void setWins(int amount);

        void setVisits(int amount);

        bool appendChildren(int children = 1, std::vector<MonteCarloNode*> nodes = {nullptr});

        ~MonteCarloNode();


};

#endif
#include "MonteCarloNode.h"


MonteCarloNode::MonteCarloNode(int visits, int wins, int numChildren, std::string l)
    : visits(visits), wins(wins), numChildren(numChildren), parent(nullptr), label(l) {
    if (numChildren > 0) {
        childNodes = new MonteCarloNode*[numChildren];
        for (int i = 0; i < numChildren; i++) {
            childNodes[i] = nullptr;
        }
    } else {
        childNodes = nullptr;
    }
}

int MonteCarloNode::getVisits() {
    return visits;
}

int MonteCarloNode::getWins() {
    return wins;
}

int MonteCarloNode::getNumChildren() {
    return numChildren;
}

bool MonteCarloNode::hasChildren() {
    return (numChildren > 0);
}

MonteCarloNode* MonteCarloNode::getParent() {
    return parent;
}

MonteCarloNode* MonteCarloNode::getChild(int index) {
    if (index < numChildren) {
        return childNodes[index];
    }
    return nullptr;
}

bool MonteCarloNode::setParent(MonteCarloNode* newParent) {
    parent = newParent;
    return true;
    //add error checking later
}

void MonteCarloNode::setWins(int amount) {
    wins = amount;
}

void MonteCarloNode::setVisits(int amount) {
    visits = amount;
}

bool MonteCarloNode::appendChildren(int children, std::vector<MonteCarloNode*> nodes) {
    if (numChildren == 0 && children > 0) {
        numChildren = children;
        childNodes = new MonteCarloNode* [numChildren];
        for (int i = 0; i < numChildren; i++) {
            childNodes[i] = nodes[i];
            childNodes[i]->setParent(this);
        }
        return true;    
    }
    return false;
}

MonteCarloNode::~MonteCarloNode() {
    for (int i = 0; i < numChildren; ++i) {
        delete childNodes[i];
    }
    delete[] childNodes;
    childNodes = nullptr;
    numChildren = 0;
}
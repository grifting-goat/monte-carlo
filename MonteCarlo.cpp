
#include "MonteCarlo.h"
#include "MonteCarloNode.h"

#include <vector>
#include <algorithm>

MonteCarlo::MonteCarlo() {
    root = new MonteCarloNode;
    head = root;

}

MonteCarloNode* MonteCarlo::getRoot() {
    return root;
}

void MonteCarlo::resetHead() {
    head = root;
}

void MonteCarlo::buildTree(int depth, int children) {
    resetHead();
    buildTreeRecursive(head, depth, children, 0);
}

void MonteCarlo::buildTreeRecursive(MonteCarloNode* currentNode, int depth, int children, int currentDepth) {

    if (currentDepth >= depth) {
        return;
    }

    std::vector<MonteCarloNode*> vNode(children, new MonteCarloNode(rand()%23,rand()%23));
    currentNode->appendChildren(children, vNode);

    //Recursive
    for (int i = 0; i < children; i++) {
        buildTreeRecursive(currentNode->getChild(i), depth, children, currentDepth + 1);
    }
}

void MonteCarlo::appendChildren(int children, std::vector<MonteCarloNode*> nodes) {
    head->appendChildren(children, nodes);
}

void MonteCarlo::select() {
    std::vector<float> vRatio;
    if (head->hasChildren()) {
        for (int i = 0; i < head->getNumChildren(); i++) {
            vRatio.push_back((float)head->getWins() / (float)head->getVisits());
        }

        // Find index of the max ratio
        auto maxIt = std::max_element(vRatio.begin(), vRatio.end());
        int index = std::distance(vRatio.begin(), maxIt);

        //update the head
        head = head->getChild(index);
        select();
    }

}

void MonteCarlo::backpropagate(bool win)
{
    head->setVisits(head->getVisits() + 1); //increment visit counter
    head->setWins(head->getWins()+ win); //add a win if it won

    if (head->getParent() != nullptr) {
        head = head->getParent();
        backpropagate(win); //go to previous nodes
    }
}


void MonteCarlo::deleteSubtree(MonteCarloNode* node) {
    if (!node) {
        return; //Base case
    }

    //delete all child nodes
    for (int i = 0; i < node->getNumChildren(); ++i) {
        deleteSubtree(node->getChild(i));
    }

    delete node;
}

std::string MonteCarlo::print(int depth, MonteCarloNode* node) {
    if (!node) return ""; // Base case

    std::string toReturn = "";

    for (int i = 0; i < depth; i++) {
        toReturn += "  ";
    }
    toReturn += "-" + std::to_string(depth) + " [visits: " + std::to_string(node->getVisits()) +
                ", wins: " + std::to_string(node->getWins()) + "]\n";
    //recursion!
    for (int i = 0; i < node->getNumChildren(); i++) {
        toReturn += print(depth + 1, node->getChild(i));
    }

    return toReturn;
}
MonteCarlo::~MonteCarlo() {
    resetHead();
    deleteSubtree(root);
}
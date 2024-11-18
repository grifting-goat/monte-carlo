#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "MonteCarloNode.h"

class MonteCarlo {

    private:
        MonteCarloNode* root;
        MonteCarloNode* head;

        /**
         * @brief deletes a subtree
         * 
         * @param node 
         * @return * void 
         */
        void deleteSubtree(MonteCarloNode* node);
        /**
         * @brief builds a tree recursivly
         * 
         * @param currentNode 
         * @param depth 
         * @param children 
         * @param currentDepth 
         */
        void MonteCarlo::buildTreeRecursive(MonteCarloNode* currentNode, int depth, int children, int currentDepth);

    public:

     

    //constructor
    MonteCarlo();

    MonteCarloNode* getRoot(); 

    /**
     * @brief sets the head back to the root
     * 
     */
    void resetHead();

    /**
     * @brief builds a tree to test or something
     * 
     */
    void buildTree(int depth, int children);


    //adds children
    void appendChildren(int children, std::vector<MonteCarloNode*> nodes);

    /**
     * @brief moves the head to a leaf node following the highest Win to visit ratio
     * 
     */
    void select();

    /**
     * @brief backpropgates a result throughout the tree, moves the head to the root
     * 
     * @param win 
     */
    void backpropagate(bool win);


    /**
     * @brief prints out cool stuff
     * 
     * @param depth node
     * @return std::string 
     */
    std::string MonteCarlo::print(int depth = 0, MonteCarloNode* node = nullptr);

    //destructor
    ~MonteCarlo();

};


#endif
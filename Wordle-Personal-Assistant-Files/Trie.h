#ifndef WORDLE_SOLVER_TRIE_H
#define WORDLE_SOLVER_TRIE_H

#include <vector>
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Trie {
private:
    Node *rootNode;
    double trieSize = 0;
    double originalSize;
    double prevSize;
    std::vector<char> greenGreyChars;
    void readFile(std::string fileName);
    void removeGrey(int numGrey);
    void removeGreen(int numGreen);
    void removeYellow(int numYellow);
    void removeGreyChars(Node *currNode, Node *parentNode, int currI, char currChar, char greyChar);
    void removeNonGreenChar(Node *currNode, Node *parentNode, int currI, int branch, int greenIdx, char greenChar);
    void insert(std::string currWord);
    bool checkIfNoChildren(Node *currNode);
    bool removeNonYellowWord(Node *currNode, Node *parentNode,int currI, char currChar, char yellowChar);
    void removeWordsAtYellowIdx(Node *currNode, Node *parentNode, int currI, int branch, int yellowIdx, char yellowChar);
    bool checkIfGuessed(char currChar);

public:
    Trie(std::string fileName);
    void printWords(Node *currNode, std::string currString);
    void playWordle();
    bool search(Node *currNode, std::string desiredString, std::string currString);
    int getTrieSize();
    int getOriginalSize();
};


#endif //WORDLE_SOLVER_TRIE_H

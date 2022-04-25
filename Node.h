#ifndef WORDLE_SOLVER_NODE_H
#define WORDLE_SOLVER_NODE_H


class Node {
private:
    Node *children[26];  // Can declare children as size 26 because of alphabet size and no special chars
    bool leafNode;

public:
    Node();
    ~Node();
    friend class Trie;

};


#endif //WORDLE_SOLVER_NODE_H

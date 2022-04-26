#include "Node.h"

Node::Node() {
    this->leafNode = false;

    for (int i = 0; i < 26 ; ++i) {
        this->children[i] = nullptr;
    }

}

Node::~Node() {
    for (int i = 0; i < 26 ; ++i) {
        if (children[i]){
            delete children[i];
        }
        children[i] = nullptr;
    }
}
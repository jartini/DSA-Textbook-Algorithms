#include <iostream>


struct Node {
    Node* lPtr = nullptr;
    Node* rPtr = nullptr;
    int key = NULL;
};

//not implementing insert(value) -> it is redundant
//also I would rather pass a root node first. easier to program and test
//void insert(int value){}

void insertNode(Node* root, int data){
    //recursive
    Node* ptr = root;
    if(data < ptr->key){ //left
        if(ptr->lPtr == nullptr){
            Node* nextLeftNode = new Node;
            nextLeftNode->key = data;
            ptr->lPtr = nextLeftNode;
        }else{
            ptr = ptr->lPtr;
            insertNode(ptr, data);
        }
    }else if (data > ptr->key){ //right
        if(ptr->rPtr == nullptr){
            Node* nextRightNode = new Node;
            nextRightNode->key = data;
            ptr->rPtr = nextRightNode;
        }else{
            ptr = ptr->rPtr;
            insertNode(ptr, data);
        }
    }
}









int main(){return 0;}
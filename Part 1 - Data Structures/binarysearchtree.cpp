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

bool contain(Node* root, int query){
    Node* ptr = root;
    if(ptr->key == query){
        return true;
    }
    if(ptr->key < query){ //left
        if(ptr->lPtr == nullptr){
            return false;
        }else{
            ptr = ptr->lPtr;
            return contain(ptr, query);
        }
    }else if(ptr->key > query){ //right
        if(ptr->rPtr == nullptr){
            return false;
        }else{
            ptr = ptr->rPtr;
            return contain(ptr, query);
        }
    }
}

bool remove(Node* root, int value){
    if (!contain(root, value)){
        return false;
    }else{
        
    }
}

Node* findParentNode(Node* root, int value){

}

Node* findNode(Node* root, int value){

}

int findMin(Node* root){

}

int findMax(Node* root){
    
}







int main(){return 0;}
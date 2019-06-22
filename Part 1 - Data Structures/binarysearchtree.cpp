#include <iostream>



struct Node {
    Node* lPtr = nullptr;
    Node* rPtr = nullptr;
    int key;
};

//not implementing insert(value) -> it is redundant
//also I would rather pass a root node first. easier to program and test
//void insert(int value){}

bool contain(Node* root, int query){
    //searches the tree for an existing node with the corresponding key
    Node* ptr = root;
    if (!ptr){
        return false;
    }
    if(ptr->key == query){
        return true;
    }else{
        if(ptr->key < query){ //left
            ptr = ptr->lPtr;
            return contain(ptr, query); 
        }else if(ptr->key > query){ //right
            return contain(ptr, query);
        }
    }
    
}

bool insertNode(Node* root, int data){
    //inserts a node
    //recursive
    if(contain(root, data)){
        return false;
    }else{
        Node* ptr = root;
        Node* temp = new Node;
        temp->key = data;
        if(data < ptr->key){
            if(!ptr->lPtr){
                ptr->lPtr = temp;
                return true;
            }else{
                ptr = ptr->lPtr;
                insertNode(ptr, data);
            }
        }
        if(data > ptr->key){
            if(!ptr->rPtr){
                ptr->rPtr = temp;
                return true;
            }else{
                ptr = ptr->rPtr;
                insertNode(ptr, data);
            }
        }
    }
    return false;
}

Node* findParentNode(Node* root, int value, Node* parent = nullptr){
    //returns the parent pointer of the node that contains the value
    Node* ptr = root;
    if(!contain(root, value)){ //contains?
        return nullptr;
    }
    if(ptr->key < value){//left
        parent = ptr;
        ptr = ptr->lPtr;
        return findParentNode(ptr, value, parent);
    }else if(ptr->key > value){ //right
        parent = ptr;
        ptr = ptr->rPtr;
        return findParentNode(ptr, value, parent);
    }else if(ptr->key == value){ //found parent
        return parent;
    }
}

Node* findNode(Node* root, int value){
    //returns pointer to the node that contains the value
    Node* ptr = root;
    if(!contain(root, value)){ //contains?
        return nullptr;
    }
    if(ptr->key < value){ //left
        ptr = ptr->lPtr;
        return findNode(ptr, value);
    }else if(ptr->key > value){ //right
        ptr = ptr->rPtr;
        return findNode(ptr, value);
    }else if(ptr->key == value){ //found node
        return ptr;
    }
}

Node* findMinNode(Node* node){
    //returns pointer of min node
    Node* ptr = node;
    if(!ptr->lPtr){
        return ptr;
    }else{
        ptr = ptr->lPtr;
        return findMinNode(ptr);
    }
}

int findMin(Node* node){
    //returns smallest value
    return findMinNode(node)->key;
}


Node* findMaxNode(Node* node){
    //returns pointer of max node
    Node* ptr = node;
    if(!ptr->rPtr){
        return ptr;
    }else{
        ptr = ptr->rPtr;
        return findMaxNode(ptr);
    }
}

int findMax(Node* node){
    //returns biggest value
    return findMaxNode(node)->key;
}



bool remove(Node* root, int value){
    //absolute shit show
    //removes a node and restructures the tree
    if (!contain(root, value)){
        return false;
    }
    Node* parent = findParentNode(root, value);
    Node* node = findNode(root, value);
    Node* infTree = node->lPtr;
    Node* supTree = node->rPtr;
    Node* infParent = findMinNode(supTree);
    infParent->lPtr = infTree;
    if(parent->lPtr == node){
        parent->lPtr = supTree;
    }else if(parent->rPtr == node){
        parent->rPtr = supTree;
    }else if(root->key == value){
        root = supTree;
        return true;
    }else{
        return false;
    }
    delete node;
    return true;
}

//TRAVERSALS

void preorder(Node* root){

}

void postorder(Node* root){

}

void inorder(Node* root){

}

void breadthFirst(Node* root){
    
}

int main(){
    int i[] ={1,5,3,6,4,7};
    Node* root = new Node;
    root->key = 2;
    std::cout << insertNode(root, 3) << std::endl;
   // for(int x : i){
   //     insertNode(root, x);
   // }
   // std::cout << contain(root, 3) << std::endl;
    
    return 0;
}
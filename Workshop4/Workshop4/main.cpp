#include<iostream>

struct DListNode {
    int data;
    DListNode *next;
    DListNode *previous;
};

DListNode *insertAfter(int newData, DListNode *n) {
    DListNode *newNode = new DListNode;
    newNode->data = newData;
    if(n != nullptr) {
        newNode->previous = n;
        newNode->next = n->next;
        if(n->next != nullptr){
            n->next->previous = newNode;
        }
        n->next = newNode;
    }
    return newNode;
}

std::ostream &operator<<(std::ostream &s, DListNode *n) {
    while(n != nullptr) {
        s << n->data << " ";
        n=n->next;
    }
    return s;
}

bool isSorted(DListNode *n) {
    if(n != nullptr) {
        int max = n->data;
        n = n->next;
        while(n != nullptr) {
            if(n->data < max) {
                return false;
            }
            max = n->data;
            n = n->next;
        }
    }
    return true;
}

DListNode* initialise(unsigned int k) {
    DListNode *f = nullptr;
    DListNode *n = nullptr;
    for (unsigned int i = k-(k%2); i>0; i-=2) {
        n = insertAfter(i, n);
        if(f == nullptr) {
            f = n;
        }
    }
    for (unsigned int i = 1; i <= k; i += 2) {
        n = insertAfter(i, n);
    }
    return f;
}

DListNode* initialiseInOrder(unsigned int k) {
    DListNode *n = nullptr;
    for (unsigned int i = k; i>0; i--) {
        n = insertAfter(i, n);
    }
    
    return n;
}

DListNode* flip(unsigned int k, DListNode *n) {
    if(n == nullptr) {
        return n;
    }
    if(n->previous != nullptr) {
        std::cout << "Node is not the first in the list!" << std::endl;
        return n;
    }
    DListNode *last = n;
    for (int i = 1; (i<k) && (last->next != nullptr); i++) {
        last = last->next;
    }
    while(n != last) {
        insertAfter(n->data, last);
        n = n->next;
        delete n->previous;
        n->previous = nullptr;
    }
    return n;
}

int main() {
    std::cout << "WORKSHOP EXERCISES 4" << std::endl;
    unsigned int input;
    std::cout << "How many elements would you like?" << std::endl;
    std::cin >> input;
    DListNode *first = initialise(input);
    while(!isSorted(first)) {
        std::cout << "Current list: " << first << std::endl;
        std::cout << "Flip how many elements?" << std::endl;
        std::cin >> input;
        first = flip(input, first);
    }
    std::cout << "Done! Final list: " << first << std::endl;
}

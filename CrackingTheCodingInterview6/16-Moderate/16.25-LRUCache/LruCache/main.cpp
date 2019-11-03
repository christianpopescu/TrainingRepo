#include <iostream>
#include <bits/stdc++.h>

class LinkedNode {
public:
    int key;
    std::string value;
    LinkedNode* prev;
    LinkedNode* next;
};

class LruCache {
protected:
    int maxCash;
    std::unordered_map<int , LinkedNode* > mapCache;
    LinkedNode *head = nullptr;
    LinkedNode *tail = nullptr;

// RemoveNodeFromList
// ------------------
    void RemoveNodeFromList(LinkedNode* pNode) {
        if (pNode == nullptr) return;
        if (pNode == head) {
            if (pNode == tail) {
                // only one node in linked list
                head = tail = nullptr;
            }
            else {
                head = pNode->next;
            }
        }
        else if (pNode == tail) {
            tail = pNode->prev;
        } else {
            pNode->prev->next = pNode->next;
            pNode->next->prev = pNode->prev;
        }
    }
// AddNodeInFrontOfList
// --------------------
    void AddNodeInFrontOflist(LinkedNode* pNode) {
        if (head  == nullptr && tail == nullptr) {
            // empty list
            head = tail = pNode;
            tail->prev = nullptr;
            tail->next = nullptr;
        }
        else
        {
            pNode->prev = nullptr;
            pNode->next = head->next;
            head = pNode;
        }

    }

};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
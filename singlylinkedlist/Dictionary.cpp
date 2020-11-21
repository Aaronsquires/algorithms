// Dictionary.cpp
// Aaron Squires - N0748944
// Assignment 1 - Task 1

#include "Dictionary.h"
#include <iostream>

using namespace std;

namespace Containers
{

    // Node Class - Struct 
    struct Dictionary::Node
    {
        Key key;
        Item item;
        Node *next_node;
        Node(Key, Item);
    };

    Dictionary::Node::Node(Key k, Item i)
    {
        key = k;
        item = i;
        next_node = nullptr;        
    }

    // Lookup
    bool Dictionary::node_empty()
    {
        return head_Node == nullptr;
    }

    Dictionary::Item *Dictionary::lookup(Key sought_key)
    {
        Node *current_node = head_Node;
        while (current_node->next_node != nullptr){
            if (sought_key == current_node->key){
                return &current_node->item;
                } else {
                    current_node = current_node->next_node;
                }
        }
        // returns nullptr - if K is not present
        cout << "Test Lookup" << endl;
        return nullptr;
    }

    // Insert
    bool Dictionary::insert(Key k, Item i)
    {
        Node* node = new Node(k, i);
        if (head_Node == nullptr){
            head_Node = node;
            tail_Node = node;
        } else {
            Node *current_node = head_Node;
            while (current_node != nullptr) {
                if (current_node->key == k) {
                    delete node;
                    return false;
                }
                current_node = current_node->next_node;
            }

            tail_Node->next_node = node;
            tail_Node = node;
        }
        cout << "Test Insert" << endl;
        return true;
    }

    // Remove
    bool Dictionary::remove(Key k)
    {
        Node *current_node = head_Node;
        if (!this->node_empty()) {
            if (head_Node->key == k) {
                head_Node = head_Node->next_node;
                delete current_node;
                current_node = nullptr;
                return true;
            }
            else {
                while (current_node->next_node != nullptr) {
                    Node *previous = current_node;
                    current_node = current_node->next_node;
                    if (current_node->key == k){
                        if (current_node == tail_Node) {
                            tail_Node = previous;
                            previous->next_node = nullptr;
                            delete current_node;
                            current_node = nullptr;
                        } else {
                            previous->next_node = current_node->next_node;
                            delete current_node;
                            current_node = nullptr;
                        }
                        return true;
                    }
                }
            }
        }
        cout << "Test remove" << endl;
        return false;
    }

    // Display Nodes
    void Dictionary::display_nodes() {
        Node* current_node = head_Node;
        if (current_node == nullptr){
            cout << "No nodes to display" << endl;
        } else {
            while (current_node != nullptr) {
                cout << current_node->key << " " << current_node->item << endl;
                current_node = current_node->next_node;
            }
        }
    }


}
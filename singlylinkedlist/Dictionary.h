#ifndef Dictionary_H
#define Dictionary_H

#include <string>
using namespace std; 

namespace Containers {
    class Dictionary {

    public:
        Dictionary() = default;

        using Key = string;// ... must support at least std::string
        using Item = string;// ... must support at least std::string

        //default constructors - setup for deep_copy and deep_remove
        Dictionary(const Dictionary& original);
        Dictionary(Dictionary&& original);
        ~Dictionary();


        // Operators -
        Dictionary& operator=(const Dictionary& original);
        Dictionary& operator=(Dictionary&& original);

        // bool insert(Key, Item);
        // Insert item
        bool insert(Key key, Item item);
        // lookup item
        Item* lookup(Key sought_key);
        // Remove item
        bool remove(Key);

        // Traversal Functions
        void display_nodes();

        //
        bool node_empty();

    private:
        //Node creation
        struct Node;
        Node* head_Node = nullptr;
        Node* tail_Node = nullptr;

        //static privite functions
        static Node* deep_copy(Node* parent_node);
        static void deep_delete(Node* parent_node);

    };
}
#endif
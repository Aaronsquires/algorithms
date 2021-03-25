#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>
#include <string>
#include <cassert>

template <typename K, typename I>
class BST
{
	using Key = K;
	using Item = I;

private:
	struct Node;
	Node* root;

public:
	BST();
	BST(const BST& original);
	BST(BST&& original);
	~BST();

	BST& operator=(const BST& original);
	BST& operator=(BST&& original);

	Item* lookup(Key sought_key);
	void insert(Key key, Item item);
	void display_entries();
	void display_tree();
	void remove(Key key);

private:
	static bool is_leaf(Node*);
	static Item* lookup_rec(Key k, Node* starting_node);
	static void insert_rec(Key k, Item i, Node*& current_node);
	static void display_entries_rec(Node* starting_node);
	static void display_tree_rec(Node* starting_node, int level);
	static void remove_rec(Key k, Node*& current_node);
	static Node* detach_minimum_node(Node* starting_node);
	static void deep_delete(Node*& starting_node);
	static Node* deep_copy(Node* starting_node);

	/**
	* Pre-conditions:
	*   - local_root: must not be null
	*   - local_root->left_child must not be null
	**/
	static void rotate_right(Node*& local_root);

	/**
	* Pre-conditions:
	*   - local_root: must not be null
	*   - local_root->right_child must not be null
	**/
	static void rotate_left(Node*& local_root);
};

template <typename K, typename I>
struct BST<K, I>::Node
{
	Key key;
	Item item;

	Node* left_child;
	Node* right_child;

	Node(Key k, Item i)
	{
		key = k;
		item = i;
		left_child = nullptr;
		right_child = nullptr;
	}
};

template <typename K, typename I>
BST<K, I>::BST()
{
	root = nullptr;
}

template <typename K, typename I>
BST<K, I>::BST(const BST& original)
{
	root = deep_copy(original.root);
}

template <typename K, typename I>
BST<K, I>::BST(BST&& original)
{
	root = original.root;
	original.root = nullptr;
}

template <typename K, typename I>
BST<K, I>::~BST()
{
	deep_delete(root);
}

template <typename K, typename I>
BST<K, I>& BST<K, I>::operator=(const BST& original)
{
	if (this == &original)
		return *this;

	deep_delete(root);
	root = deep_copy(original.root);

	return *this;
}

template <typename K, typename I>
BST<K, I>& BST<K, I>::operator=(BST&& original)
{
	if (this == &original)
		return *this;

	deep_delete(root);
	root = original.root;
	original.root = nullptr;

	return *this;
}

template <typename K, typename I>
bool BST<K, I>::is_leaf(Node* n)
{
	return n == nullptr;
}

/*
BST::Item* BST::lookup(Key sought_key)
{
	Node* current = root;

	while (!is_leaf(current))
	{
		if (current->key == sought_key)
			return &current->item;

		if (sought_key < current->key)
			current = current->left_child;
		else
			current = current->right_child;
	}

	if (!is_leaf(current))
		return &current->item;

	return nullptr;
}
*/

template <typename K, typename I>
typename BST<K, I>::Item* BST<K, I>::lookup(Key sought_key)
{
	return lookup_rec(sought_key, root);
}

template <typename K, typename I>
typename BST<K, I>::Item* BST<K, I>::lookup_rec(Key sought_key, Node* current_node)
{
	if (is_leaf(current_node))
		return nullptr;

	if (sought_key == current_node->key)
		return &current_node->item;

	if (sought_key < current_node->key)
		return lookup_rec(sought_key, current_node->left_child);
	else
		return lookup_rec(sought_key, current_node->right_child);
}

/*
BST::Node* BST::insert(Key key, Item item)
{
	Node** current_node = &root;
	while (!is_leaf(*current_node))
	{
		if (key == (*current_node)->key) {
			(*current_node)->item = item;
			break;
		}

		else if (key < (*current_node)->key)
			current_node = &(*current_node)->left_child;
		else
			current_node = &(*current_node)->right_child;
	}

	if (is_leaf(*current_node)) {
		Node* new_node = new Node(key, item);
		*current_node = new_node;
	}

	return *current_node;
}
*/

template <typename K, typename I>
void BST<K, I>::insert(Key key, Item item)
{
	insert_rec(key, item, root);
}

template <typename K, typename I>
void BST<K, I>::insert_rec(Key key, Item item, Node*& current_node)
{
	if (is_leaf(current_node)) {
		Node* new_node = new Node(key, item);
		current_node = new_node;
	}
	else if (key == current_node->key) {
		current_node->item = item;
	}
	else if (key < current_node->key) {
		insert_rec(key, item, current_node->left_child);
	}
	else if (key > current_node->key) {
		insert_rec(key, item, current_node->right_child);
	}
}

template <typename K, typename I>
void BST<K, I>::display_entries()
{
	display_entries_rec(root);
}

template <typename K, typename I>
void BST<K, I>::display_entries_rec(Node* starting_node)
{
	if (is_leaf(starting_node))
		return;

	display_entries_rec(starting_node->left_child);

	std::cout << starting_node->key << " " << starting_node->item << std::endl;

	display_entries_rec(starting_node->right_child);
}

template <typename K, typename I>
void BST<K, I>::display_tree()
{
	display_tree_rec(root, 0);
}

template <typename K, typename I>
void BST<K, I>::display_tree_rec(Node* starting_node, int level)
{
	std::string tabs(level, '\t');

	if (is_leaf(starting_node)) {
		std::cout << tabs << "LEAF" << std::endl;
	}
	else {
		std::cout << tabs << starting_node->key << " " << starting_node->item << std::endl;

		display_tree_rec(starting_node->left_child, level + 1);
		display_tree_rec(starting_node->right_child, level + 1);
	}
}

template <typename K, typename I>
void BST<K, I>::remove(Key key)
{
	remove_rec(key, root);
}

template <typename K, typename I>
void BST<K, I>::remove_rec(Key key, Node*& current_node)
{
	if (key < current_node->key) {
		remove_rec(key, current_node->left_child);
	}
	else if (key > current_node->key) {
		remove_rec(key, current_node->right_child);
	}
	else {
		if (is_leaf(current_node->left_child) && is_leaf(current_node->right_child))
		{
			delete current_node;
			current_node = nullptr;
		}
		else if (is_leaf(current_node->left_child)) {
			Node* to_remove = current_node;
			current_node = current_node->right_child;
			delete to_remove;
		}
		else if (is_leaf(current_node->right_child))
		{
			Node* to_remove = current_node;
			current_node = current_node->left_child;
			delete to_remove;
		}
		else
		{
			Node* minimum_node = detach_minimum_node(current_node->right_child);
			minimum_node->right_child = current_node->right_child;
			minimum_node->left_child = current_node->left_child;
			Node* to_remove = current_node;
			current_node = minimum_node;
			delete to_remove;
		}
	}
}

template <typename K, typename I>
typename BST<K, I>::Node* BST<K, I>::detach_minimum_node(Node* starting_node)
{
	Node* root_node = starting_node;
	while (!is_leaf(starting_node->left_child))
	{
		root_node = starting_node;
		starting_node = starting_node->left_child;
	}

	root_node->left_child = starting_node->right_child;

	return starting_node;
}

template <typename K, typename I>
void BST<K, I>::deep_delete(Node*& starting_node)
{
	if (is_leaf(starting_node))
		return;

	deep_delete(starting_node->left_child);
	deep_delete(starting_node->right_child);

	delete starting_node;
	starting_node = nullptr;
}

template <typename K, typename I>
typename BST<K, I>::Node* BST<K, I>::deep_copy(Node* starting_node)
{
	if (is_leaf(starting_node))
		return nullptr;

	Node* new_node = new Node(starting_node->key, starting_node->item);
	new_node->left_child = deep_copy(starting_node->left_child);
	new_node->right_child = deep_copy(starting_node->right_child);

	return new_node;
}

template <typename K, typename I>
void BST<K, I>::rotate_right(Node*& local_root)
{
	assert(local_root);
	assert(local_root->left_child);

	Node* b = local_root;
	Node* a = b->left_child;
	Node* beta = a->right_child;

	local_root = a;
	a->right_child = b;
	b->left_child = beta;
}

template <typename K, typename I>
void BST<K, I>::rotate_left(Node*& local_root)
{
	assert(local_root);
	assert(local_root->right_child);

	Node* a = local_root;
	Node* b = a->right_child;
	Node* beta = b->left_child;

	local_root = b;
	b->left_child = a;
	a->right_child = beta;
}

#endif

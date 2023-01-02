#pragma once
#include <vector> // #include directive
#include <string>
#include "DLL.h"
class AVL {
private:
struct Tnode {
	int data;
	int height;    // height of tree
	Tnode* right;
	Tnode* left;
	Tnode* next;
	dnode* pointer;
	Tnode(int val, int h)
	{
		data = val;
		height = h;
		left = NULL;
		right = NULL;
		next = NULL;
	}
};
	Tnode* root;
	int n;        // size of tree

	int height(Tnode* ptr)      // funtion to get height
	{
		if (ptr == NULL)
			return -1;
		else
			return ptr->height;
	}

	int Balancefactor(Tnode* ptr)      // function to find balance factor
	{
		int bf;
		bf = height(ptr->right) - height(ptr->left);
		return bf;
	}

	bool isBalanced(Tnode* ptr)
	{
		int bf = 0;
		if (ptr != NULL)
		{
			isBalanced(ptr->left);    //post order traversal LRN
			isBalanced(ptr->right);
			bf = Balancefactor(ptr);
			if (bf != 0 && bf != 1 && bf != -1)
			{
				return false;
			}
		}
		return true;
	}

	int max(int a, int b)      // function to get maximum of two
	{
		if (a > b)
			return a;
		else
			return b;
	}

	bool Updateheight(Tnode* ptr)     // function to update height after insertion or deleletion
	{
		int oldheight, newheight;
		oldheight = ptr->height;
		newheight = max(height(ptr->left), height(ptr->right)) + 1;
		ptr->height = newheight;
		return (oldheight != newheight);
	}

	Tnode* RR(Tnode* ptr)   // rotate right
	{
		Tnode* cptr = ptr->left;
		Tnode* pptr = cptr->right;
		if (cptr == NULL)
			return cptr;

		else
		{
			if (pptr == NULL)
			{
				root = cptr;
			}
			else
			{
				if (ptr == pptr->left)
				{
					pptr->left = cptr;
				}
				else
					pptr->right = cptr;
			}
		}
		Tnode* temp = cptr->right;
		cptr->right = ptr;
		ptr->left = temp;
		return cptr;
	}

	Tnode* RL(Tnode* ptr)     // Rotate left
	{
		Tnode* cptr = ptr->right;
		Tnode* pptr = cptr->left;
		if (cptr == NULL)
			return cptr;

		else
		{
			if (pptr == NULL)
			{
				root = cptr;
			}
			else
			{
				if (ptr == pptr->left)
				{
					pptr->left = cptr;
				}
				else
					pptr->right = cptr;
			}
		}
		Tnode* temp = cptr->left;
		cptr->left = ptr;
		ptr->right = temp;
		return cptr;
	}

	bool getaccess(int val, Tnode* ptr)   // check value exist or not
	{
		ptr = NULL;
		Tnode* curr = root;
		while (curr != NULL)
		{

			if (val == curr->data)
				return true;
			else
			{
				ptr = curr;
			}
			if (val < curr->data)
			{
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
		}
		return false;
	}


public:
	AVL()
	{
		root = NULL;
	}

	// Insert a node
	Tnode* insertNode(Tnode* node, int data, dnode*& t) {
		// Find the correct postion and insert the node
		if (node == NULL)
		{
			node = new Tnode(data, height(node));
			node->pointer = t;
			return node;
		}
		if (data < node->data)
			node->left = insertNode(node->left, data, t);
		else if (data > node->data)
			node->right = insertNode(node->right, data, t);
		else
			node->pointer = t;
		return node;

		// Update the balance factor of each node and
		// balance the tree
		node->height = 1 + max(height(node->left),
			height(node->right));
		int balanceFactor = Balancefactor(node);
		if (balanceFactor > 1) {
			if (data < node->left->data) {
				return RR(node);
			}
			else if (data > node->left->data) {
				node->left = RL(node->left);
				return RR(node);
			}
		}
		if (balanceFactor < -1) {
			if (data > node->right->data) {
				return RL(node);
			}
			else if (data < node->right->data) {
				node->right = RR(node->right);
				return RL(node);
			}
		}
		return node;
	}

	void insertNode(dnode* t, int key)
	{
		root = insertNode(root, key, t);
	}

	Tnode* minValueNode(Tnode* node)
	{
		Tnode* current = node;

		/* loop down to find the leftmost leaf */
		while (current->left != NULL)
			current = current->left;

		return current;
	}
	void deleteNode(dnode* t, int key)
	{
		root = deleteNode(root, key, t);
	}

	// Delete a node
	Tnode* deleteNode(Tnode* root, int data, dnode*& t) {
		// Find the node and delete it
		if (root == NULL)
			return root;
		if (data < root->data)
			root->left = deleteNode(root->left, data, t);
		else if (data > root->data)
			root->right = deleteNode(root->right, data, t);
		else {
			if ((root->left == NULL) ||
				(root->right == NULL)) {
				Tnode* temp = root->left ? root->left : root->right;
				if (temp == NULL) {
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
				free(temp);
			}
			else {
				Tnode* temp = minValueNode(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data, t);
			}
		}

		if (root == NULL)
			return root;

		// Update the balance factor of each node and
		// balance the tree
		root->height = 1 + max(height(root->left),
			height(root->right));
		int balanceFactor = Balancefactor(root);
		if (balanceFactor > 1) {
			if (Balancefactor(root->left) >= 0) {
				return RR(root);
			}
			else {
				root->left = RL(root->left);
				return RR(root);
			}
		}
		if (balanceFactor < -1) {
			if (Balancefactor(root->right) <= 0) {
				return RL(root);
			}
			else {
				root->right = RR(root->right);
				return RL(root);
			}
		}
		return root;
	}

	bool searchAvl(dnode* t, int val)
	{
		bool y = searchAvl(root, val, t);
		if (y == true)
		{
			cout << "Issn Found !!!\n";
			return true;
		}
		else
		{
			cout << "Issn not found !!!\n";
			return false;
		}
	}

	bool searchAvl(Tnode* root, int val, dnode* t)
	{
		if (root == NULL)
			return false;
		else if (root->data == val)
			return true;

		else if (root->data > val)
		{
			bool x = searchAvl(root->left, val, t);
			return x;
		}
		else
		{
			bool x = searchAvl(root->right, val, t);
			return x;
		}
	}

	void preOrder(Tnode* root)
	{
		preOrder();
	}
	void preOrder()
	{
		if (root != NULL)
		{
			cout << root->data << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void inorder(dnode* t)
	{
		inorder(root, t);
	}

	void inorder(Tnode* root, dnode* t)
	{
		if (root != NULL)
		{
			cout << "Issn : " << root->data;
			cout << endl;
			inorder(root->left, t);
			root->pointer->pr();
			inorder(root->right, t);
			cout << endl;
		}

	}

	~AVL()
	{

	}
};
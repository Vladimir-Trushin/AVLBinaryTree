#pragma once

//=========================================================================================
// The current code of the AVL-tree was copied from the site "habr.com"
// &: https://habr.com/ru/post/150732/
//
// The current code of the print function was copied from the site "www.geeksforgeeks.org" 
// &: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
//
// EXCEPTION:
// Tree()     ---> NO
// ~Tree()    ---> NO
//
// insert()   ---> Throwing an exception if the tree already have the node of the current key
// remove()   ---> Throwing an exception if the node of the current key is not exist
// size()     ---> NO
// contains() ---> NO
// root()     ---> Throwing an exception if the tree empty
// parent()   ---> Throwing an exception if the current node not exist
// left()     ---> Throwing an exception if the current node not exist
// right()    ---> Throwing an exception if the current node not exist
// print()    ---> NO
//
//
////////



#include <iostream>

#define LEN 3 // Number space for function print2DUtil(), initializing the variable _len


namespace ariel
{
	class Tree
	{
	private:
		////--------------------------------------------------------------------
		// Standard binary node (declaration)
		struct node
		{
			int _key;
			unsigned char _height;
			node* _left;
			node* _right;
			node(int k);
		};

		//--------------------------------
		node* _root; // Root of the tree
		int _size; // The number of nodes in the tree
		int _len; // The number of spaces for the print function


		////--------------------------------------------------------------------
		// Is a wrapper for the height field, it can work with null pointer
		unsigned char height(node* p);

		////--------------------------------------------------------------------
		// Calculates the balance factor of the specified node,
		// it can't work with a null pointer
		int bfactor(node* p);

		////--------------------------------------------------------------------
		// The function restores the correct value of the height field
		// of the specified node. Provided that the values of this field
		// in the right and left node are correct
		void fixheight(node* p);

		////--------------------------------------------------------------------
		// The function provides the right turn
		node* rotateright(node* p);

		////--------------------------------------------------------------------
		// The function provides the left turn
		node* rotateleft(node* q);

		////--------------------------------------------------------------------
		// The function balancing
		node* balance(node* p);

		//@//--------------------------------------------------------------------
		// The function insert. The function is throwing an exception
		// if the tree already have the node of the current key
		node* insert(node* root, int k);

		//@//--------------------------------------------------------------------
		// The function which finding a minimum node
		node* findmin(node* p);


		//@//--------------------------------------------------------------------
		// The function which removing a minimum node
		node* removemin(node* p);

		//@//--------------------------------------------------------------------
		// The function which removing the node of the current key.
		// The function is throwing an exception
		// if the node of the current key is not exist
		node* remove(node* root, int k);

		//@//--------------------------------------------------------------------
		// The find function
		const node* find(const node* root, int key) const;

		//@//--------------------------------------------------------------------
		// Function to print binary tree in 2D  
		// It does reverse inorder traversal  
		void print2DUtil(node* root, int space) const;

		//@//--------------------------------------------------------------------
		// The function is deleting the tree
		void deleteTree(node* root);



	//----------------------INTERFACE--------------------------



	public:
		////--------------------------------------------------------------------
		// Constructor
		Tree();

		////--------------------------------------------------------------------
		// Distractor
		~Tree();

		////--------------------------------------------------------------------
		// The insert function.
		// The function is throwing an exception
		// if the tree already have the node of the current key
		void insert(int key);

		////--------------------------------------------------------------------
		// The remove function.
		// The function is throwing an exception
		// if the node of the current key is not exist
		void remove(int key);

		////--------------------------------------------------------------------
		// The size function
		int size() const;

		////--------------------------------------------------------------------
		// The contains function
		bool contains(int key) const;

		////--------------------------------------------------------------------
		// The contains function.
		// The function is throwing an exception
		// if the tree empty
		int root() const;

		////--------------------------------------------------------------------
		// The parent function.
		// The function is throwing an exception
		// if the current node not exist
		int parent(int key) const;

		////--------------------------------------------------------------------
		// The left function
		// The function is throwing an exception
		// if the current node not exist
		int left(int key) const;

		////--------------------------------------------------------------------
		// The right function
		// The function is throwing an exception
		// if the current node not exist
		int right(int key) const;

		////--------------------------------------------------------------------
		// Wrapper over print2DUtil()  
		void print() const;



	}; // End of class Tree

} // End of spacename ariel
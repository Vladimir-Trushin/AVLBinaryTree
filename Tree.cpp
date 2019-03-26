#include "Tree.hpp"
//#include "str_exception.hpp"




namespace ariel
{
	// AVL Tree
        Tree::node::node(int k) : _key(k), _left(nullptr), _right(nullptr), _height(1)
        {
        }



		////--------------------------------------------------------------------
		// Is a wrapper for the height field, it can work with null pointer
		unsigned char Tree::height(node* p)
		{
			return p ? p->_height : (unsigned char)0;
		}

		////--------------------------------------------------------------------
		// Calculates the balance factor of the specified node,
		// it can't work with a null pointer
		int Tree::bfactor(node* p)
		{
			return height(p->_right) - height(p->_left);
		}

		////--------------------------------------------------------------------
		// The function restores the correct value of the height field
		// of the specified node. Provided that the values of this field
		// in the right and left node are correct
		void Tree::fixheight(node* p)
		{
			unsigned char hl = height(p->_left);
			unsigned char hr = height(p->_right);
			p->_height = (hl > hr ? hl : hr) + 1;
		}

		////--------------------------------------------------------------------
		// The function provides the right turn
		Tree::node* Tree::rotateright(node* p)
		{
			node* q = p->_left;
			p->_left = q->_right;
			q->_right = p;
			fixheight(p);
			fixheight(q);

			return q;
		}

		////--------------------------------------------------------------------
		// The function provides the left turn
		Tree::node* Tree::rotateleft(node* q)
		{
			node* p = q->_right;
			q->_right = p->_left;
			p->_left = q;
			fixheight(q);
			fixheight(p);

			return p;
		}

		////--------------------------------------------------------------------
		// The function balancing
		Tree::node* Tree::balance(node* p)
		{
			fixheight(p); // Fixing height current node

			if (bfactor(p) == 2) // If the right child of the node imbalanced, do balance
			{
				if (bfactor(p->_right) < 0) // Double rotation run (talking about children of (p->_right) )
					p->_right = rotateright(p->_right); // when the height of the left child is bigger than the right child

				return rotateleft(p);
			}

			if (bfactor(p) == -2) // If the left child of the node imbalanced, do balance
			{
				if (bfactor(p->_left) > 0) // Double rotation run (talking about children of (p->_left) )
					p->_left = rotateleft(p->_left); // when the height of the right child is bigger than the left child

				return rotateright(p);
			}

			return p; // No need for balancing
		}

		//@//--------------------------------------------------------------------
		// The function insert. The function is throwing an exception
		// if the tree already have the node of the current key
		Tree::node* Tree::insert(node* root, int k)
		{
			if (!root)
			{
				node* p = new (std::nothrow) node(k); // Don't throw the exception "bad_alloc"
				if (!p) // Immediately exiting from the application
				{
					std::cerr << "Bad allocation memory";
					exit(1);
				}

				return p;
			}

			if (k == root->_key) // Throw an exception if the current key is exist
				throw "The tree already have the current key";

			if (k < root->_key)
				root->_left = insert(root->_left, k);
			else
				root->_right = insert(root->_right, k);

			return balance(root); // Balancing after each iteration
		}


		//@//--------------------------------------------------------------------
		// The function which finding a minimum node
		Tree::node* Tree::findmin(node* p)
		{
			return p->_left ? findmin(p->_left) : p;
		}


		//@//--------------------------------------------------------------------
		// The function which removing a minimum node
		Tree::node* Tree::removemin(node* p)
		{
			if (p->_left == nullptr)
				return p->_right;
			p->_left = removemin(p->_left);

			return balance(p); // Balancing after each iteration
		}


		//@//--------------------------------------------------------------------
		// The function which removing the node of the current key.
		// The function is throwing an exception
		// if the node of the current key is not exist
		Tree::node* Tree::remove(node* root, int k)
		{
			if (!root) // Throw an exception if the current node is not exist
				throw "The tree doesn't have the current key";

			if (k < root->_key)
				root->_left = remove(root->_left, k);
			else if (k > root->_key)
				root->_right = remove(root->_right, k);
			else // The key is exist. Removing the node of the current key
			{
				node* q = root->_left;
				node* r = root->_right;
				delete root;
				if (!r) return q;
				node* min = findmin(r);
				min->_right = removemin(r);
				min->_left = q;

				return balance(min); // Balancing after removing
			}

			return balance(root); // Balancing after each iteration
		}


		//@//--------------------------------------------------------------------
		// The find function
		const Tree::node* Tree::find(const node* root, int key) const
		{
			if (root == nullptr)
				return nullptr;

			if (key == root->_key)
				return root;
			else if (key < root->_key)
				find(root->_left, key);
			else
				find(root->_right, key);
		}


		//@//--------------------------------------------------------------------
		// Function to print binary tree in 2D  
		// It does reverse inorder traversal  
		void Tree::print2DUtil(node* root, int space) const
		{
			// Base case  
			if (root == nullptr)
				return;

			// Increase distance between levels  
			space += _len;

			// Process right child first  
			print2DUtil(root->_right, space);

			// Print current node after space  
			// count  
			std::cout << std::endl;
			for (int i = _len; i < space; i++)
				std::cout << " ";
			std::cout << root->_key << "\n";

			// Process left child  
			print2DUtil(root->_left, space);
		}


		//@//--------------------------------------------------------------------
		// The function is deleting the tree
		void Tree::deleteTree(node* root)
		{
			if (!root)
				return;

			deleteTree(root->_left);
			deleteTree(root->_right);

			delete root;
		}



	//----------------------INTERFACE--------------------------



	
		////--------------------------------------------------------------------
		// Constructor
		Tree::Tree() : _root(nullptr), _size(0), _len(LEN)
		{
		}


		////--------------------------------------------------------------------
		// Distractor
		Tree::~Tree()
		{
			deleteTree(_root);
		}


		////--------------------------------------------------------------------
		// The insert function.
		// The function is throwing an exception
		// if the tree already have the node of the current key
		void Tree::insert(int key)
		{
			_root = insert(_root, key);
			_size++;
		}


		////--------------------------------------------------------------------
		// The remove function.
		// The function is throwing an exception
		// if the node of the current key is not exist
		void Tree::remove(int key)
		{
			_root = remove(_root, key);
			_size--;
		}


		////--------------------------------------------------------------------
		// The size function
		int Tree::size() const
		{
			return _size;
		}


		////--------------------------------------------------------------------
		// The contains function
		bool Tree::contains(int key) const
		{
			if (find(_root, key) == nullptr)
				return false;
			else
				return true;
		}


		////--------------------------------------------------------------------
		// The contains function.
		// The function is throwing an exception
		// if the tree empty
		int Tree::root() const
		{
			if (_root == nullptr)
				throw "Error: null pointer reference";

			return _root->_key;
		}


		////--------------------------------------------------------------------
		// The parent function.
		// The function is throwing an exception
		// if the current node not exist
		int Tree::parent(int key) const
		{
			const node* temp = _root;
			const node* ret = nullptr;
			
			if (!contains(key))
				throw "Error: current node not exist";

			if (key == _root->_key)
				throw "Error: current node not exist";

			while (key != temp->_key)
			{
				ret = temp;

				if (key < temp->_key)
					temp = temp->_left;
				else
					temp = temp->_right;
			}

			return ret->_key;
		}


		////--------------------------------------------------------------------
		// The left function
		// The function is throwing an exception
		// if the current node not exist
		int Tree::left(int key) const
		{
			const node* temp = find(_root, key);

			if (!temp)
				throw "Error: current node not exist";
			else if (!temp->_left)
				throw "Error: current node not exist";
			else
				return temp->_left->_key;
		}


		////--------------------------------------------------------------------
		// The right function
		// The function is throwing an exception
		// if the current node not exist
		int Tree::right(int key) const
		{
			const node* temp = find(_root, key);

			if (!temp)
				throw "Error: current node not exist";
			else if (!temp->_right)
				throw "Error: current node not exist";
			else
				return temp->_right->_key;
		}


		////--------------------------------------------------------------------
		// Wrapper over print2DUtil()  
		void Tree::print() const
		{
			// Pass initial space count as 0  
			print2DUtil(_root, 0);
		}


} // End of spacename ariel
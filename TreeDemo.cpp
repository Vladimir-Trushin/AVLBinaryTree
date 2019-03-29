/**
 * Demo program for the exercise on binary trees
 *
 * @author Erel Segal-Halevi
 * 
 * @since 2019-02
 */

#include <iostream>
#include "Tree.hpp"
using std::cout, std::endl;


int main()
{
  try
  {
    // constructs an empty tree:
    ariel::Tree emptytree;
    cout << "Empty tree: size=" << emptytree.size() << endl; // should print 0
    
    // constructs an ordered binary tree:
    ariel::Tree tree;

    // insert check
    tree.insert(5);
    tree.insert(7);
    tree.insert(3);
    tree.insert(4);
    tree.insert(10);
    tree.insert(9);
    tree.insert(1);
    tree.insert(15);
    tree.insert(2);

    cout << "Tree: size=" << tree.size() << " root=" << tree.root() << endl << "   ";  // size=9, root=5.
    tree.print();
    cout << endl;
      
    cout << tree.size() << " ";      // should print 9
    cout << tree.parent(3) << " ";   // should print 5
    cout << tree.parent(7) << " ";   // should print 9
    cout << tree.left(5) << " ";     // should print 3
    cout << tree.right(5) << " ";    // should print 9
    cout << endl;
    cout << endl;

    //----------------------------------------------------

    // remove check
    tree.remove(15);
    tree.remove(5);
    tree.remove(1);
    tree.remove(9);

    cout << "Tree: size=" << tree.size() << " root=" << tree.root() << endl << "   ";  // size=5, root=7.
    tree.print();
    cout << endl;

    cout << tree.size() << " ";      // should print 5
    cout << tree.parent(3) << " ";   // should print 7
    cout << tree.parent(4) << " ";   // should print 3
    cout << tree.left(7) << " ";     // should print 3
    cout << tree.right(7) << " ";    // should print 10
    cout << endl;
    tree.remove(5);    // should throw an exception, since 5 not exists.
  }
  catch (const char* ex)
  {
    cout << "Caught exception: " << ex << endl;
  }
  catch (...)
  {
    cout << "Unknown exception!!!" << endl;
  }
}

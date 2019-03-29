/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  // My tree chech
  ariel::Tree mytree;
  ariel::Tree myemptytree;
  //////  

  cout << "----------standard test----------";
  cout << endl;

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print());



  cout << endl;
  cout << "-------------my test-------------";
  cout << endl;

  // My tree chech
  tc
  .CHECK_EQUAL (mytree.size(), 0)
  .CHECK_OK    (mytree.insert(10))
  .CHECK_OK    (mytree.insert(5))
  .CHECK_OK    (mytree.insert(2))
  .CHECK_OK    (mytree.insert(9))
  .CHECK_OK    (mytree.insert(15))
  .CHECK_OK    (mytree.insert(23))
  .CHECK_OK    (mytree.insert(13))
  .CHECK_OK    (mytree.insert(7))
  .CHECK_OK    (mytree.insert(19))

  .CHECK_OK    (mytree.print())

  // Empty tree
  .CHECK_EQUAL (myemptytree.size(), 0)     // ok - size = 0
  .CHECK_THROWS(myemptytree.root())        // ok - root not exist
  .CHECK_OK    (myemptytree.print())       // ok - not throwing exception

  // My tree
  .CHECK_EQUAL (mytree.root(), 10)         // ok - root is 10
  .CHECK_EQUAL (mytree.size(), 9)          // ok - size = 9
  .CHECK_EQUAL (mytree.contains(19), true) // ok - 19 exist
  .CHECK_EQUAL (mytree.contains(3), false) // ok - 3 not exist
  .CHECK_EQUAL (mytree.parent(5), 10)      // ok - parent is 10
  .CHECK_THROWS(mytree.parent(10))         // ok - parent not exist
  .CHECK_THROWS(mytree.parent(3))          // ok - node 3 not exist
  .CHECK_EQUAL (mytree.left(5), 2)         // ok - left is 2
  .CHECK_THROWS(mytree.left(7))            // ok - left not exist
  .CHECK_THROWS(mytree.left(50))           // ok - node 50 not exist
  .CHECK_EQUAL (mytree.right(15), 23)      // ok - right is 23
  .CHECK_THROWS(mytree.right(23))          // ok - right not exist
  .CHECK_THROWS(mytree.right(8))           // ok - node 8 not exist

  .CHECK_OK    (mytree.remove(10))
  .CHECK_OK    (mytree.remove(23))
  .CHECK_OK    (mytree.remove(15))
  .CHECK_OK    (mytree.remove(7))
  .CHECK_OK    (mytree.remove(19))
  .CHECK_OK    (mytree.remove(13));

  cout << endl;
  cout << "---------------------------------";
  cout << endl;

tc
  .CHECK_OK    (mytree.print())

  .CHECK_EQUAL (mytree.root(), 5)           // ok - root is 5
  .CHECK_EQUAL (mytree.size(), 3)           // ok - size = 3
  .CHECK_EQUAL (mytree.contains(9), true)   // ok - 9 exist
  .CHECK_EQUAL (mytree.contains(3), false)  // ok - 3 not exist
  .CHECK_EQUAL (mytree.parent(2), 5)        // ok - parent is 5
  .CHECK_THROWS(mytree.parent(5))           // ok - parent not exist
  .CHECK_THROWS(mytree.parent(23))          // ok - node 23 not exist
  .CHECK_EQUAL (mytree.left(5), 2)          // ok - left is 2
  .CHECK_THROWS(mytree.left(9))             // ok - left not exist
  .CHECK_THROWS(mytree.left(10))            // ok - node 10 not exist
  .CHECK_EQUAL (mytree.right(5), 9)         // ok - right is 9
  .CHECK_THROWS(mytree.right(9))            // ok - right not exist
  .CHECK_THROWS(mytree.right(7))            // ok - node 8 not exist
  //////


  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}

#!make

demo: TreeDemo.o Tree.o
	clang++-5.0 -v -std=c++17 $^ -o demo

test: TreeTest.o Tree.o
	clang++-5.0 -std=c++17 $^ -o test

%.o: %.cpp
	clang++-5.0 -std=c++17 --compile $< -o $@

clean:
	rm -f *.o demo test

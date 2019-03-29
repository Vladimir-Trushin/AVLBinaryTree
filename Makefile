#!make -f

demo: TreeDemo.o Tree.o
	clang++-5.0 -g -std=c++17 $^ -o demo

test: TreeTest.o Tree.o
	clang++-5.0 -g -std=c++17 $^ -o test

%.o: %.cpp
	clang++-5.0 -g -std=c++17 --compile $< -o $@

clean:
	rm -f *.o demo test

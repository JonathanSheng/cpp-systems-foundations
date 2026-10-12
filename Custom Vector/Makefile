CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -g
BREW_PREFIX := $(shell brew --prefix)

.PHONY: all test clean

all: main

main: main.cpp vector.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

test_vector: test_vector.cpp vector.hpp
	$(CXX) $(CXXFLAGS) test_vector.cpp \
		-I$(BREW_PREFIX)/include -L$(BREW_PREFIX)/lib \
		-lgtest -lgtest_main -pthread -o test_vector

test: test_vector
	./test_vector

clean:
	rm -f main test_vector
	rm -rf main.dSYM test_vector.dSYM

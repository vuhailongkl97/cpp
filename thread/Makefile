.PHONY: all test barrier
all: clean test lock barrier

test:
	g++ test.cpp -o test
lock:
	g++ locking.cpp -lpthread -o lock  
barrier:
	g++ barrier.cpp -lpthread -std=c++20 -o barrier

clean:
	rm -rf lock test 

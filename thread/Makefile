.PHONY: all test barrier threadpool
all: clean test lock barrier threadpool

test:
	g++ test.cpp -o test
lock:
	g++ locking.cpp -lpthread -o lock  
barrier:
	g++ barrier.cpp -lpthread -std=c++20 -o barrier
threadpool:
	g++ threadpool.cpp -lpthread -std=c++20 -o threadpool -g

clean:
	rm -rf lock test 

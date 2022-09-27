.PHONY: all test
all: clean test lock

test:
	g++ test.cpp -o test

lock:
	g++ locking.cpp -lpthread -o lock  

clean:
	rm -rf lock test 

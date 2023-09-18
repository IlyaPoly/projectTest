all: Test

Test: connect.o test_generated.o main.o
	g++ connect.o  main.o  -o consolechatClient
main.o: main.cpp
	g++ -g -c main.cpp
test_generated.o: test_generated.h
	g++ -g -c test_generated.h
connect.o: connect.cpp
	g++ -g -c connect.cpp
clean:
	rm -rf *.o
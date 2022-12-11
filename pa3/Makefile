CC=g++
CFLAGS=-std=c++11
SRC=main.cpp

cb: $(SRC)
	$(CC) $(CFLAGS) -o $@ $< -g

test: cb
	./cb public_case_1.in
clean: cb
	rm -rf cb *.o
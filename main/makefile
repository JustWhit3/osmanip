CC=g++
CFLAGS=-I.
DEPS = ../osmanip/include/osmanip.h
OBJ = main.o ../osmanip/src/osmanip.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean
clean:
	rm -f main.o main ../osmanip/src/osmanip.o ../osmanip/src/osmanip.cpp.save

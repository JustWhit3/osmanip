CC=g++
CFLAGS=-I.
DEPS = ../OstreamManipulator/include/OstreamManipulator.h
OBJ = Main.o ../OstreamManipulator/src/OstreamManipulator.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean
clean:
	rm -f Main.o Main ../OstreamManipulator/src/OstreamManipulator.o ../OstreamManipulator/src/OstreamManipulator.cpp.save

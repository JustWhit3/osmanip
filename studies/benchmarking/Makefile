#====================================================
#     Variables
#====================================================
ifeq ($(OS),Windows_NT)
	EXEC := manipulators.exe
else
	EXEC := manipulators
endif

#====================================================
#     FLAGS
#====================================================
WARNINGS := -Wall -Wextra -Wno-unused-but-set-variable
EXTRAFLAGS := -std=c++17 -g -O3 -O1 -falign-functions=32 
LDFLAGS := -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -L../../lib -losmanip -o $(EXEC)

#====================================================
#     Compilation
#====================================================
bin/$(EXEC): manipulators.o
	g++ manipulators.o -o $(EXEC) $(LDFLAGS)
	@ mkdir -p obj bin
	@ mv *.o obj
	@ mv manipulators bin

manipulators.o: src/manipulators.cpp
	g++ -c src/manipulators.cpp $(EXTRAFLAGS) $(WARNINGS) 

clean:
	rm -rf obj bin
#====================================================
#     OS detection
#====================================================
ifeq ($(OS),Windows_NT)
	O_SYSTEM = Windows
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		O_SYSTEM = Linux
	else ifeq ($(UNAME_S),Darwin)
		O_SYSTEM = MacOS
	endif
endif

#====================================================
#     Variables
#====================================================
ifeq ($(O_SYSTEM),$(filter $(O_SYSTEM),MacOS Linux))
	EX_MANIP_EXEC := manipulators
	EX_PB_EXEC := progressbar
	EX_GRAPH_EXEC := graphics
	EX_REDIR_EXEC := redirection
	TEST_EXEC := tests
else
	EX_MANIP_EXEC := manipulators.exe
	EX_PB_EXEC := progressbar.exe
	EX_GRAPH_EXEC := graphics.exe
	EX_REDIR_EXEC := redirection.exe
	TEST_EXEC := tests.exe
endif
LIB := libosmanip.a
CXX := g++

#====================================================
#     Directories
#====================================================

# Binary directories
BUILD_DIR := bin
OBJ_DIR := obj
LIB_DIR := lib

# Source directories
SRC_DIR := src
EX_DIR := examples
TEST_DIR := test/unit_tests

#====================================================
#     Source files
#====================================================
ifeq ($(O_SYSTEM),$(filter $(O_SYSTEM),MacOS Linux))
	SRC_MANIP := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'manipulators.cpp')
	SRC_PB := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'progressbar.cpp')
	SRC_GRAPH := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'graphics.cpp')
	SRC_REDIR := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'redirection.cpp')

	SRC_LIB := $(shell find $(SRC_DIR) -name '*.cpp')
	TEST := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(TEST_DIR) -name '*.cpp')
else
	ALL_SOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp)
	SRC_MANIP := $(ALL_SOURCES) $(wildcard $(EX_DIR)/manipulators.cpp)
	SRC_PB := $(ALL_SOURCES) $(wildcard $(EX_DIR)/progressbar.cpp)
	SRC_GRAPH := $(ALL_SOURCES) $(wildcard $(EX_DIR)/graphics.cpp)
	SRC_REDIR := $(ALL_SOURCES) $(wildcard $(EX_DIR)/redirection.cpp)

	SRC_LIB := $(ALL_SOURCES)
	ALL_TESTS := $(wildcard $(TEST_DIR)/*.cpp) $(wildcard $(TEST_DIR)/*/*.cpp)
	TEST := $(ALL_SOURCES) $(ALL_TESTS)
endif

#====================================================
#     Source objects
#====================================================

# Source objects fo examples
OBJ_MANIP := $(SRC_MANIP:%=$(OBJ_DIR)/%.o)
OBJ_PB := $(SRC_PB:%=$(OBJ_DIR)/%.o)
OBJ_GRAPH := $(SRC_GRAPH:%=$(OBJ_DIR)/%.o)
OBJ_REDIR := $(SRC_REDIR:%=$(OBJ_DIR)/%.o)

# Other source objects
OBJ_LIB := $(SRC_LIB:%=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST:%=$(OBJ_DIR)/%.o)

#====================================================
#     Dependencies and flags
#====================================================
DEPS := $(OBJ_MANIP:.o=.d) $(OBJ_PB:.o=.d) $(OBJ_GRAPH:.o=.d) $(OBJ_REDIR:.o=.d)
ifeq ($(O_SYSTEM),$(filter $(O_SYSTEM),MacOS Linux))
	INC_DIR := $(shell find $(SRC_DIR) -type d)
else
	INC_DIR := $(SRC_DIR)
endif
INC_FLAGS := $(addprefix -I,$(INC_DIR))
WFLAGS := -Wall -Wextra -Wno-reorder -pedantic
CXXFLAGS := -std=c++17
CPPFLAGS := $(CXXFLAGS) $(INC_FLAGS) -MMD -MP $(WFLAGS)
LDFLAGS := -pthread -larsenalgear

#====================================================
#     Aliases
#====================================================
.PHONY: clean all

all: $(BUILD_DIR)/$(EX_MANIP_EXEC) $(BUILD_DIR)/$(EX_PB_EXEC) $(BUILD_DIR)/$(EX_GRAPH_EXEC) $(BUILD_DIR)/$(EX_REDIR_EXEC) $(BUILD_DIR)/$(TEST_EXEC) $(LIB_DIR)/$(LIB)
examples: $(BUILD_DIR)/$(EX_MANIP_EXEC) $(BUILD_DIR)/$(EX_PB_EXEC) $(BUILD_DIR)/$(EX_GRAPH_EXEC) $(BUILD_DIR)/$(EX_REDIR_EXEC) $(LIB_DIR)/$(LIB)
tests: $(BUILD_DIR)/$(TEST_EXEC)

#====================================================
#     Building examples
#====================================================

# Manipulators
$(BUILD_DIR)/$(EX_MANIP_EXEC): $(OBJ_MANIP)
	@ mkdir -p $(dir $@)
	$(CXX) $(OBJ_MANIP) -o $@ $(LDFLAGS)

# Progress bar
$(BUILD_DIR)/$(EX_PB_EXEC): $(OBJ_PB)
	@ mkdir -p $(dir $@)
	$(CXX) $(OBJ_PB) -o $@ $(LDFLAGS)

# Graphics
$(BUILD_DIR)/$(EX_GRAPH_EXEC): $(OBJ_GRAPH)
	@ mkdir -p $(dir $@)
	$(CXX) $(OBJ_GRAPH) -o $@ $(LDFLAGS)

# Redirection
$(BUILD_DIR)/$(EX_REDIR_EXEC): $(OBJ_REDIR)
	@ mkdir -p $(dir $@)
	$(CXX) $(OBJ_REDIR) -o $@ $(LDFLAGS)

#====================================================
#     Building tests
#====================================================
$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJ)
	@ mkdir -p $(dir $@)
	$(CXX) $(TEST_OBJ) -o $@ $(LDFLAGS)

#====================================================
#     Reordering objects
#====================================================
$(OBJ_DIR)/%.cpp.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#====================================================
#     Static library creation
#====================================================
$(LIB_DIR)/$(LIB): $(OBJ_LIB)
	@ mkdir -p $(dir $@)
	ar rcs $(LIB_DIR)/$(LIB) $(OBJ_LIB)

#====================================================
#     Clean
#====================================================
clean:
	rm -r $(OBJ_DIR) $(BUILD_DIR) $(LIB_DIR)

#====================================================
#     Include
#====================================================
-include $(DEPS)
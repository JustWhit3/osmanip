#====================================================
#     Variables
#====================================================

# Executabls
EX_MANIP_EXEC := manipulators
EX_PB_EXEC := progressbar
EX_GRAPH_EXEC := graphics
TEST_EXEC := tests

# Other
LIB := libosmanip.a
CC := g++

#====================================================
#     Folders
#====================================================

# Binary folders
BUILD_DIR := bin
OBJ_DIR := obj
LIB_DIR := lib

# Source folders
SRC_DIR := src
EX_DIR := examples
TEST_DIR := test

#====================================================
#     Source files
#====================================================

# Source files fo examples
SRC_MANIP := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'manipulators.cpp')
SRC_PB := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'progressbar.cpp')
SRC_GRAPH := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'graphics.cpp')

# Other source files
SRC_LIB := $(shell find $(SRC_DIR) -name '*.cpp')
TEST := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(TEST_DIR) -name '*.cpp')

#====================================================
#     Source objects
#====================================================

# Source objects fo examples
OBJ_MANIP := $(SRC_MANIP:%=$(OBJ_DIR)/%.o)
OBJ_PB := $(SRC_PB:%=$(OBJ_DIR)/%.o)
OBJ_GRAPH := $(SRC_GRAPH:%=$(OBJ_DIR)/%.o)

# Other source objects
OBJ_LIB := $(SRC_LIB:%=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST:%=$(OBJ_DIR)/%.o)

#====================================================
#     Dependencies and flags
#====================================================
DEPS := $(OBJ_MANIP:.o=.d) $(OBJ_PB:.o=.d) $(OBJ_GRAPH:.o=.d)
INC_DIR := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIR))
CPPFLAGS := -std=c++17 -g $(LDFLAGS) $(INC_FLAGS) -MMD -MP
LDFLAGS := -pthread -L/usr/local/lib -larsenalgear

#====================================================
#     Operating system detection
#====================================================

# Windows (Cygwin)
ifeq ($(OS), Windows_NT)
	TARGET_EXEC += .exe
	TEST_EXEC += .exe
endif

#====================================================
#     Aliases
#====================================================
.PHONY: clean all

all: $(BUILD_DIR)/$(EX_MANIP_EXEC) $(BUILD_DIR)/$(EX_PB_EXEC) $(BUILD_DIR)/$(EX_GRAPH_EXEC) $(BUILD_DIR)/$(TEST_EXEC) $(LIB_DIR)/$(LIB)
main: $(BUILD_DIR)/$(EX_MANIP_EXEC) $(BUILD_DIR)/$(EX_PB_EXEC) $(BUILD_DIR)/$(EX_GRAPH_EXEC) $(LIB_DIR)/$(LIB)
tests: $(BUILD_DIR)/$(TEST_EXEC)

#====================================================
#     Building examples
#====================================================

# Manipulators
$(BUILD_DIR)/$(EX_MANIP_EXEC): $(OBJ_MANIP)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_MANIP) -o $@ $(LDFLAGS)

# Progress bar
$(BUILD_DIR)/$(EX_PB_EXEC): $(OBJ_PB)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_PB) -o $@ $(LDFLAGS)

# Graphics
$(BUILD_DIR)/$(EX_GRAPH_EXEC): $(OBJ_GRAPH)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_GRAPH) -o $@ $(LDFLAGS)

#====================================================
#     Building tests
#====================================================
$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(TEST_OBJ) -o $@ $(LDFLAGS)

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

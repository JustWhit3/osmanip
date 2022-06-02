#====================================================
#     Variables
#====================================================
TARGET_EXEC := main
TEST_EXEC := tests
LIB := libosmanip.a
CC := g++

#====================================================
#     Folders
#====================================================
BUILD_DIR := bin
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := test
LIB_DIR := lib

#====================================================
#     Source files
#====================================================
SRC := $(shell find $(SRC_DIR) -name '*.cpp')
SRC_LIB := $(shell find $(SRC_DIR) -type f | grep -v 'main.cpp')
TEST := $(shell find $(SRC_DIR) -type f | grep -v 'main.cpp') $(shell find $(TEST_DIR) -name '*.cpp')

#====================================================
#     Source objects
#====================================================
OBJ := $(SRC:%=$(OBJ_DIR)/%.o)
OBJ_LIB := $(SRC_LIB:%=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST:%=$(OBJ_DIR)/%.o)

#====================================================
#     Dependencies and flags
#====================================================
DEPS := $(OBJ:.o=.d)
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

#====================================================
#     Building
#====================================================

#Building all:
all: $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/$(TEST_EXEC) $(LIB_DIR)/$(LIB)
main: $(BUILD_DIR)/$(TARGET_EXEC) $(LIB_DIR)/$(LIB)
tests: $(BUILD_DIR)/$(TEST_EXEC)

#Building main executable:
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

#Building test executable:
$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(TEST_OBJ) -o $@ $(LDFLAGS)

#Put object files into the object dir:
$(OBJ_DIR)/%.cpp.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#Create a static library from object files and put it in the library dir:
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

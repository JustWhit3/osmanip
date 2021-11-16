TARGET_EXEC := main
TEST_EXEC := tests
LIB := libosmanip.a
CC := g++

BUILD_DIR := bin
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := test
LIB_DIR := lib

SRC := $(shell find $(SRC_DIR) -name '*.cpp')
SRC_LIB := $(shell find $(SRC_DIR) -type f | grep -v 'main.cpp')
TEST := $(shell find $(SRC_DIR) -type f | grep -v 'main.cpp') $(shell find $(TEST_DIR) -name '*.cpp')

OBJ := $(SRC:%=$(OBJ_DIR)/%.o)
OBJ_LIB := $(SRC_LIB:%=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST:%=$(OBJ_DIR)/%.o)
DEPS := $(OBJ:.o=.d)

INC_DIR := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIR))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

.PHONY: clean all

all: $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/$(TEST_EXEC) $(LIB_DIR)/$(LIB)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(TEST_OBJ) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.cpp.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(LIB_DIR)/$(LIB): $(OBJ_LIB)
	@ mkdir -p $(dir $@)
	ar rcs $(LIB_DIR)/$(LIB) $(OBJ_LIB)

clean:
	rm -r $(OBJ_DIR) $(BUILD_DIR) $(LIB_DIR)
	
-include $(DEPS)

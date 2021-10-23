TARGET_EXEC := main
CC := g++

BUILD_DIR := .
SRC_DIR := src
OBJ_DIR := obj

SRC := $(shell find $(SRC_DIR) -name '*.cpp')
OBJ := $(SRC:%=$(OBJ_DIR)/%.o)
DEPS := $(OBJ:.o=.d)

INC_DIR := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIR))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.cpp.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(OBJ_DIR) main
	
-include $(DEPS)

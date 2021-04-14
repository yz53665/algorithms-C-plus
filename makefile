Q := @

TOP_DIR := ~/qrqCode/algorithms-C++
CC = g++
CFLAGS = -g -Wall
LIBS = -lm

SRC_DIR := $(shell find $(TOP_DIR) -type d)

HDR_DIR := $(SRC_DIR)
HDR_FILE := $(shell find $(HDR_DIR) -name "*.h")
HDR_FILE := $(patsubst %.h, %.cpp, $(HDR_FILE))
OBJ_FILE := $(patsubst %.cpp, %.o, $(HDR_FILE))

IND_CPP_FILE := $(filter-out $(HDR_FILE), $(shell find $(TOP_DIR) -name "*.cpp"))
IND_OBJ_FILE := $(patsubst %.cpp, %.o, $(IND_CPP_FILE))
PROG_TARGET := $(patsubst %.cpp, %, $(IND_CPP_FILE))

all: $(IND_OBJ_FILE) $(PROG_TARGET)

$(IND_OBJ_FILE): $(IND_CPP_FILE)
	$(Q)echo ": Compiling $< ..."
	$(CC) -o $@ -c $(patsubst %.o, %.cpp, $@) $(CFLAGS)

$(PROG_TARGET): $(OBJ_FILE)
	$(Q)echo "+ Linking $@ with $^"
	$(Q)$(CC) -o $@ $(CFLAGS) $(addsuffix .o, $@) $^ $(LIBS)

%.o: %.cpp
	$(Q)echo ": Compiling $< ..."
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean
clean:
	$(Q)rm -rf $(obj) $(OBJ_FILE) $(IND_OBJ_FILE) $(PROG_TARGET)

test:
	$(Q)echo $(IND_OBJ_FILE)


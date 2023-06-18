CC=g++
CFLAGS=-Wall
SUBDIRS=task1 task2 task3
BUILD_DIR=build
TARGETS=$(patsubst %, $(BUILD_DIR)/%, $(SUBDIRS))

all : $(BUILD_DIR) $(TARGETS)

$(BUILD_DIR)/% : %/*.cpp
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR) :
	mkdir $(BUILD_DIR)

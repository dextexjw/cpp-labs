CXX ?= g++
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra -pedantic
DBGFLAGS = -std=c++20 -g -O0 -Wall -Wextra -pedantic
BUILD = build

# usage:
# make run L=lesson1 FILE=main
# make debug L=lesson1 FILE=main
# make clean
L ?= lesson1
FILE ?= main

run:
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $(L)/$(FILE).cpp -o $(BUILD)/a
	@./$(BUILD)/a

debug:
	@mkdir -p $(BUILD)
	$(CXX) $(DBGFLAGS) $(L)/$(FILE).cpp -o $(BUILD)/a
	@gdb ./$(BUILD)/a

clean:
	rm -rf $(BUILD)

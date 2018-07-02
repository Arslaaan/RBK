OBJPATH = ./obj/
INCPATH = ./Include/
SRCPATH = ./src/
SRCMODULES = $(SRCPATH)Merchant.cpp $(SRCPATH)Guild.cpp
OBJMODULES = $(OBJPATH)Merchant.o $(OBJPATH)Guild.o
CXX = g++
CXXFLAGS = -Wall -g -I$(INCPATH) -std=c++11

$(OBJPATH)%.o: $(SRCPATH)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(SRCPATH)main.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o solution

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CXX) -I$(INCPATH) -MM $^ > $@

clean:
	rm -f $(OBJPATH)*.o solution deps.mk

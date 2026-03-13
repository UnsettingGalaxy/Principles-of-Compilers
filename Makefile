CXX     := g++
CXXFLAGS:= -Wall -Wextra -O2 -std=c++17
TARGET  := compiler
SRCS    := $(wildcard src/*.cpp)
OBJS    := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

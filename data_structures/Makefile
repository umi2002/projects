# Compiler options
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++20
INCLUDES =
OBJECTS=$(SOURCES:.cpp=.o)

# Linker options
LDLIBS =

# Source files
SRCS = $(wildcard *.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = linked_list

# Build rule
all: $(TARGET)
	@echo "Build complete."

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJS)

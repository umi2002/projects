# Compiler options
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
INCLUDES = -I/usr/include/qt -I/usr/include/cppitertools -I./logical/ -I./graphical/
OBJECTS=$(SOURCES:.cpp=.o) $(MOC_SOURCES:.cpp=.o)

# Linker options
LDLIBS = -lQt5Core -lQt5Gui -lQt5Widgets

# Source files
SRCS = $(wildcard *.cpp) $(wildcard logical/*.cpp) $(wildcard graphical/*.cpp)
MOC_HEADERS = $(wildcard *.h) $(wildcard logical/*.h) $(wildcard graphical/*.h)
MOC_SOURCES=$(MOC_HEADERS:.h=.moc.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o) $(MOC_SOURCES:.cpp=.o)

# Target executable
TARGET = tic-tac-toe

# Build rule
all: $(TARGET)
	@echo "Build complete."

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.moc.cpp: %.h
	moc $(MOC) $(INCLUDES) $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJS)

CXX = gcc -std=c++17
CXXFLAGS = -Wall -Og
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
EXEC=main

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.c
	$(CXX) -c -o $@ $< $(CXXFLAGS)


clean:
	rm -f $(OBJECTS) $(DEPENDS) $(EXEC)

CXX = gcc
CXXFLAGS = -Wall -Og `pkg-config --cflags --libs gtk+-3.0`
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
EXEC=main

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.c
	$(CXX) -c -o $@ $< $(CXXFLAGS)


clean:
	rm -f $(OBJECTS) $(DEPENDS) $(EXEC)

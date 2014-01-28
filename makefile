CC=g++
CFLAGS=-c -std=c++0x -Wall
LDFLAGS=
SOURCES=main.cpp RandomGenerator.cpp RandomIntGenerator.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=RandomGenerator


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

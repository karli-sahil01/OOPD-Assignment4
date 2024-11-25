CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS =

SOURCES = src/Author.cpp src/BibTeXParser.cpp src/Publication.cpp src/PublicationBase.cpp src/main.cpp
HEADERS = include/Author.h include/BibTeXParser.h include/Publication.h include/PublicationBase.h include/PublicationHandler.h

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = bibparser

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

.PHONY: run
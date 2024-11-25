CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS =

SOURCES = src/res_Author.cpp src/bibTeX_Parser.cpp src/research_Publication.cpp src/Pub_Base.cpp src/main.cpp
HEADERS = include/res_Author.h include/bibTeX_Parser.h include/research_Publication.h include/Pub_Base.h include/PublicationHandler.h

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
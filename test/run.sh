#!/bin/bash

# Define the base directory
BASE_DIR="project"

# Create the directory structure
mkdir -p "$BASE_DIR/data"
mkdir -p "$BASE_DIR/include"
mkdir -p "$BASE_DIR/src"

# Create files in the include directory
touch "$BASE_DIR/include/Author.h"
touch "$BASE_DIR/include/BibTexParser.h"
touch "$BASE_DIR/include/Publication.h"
touch "$BASE_DIR/include/PublicationBase.h"
touch "$BASE_DIR/include/PublicationHandler.h"

# Create files in the src directory
touch "$BASE_DIR/src/Author.cpp"
touch "$BASE_DIR/src/Author.o"
touch "$BASE_DIR/src/BibTexParser.cpp"
touch "$BASE_DIR/src/BibTexParser.o"
touch "$BASE_DIR/src/main.cpp"
touch "$BASE_DIR/src/main.o"
touch "$BASE_DIR/src/Publication.cpp"
touch "$BASE_DIR/src/Publication.o"
touch "$BASE_DIR/src/PublicationBase.cpp"
touch "$BASE_DIR/src/PublicationBase.o"
touch "$BASE_DIR/src/PublicationHandler.cpp"
touch "$BASE_DIR/src/PublicationHandler.o"

# Create files in the base directory
touch "$BASE_DIR/.gitignore"
touch "$BASE_DIR/bibparser.exe"
touch "$BASE_DIR/makefile"
touch "$BASE_DIR/README.md"
touch "$BASE_DIR/run.sh"

# Print completion message
echo "Directory and file structure created successfully!"

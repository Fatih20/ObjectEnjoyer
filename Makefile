CC = g++
STD = -std=c++17

OBJECTS = src/main.cpp $(filter-out src/Classes/*/main.cpp, $(wildcard src/Classes/*/*.cpp))
CINCLUDES = -Isrc -Isrc/Classes $(foreach a, $(wildcard src/Classes/*), -I$(a))

TARGET = bin/main

run : build
	$(TARGET)
build :
	$(CC) $(STD) $(CINCLUDES) $(OBJECTS) -o $(TARGET)

run-only:
	$(TARGET)
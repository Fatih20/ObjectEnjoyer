CC = g++
STD = -std=c++14

OBJECTS = src/main.cpp src/Classes/*/*.cpp
CINCLUDES = -Isrc -Isrc/Classes -Isrc/Classes/DeckPlayer/

TARGET = bin/main

run : build
	$(TARGET)
build :
	$(CC) $(STD) $(CINCLUDES) $(OBJECTS) -o $(TARGET)


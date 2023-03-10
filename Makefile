CC = g++
STD = -std=c++11

OBJECTS = src/main.cpp src/Classes/*/*.cpp
CINCLUDES = -Isrc -Isrc/Classes -Isrc/Classes/*/

TARGET = bin/main

run : build
	$(TARGET)
build :
	$(CC) $(STD) $(CINCLUDES) $(OBJECTS) -o $(TARGET)


CC = g++

OBJECTS = src/main.cpp src/Classes/*/*.cpp
CINCLUDES = -Isrc -Isrc/Classes

TARGET = bin/main

run : build
	$(TARGET)
build :
	$(CC) $(CINCLUDES) $(OBJECTS) -o $(TARGET)


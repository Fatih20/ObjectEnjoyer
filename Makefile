CC = g++

OBJECTS = src/main.cpp src/Classes/*/*.cpp
CINCLUDES = -Isrc

TARGET = bin/main

run :
	$(CC) $(CINCLUDES) $(OBJECTS) -o $(TARGET)
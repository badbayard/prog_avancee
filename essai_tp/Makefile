SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=main

CC=g++
CFLAGS=-Wall -pedantic -std=c++17 -ggdb

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	rm -f $(OBJECTS)

.PHONY: clean

veryclean: clean
	rm -f $(TARGET)
CXX := g++
override CXXFLAGS += -Wall -pedantic -std=c++14
LDLIBS := -pthread
OBJS := main.o server.o helper.o
BINARY := server

.PHONY: all clean debug help

debug: CXXFLAGS += -g -fsanitize=address

all: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${BINARY} ${OBJS} ${LDLIBS}

debug: all

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $*.o $*.cpp

clean:
	-rm -f *.o ${BINARY}

help:
	@cat README.txt
CXX := g++
override CXXFLAGS += -Wall -pedantic -std=c++14
LDLIBS := -pthread
SRC := src
OBJS := ${SRC}/consoleLogger.o ${SRC}/controller.o ${SRC}/dirResponse.o ${SRC}/errorLog.o ${SRC}/execResponse.o \
 ${SRC}/fileLogger.o ${SRC}/fileResponse.o ${SRC}/byeResponse.o ${SRC}/log.o ${SRC}/logger.o ${SRC}/notFoundResponse.o ${SRC}/parser.o \
 ${SRC}/request.o ${SRC}/requestLog.o ${SRC}/response.o ${SRC}/responseLog.o ${SRC}/server.o ${SRC}/shutdownLog.o \
 ${SRC}/worker.o ${SRC}/main.o ${SRC}/helper.o ${SRC}/threadPool.o

TESTDIR := router/tests
BINARY := sejvlpet

.PHONY: all clean debug help tests



debug: CXXFLAGS += -g -fsanitize=address

all: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${BINARY} ${OBJS} ${LDLIBS}

debug: all

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $*.o $*.cpp

clean:
	-rm -f *.o ${BINARY}
	-rm -f *.o ${OBJS}

run:
	./$(BINARY)

doc:
	Doxyfile src/*
	doxygen Doxyfile

tests:
	mkdir -p ${TESTDIR}/bin
	${CXX} ${CXXFLAGS} -o ${TESTDIR}/bin/helloWorld ${TESTDIR}/helloWorld.cpp
	${CXX} ${CXXFLAGS} -o ${TESTDIR}/bin/testBye ${TESTDIR}/testBye.cpp
	${CXX} ${CXXFLAGS} -o ${TESTDIR}/bin/testInvalidRequest ${TESTDIR}/testInvalidRequest.cpp
	${CXX} ${CXXFLAGS} -o ${TESTDIR}/bin/testNotFound ${TESTDIR}/testNotFound.cpp
	${CXX} ${CXXFLAGS} -o ${TESTDIR}/bin/testThreadPool ${TESTDIR}/testThreadPool.cpp

cleanTests:
	-rm -f -r ${TESTDIR}/bin


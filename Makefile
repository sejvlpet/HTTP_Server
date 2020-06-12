CXX := g++
override CXXFLAGS += -Wall -pedantic -std=c++17 -MMD -MP
LDLIBS := -pthread
SRC := src
OBJS := ${SRC}/consoleLogger.o ${SRC}/controller.o ${SRC}/dirResponse.o ${SRC}/errorLog.o ${SRC}/execResponse.o \
 ${SRC}/fileLogger.o ${SRC}/fileResponse.o ${SRC}/byeResponse.o ${SRC}/log.o ${SRC}/logger.o ${SRC}/notFoundResponse.o ${SRC}/parser.o \
 ${SRC}/request.o ${SRC}/requestLog.o ${SRC}/response.o ${SRC}/responseLog.o ${SRC}/server.o ${SRC}/shutdownLog.o \
 ${SRC}/worker.o ${SRC}/main.o ${SRC}/helper.o ${SRC}/threadPool.o

OBJS_DEPENDECIES := := ${SRC}/consoleLogger.d ${SRC}/controller.d ${SRC}/dirResponse.d ${SRC}/errorLog.d ${SRC}/execResponse.d \
 ${SRC}/fileLogger.d ${SRC}/fileResponse.d ${SRC}/byeResponse.d ${SRC}/log.d ${SRC}/logger.d ${SRC}/notFoundResponse.d ${SRC}/parser.d \
 ${SRC}/request.d ${SRC}/requestLog.d ${SRC}/response.d ${SRC}/responseLog.d ${SRC}/server.d ${SRC}/shutdownLog.d \
 ${SRC}/worker.d ${SRC}/main.d ${SRC}/helper.d ${SRC}/threadPool.d

TESTDIR := router/tests
BINARY := sejvlpet

.PHONY: all clean debug help tests



debug: CXXFLAGS += -g -fsanitize=address

all: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${BINARY} ${OBJS} ${LDLIBS}

debug: all

-include $(OBJ_FILES:.o=.d)

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $*.o $*.cpp

clean:
	-rm -f *.o ${BINARY}
	-rm -f *.o ${OBJS}
	-rm -f *.d ${OBJS_DEPENDECIES}

run:
	./$(BINARY)

doc:
	Doxyfile src/*
	doxygen Doxyfile

tests:
	mkdir -p ${TESTDIR}/bin
	${CXX} -o ${TESTDIR}/bin/helloWorld ${TESTDIR}/helloWorld.cpp
	${CXX} -o ${TESTDIR}/bin/testBye ${TESTDIR}/testBye.cpp
	${CXX} -o ${TESTDIR}/bin/testInvalidRequest ${TESTDIR}/testInvalidRequest.cpp
	${CXX} -o ${TESTDIR}/bin/testNotFound ${TESTDIR}/testNotFound.cpp
	${CXX} -o ${TESTDIR}/bin/testThreadPool ${TESTDIR}/testThreadPool.cpp
	${CXX} -o ${TESTDIR}/bin/testPermissions ${TESTDIR}/testPermissions.cpp
	${CXX} -o ${TESTDIR}/bin/testInvalidExecutable ${TESTDIR}/testInvalidExecutable.cpp


cleanTests:
	-rm -f -r ${TESTDIR}/bin


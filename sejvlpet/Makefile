CXX := g++
override CXXFLAGS += -Wall -pedantic -std=c++17 -MMD -MP
LDLIBS := -pthread -lstdc++fs
SRC := src
TESTDIR := examples/tests
BINARY := sejvlpet
BINARIES := binaries
TESTBINARIES:= ${TESTDIR}/bin
DOC:=doc

OBJS := ${SRC}/consoleLogger.o ${SRC}/controller.o ${SRC}/dirResponse.o ${SRC}/errorLog.o ${SRC}/execResponse.o \
 ${SRC}/fileLogger.o ${SRC}/fileResponse.o ${SRC}/byeResponse.o ${SRC}/log.o ${SRC}/logger.o ${SRC}/notFoundResponse.o ${SRC}/parser.o \
 ${SRC}/request.o ${SRC}/requestLog.o ${SRC}/response.o ${SRC}/responseLog.o ${SRC}/server.o ${SRC}/shutdownLog.o \
 ${SRC}/worker.o ${SRC}/main.o ${SRC}/helper.o ${SRC}/threadPool.o

OBJS_DEPENDECIES := ${SRC}/consoleLogger.d ${SRC}/controller.d ${SRC}/dirResponse.d ${SRC}/errorLog.d ${SRC}/execResponse.d \
 ${SRC}/fileLogger.d ${SRC}/fileResponse.d ${SRC}/byeResponse.d ${SRC}/log.d ${SRC}/logger.d ${SRC}/notFoundResponse.d ${SRC}/parser.d \
 ${SRC}/request.d ${SRC}/requestLog.d ${SRC}/response.d ${SRC}/responseLog.d ${SRC}/server.d ${SRC}/shutdownLog.d \
 ${SRC}/worker.d ${SRC}/main.d ${SRC}/helper.d ${SRC}/threadPool.d

TESTS := ${TESTBINARIES}/helloWorld ${TESTBINARIES}/testBye ${TESTBINARIES}/testInvalidRequest ${TESTBINARIES}/testNotFound \
 ${TESTBINARIES}/testPermissions ${TESTBINARIES}/testBye ${TESTBINARIES}/testThreadPool ${TESTBINARIES}/testInvalidExecutable \


.PHONY: all clean debug help compileTests cleanTests cleanAll compile run

all: compile doc


doc: Doxyfile
	mkdir -p ${DOC}
	doxygen Doxyfile
	ln -s html/index.html doc/index.html

debug: CXXFLAGS += -g -fsanitize=address

debug: all

compile: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${BINARY} ${OBJS} ${LDLIBS}


-include $(OBJS:.o=.d)


/%.o: /%.cpp
	${CXX} ${CXXFLAGS} -c -o $*.o $*.cpp

# /%: ${TESTDIR}/%.cpp
# 	${CXX} -o $*.o $*.cpp

cleanAll: clean cleanTests

clean:
	-rm -f *.o ${BINARY}
	-rm -f *.o ${OBJS}
	-rm -f *.d ${OBJS_DEPENDECIES}
	-rm -fr ${DOC}

run:
	./$(BINARY)

compileTests:
	mkdir -p ${TESTBINARIES}
# 	${CXX} -o ${TESTS}
	${CXX} -o ${TESTBINARIES}/helloWorld ${TESTDIR}/helloWorld.cpp
	${CXX} -o ${TESTBINARIES}/testFile ${TESTDIR}/testFile.cpp
	${CXX} -o ${TESTBINARIES}/testInvalidRequest ${TESTDIR}/testInvalidRequest.cpp
	${CXX} -o ${TESTBINARIES}/testNotFound ${TESTDIR}/testNotFound.cpp
	${CXX} -o ${TESTBINARIES}/testThreadPool ${TESTDIR}/testThreadPool.cpp
	${CXX} -o ${TESTBINARIES}/testPermissions ${TESTDIR}/testPermissions.cpp
	${CXX} -o ${TESTBINARIES}/testInvalidExecutable ${TESTDIR}/testInvalidExecutable.cpp
	${CXX} -o ${TESTBINARIES}/testDir ${TESTDIR}/testDir.cpp
	${CXX} -o ${TESTBINARIES}/testExecutable ${TESTDIR}/testExecutable.cpp


cleanTests:
	-rm -f -r ${TESTDIR}/bin

runTests:
	cd ${TESTDIR}; ./run.sh;
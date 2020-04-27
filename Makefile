# CXX := g++
# override CXXFLAGS += -Wall -pedantic -std=c++14
# LDLIBS := -pthread
# BINARY := server
#
# .PHONY: all clean debug help
#
# debug: CXXFLAGS += -g -fsanitize=address
#
# all: ${OBJS}
# 	${CXX} ${CXXFLAGS} -o ${BINARY} ${OBJS} ${LDLIBS}
#
# debug: all
#
# %.o: %.cpp
# 	${CXX} ${CXXFLAGS} -c -o $*.o $*.cpp
#
# clean:
# 	-rm -f *.o ${BINARY}
#
# help:
# 	@cat README.txt
#
#
#
#
#
#
# $(OBJS)response.o: src/io/response/fileResponse.h src/io/response/fileResponse.cpp \
#  src/io/response/response.h src/io/response/response.cpp
# $(OBJS)io.o: src/io/parser.h src/io/parser.cpp src/io/request.h src/io/request.cpp
# $(OBJS)log.o: src/log/errorLog.h src/log/errorLog.cpp src/log/log.h src/log/log.cpp \
#  src/log/requestLog.h src/log/requestLog.cpp src/log/responseLog.h src/log/responseLog.cpp \
#  src/log/shutDownLog.h src/log/shutDownLog.cpp
# $(OBJS)logger.o: src/logger/consoleLogger.h src/logger/consoleLogger.cpp src/logger/fileLogger.h  \
#  src/logger/fileLogger.cpp src/logger/logger.h src/logger/logger.cpp
# $(OBJS)logic.o: src/logic/controller.h src/logic/controller.cpp src/logic/server.h src/logic/server.cpp \
#  src/logic/worker.h src/logic/worker.cpp
# $(OBJS)main.o: main.cpp helper.h helper.cpp
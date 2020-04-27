cmake_minimum_required(VERSION 3.15)
project(pa2_server)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address -Wall -pedantic")


add_executable(pa2_server main.cpp helper.cpp helper.h src/logic/server.cpp src/logic/server.h src/logic/worker.cpp src/logic/worker.h src/logger/logger.cpp src/logger/logger.h src/log/log.cpp src/log/log.h src/logic/controller.cpp src/logic/controller.h src/io/parser.cpp src/io/parser.h src/io/request.cpp src/io/request.h src/io/response/response.cpp src/io/response/response.h src/log/responseLog.cpp src/log/responseLog.h src/log/requestLog.cpp src/log/requestLog.h src/log/shutdownLog.cpp src/log/shutdownLog.h src/log/errorLog.cpp src/log/errorLog.h src/logger/consoleLogger.cpp src/logger/consoleLogger.h src/logger/fileLogger.cpp src/logger/fileLogger.h src/io/response/fileResponse.cpp src/io/response/fileResponse.h)
cmake_minimum_required(VERSION 3.0.0)
project(cq-websocket-server VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(cq-websocket-server main.cpp ${SOURCES})

# set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
# target_compile_options(cq-websocket-server PRIVATE /MT)
# target_link_options(cq-websocket-server PRIVATE /INCREMENTAL:NO /NODEFAULTLIB:MSVCR)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


find_package(Drogon CONFIG REQUIRED)
target_link_libraries(cq-websocket-server PRIVATE Drogon::Drogon)

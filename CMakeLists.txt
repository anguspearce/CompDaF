cmake_minimum_required(VERSION 3.16.3)
project(raftlib-server)

include_directories(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
set(CMAKE_LINK_DIRECTORIES_BEFORE ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/third-party/install)
include(uWebSockets)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules(RAFT REQUIRED raftlib)

FIND_PACKAGE(TBB QUIET)
if (TBB_FOUND)
    message(STATUS "Found TBB using find_package")
else ()
    PKG_SEARCH_MODULE(TBB REQUIRED tbb)
    if (TBB_FOUND)
        message(STATUS "Found TBB using pkg-config")
    else()
        message(FATAL_ERROR "TBB not found")
    endif ()
endif()

FIND_PACKAGE(CFITSIO QUIET)
if (CFITSIO_FOUND)
    message(STATUS "Found cfitsio using find_package")
else ()
    PKG_SEARCH_MODULE(CFITSIO REQUIRED cfitsio)
    if (CFITSIO_FOUND)
        message(STATUS "Found cfitsio using pkg-config")
    else ()
        message(FATAL_ERROR "Could not find cfitsio")
    endif ()
endif()

FIND_PACKAGE(Protobuf REQUIRED)
FIND_PACKAGE(Threads)

ADD_SUBDIRECTORY(carta-protobuf)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(LINK_LIBS ${LINK_LIBS} stdc++fs)

include_directories(${CMAKE_SOURCE_DIR}/third-party/include)
install_uWebSockets()

set(LINK_LIBS
        ${LINK_LIBS}
        carta-protobuf
        ${PROTOBUF_LIBRARY}
        ${RAFT_LIBRARIES}
        uSockets
        z
        tbb
        cfitsio
        ${GTEST_LIBRARIES} 
        pthread
        ${CMAKE_THREAD_LIBS_INIT}
        )

set(SOURCE_FILES
        ${SOURCE_FILES}
        src/raft-backend/RaftlibServer.cpp
        src/raft-backend/Session.cpp
        src/raft-backend/FitsReader.cpp
         
        )

add_executable(raftlib-server ${SOURCE_FILES})
add_executable(unittest src/raft-backend/UnitTests.cpp src/raft-backend/FitsReader.cpp)

target_include_directories(raftlib-server PUBLIC ${RAFT_INCLUDE_DIRS})
target_compile_options(raftlib-server PUBLIC ${RAFT_CFLAGS})
target_link_libraries(raftlib-server ${LINK_LIBS})
target_include_directories(unittest PUBLIC ${RAFT_INCLUDE_DIRS})
target_compile_options(unittest PUBLIC ${RAFT_CFLAGS})
target_link_libraries(unittest ${LINK_LIBS})
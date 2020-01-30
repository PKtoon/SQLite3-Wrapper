cmake_minimum_required(VERSION 3.5)

project(sqlite3_wrapper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SQLite3 REQUIRED)

set(SQLITEDB
    sqlitedb.h
#    sqlitedb.cpp
    )

add_executable(main main.cpp ${SQLITEDB})
target_link_libraries(main ${SQLite3_LIBRARIES})

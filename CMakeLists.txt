cmake_minimum_required(VERSION 4.2)
project(OOP_Hausaufgabe)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_Hausaufgabe src/main.cpp
        src/CKonto.cpp
        src/CKonto.h
        src/CSparbuch.cpp
        src/CSparbuch.h
        src/CGirokonto.cpp
        src/CGirokonto.h)

add_executable(test_CKonto src/CKonto.cpp
        src/CKonto.h
        tests/test_CKonto.cpp)

add_executable(test_CSparbuch src/CKonto.cpp
        src/CKonto.h
        src/Csparbuch.cpp
        src/CSparbuch.h
        tests/test_CSparbuch.cpp)

add_executable(test_CGirokonto src/CKonto.cpp
        src/CKonto.h
        src/CGirokonto.cpp
        src/CGirokonto.h
        tests/test_CGirokonto.cpp)
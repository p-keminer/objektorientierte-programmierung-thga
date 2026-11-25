cmake_minimum_required(VERSION 4.2)
project(OOP_Hausaufgabe)

set(CMAKE_CXX_STANDARD 20)

add_executable(main src/main.cpp
        src/konten/CKonto.cpp
        src/konten/CKonto.h
        src/konten/CSparbuch.cpp
        src/konten/CSparbuch.h
        src/konten/CGirokonto.cpp
        src/konten/CGirokonto.h
        src/kunden/CKunde.cpp
        src/kunden/CKunde.h
        src/kunden/CBankkunde.cpp
        src/kunden/CBankkunde.h)

add_executable(main_CComplex src/main_CComplex.cpp
        src/CComplex/CComplex.cpp
        src/CComplex/CComplex.h)

add_executable(main_5_3 src/main_5_3.cpp
        src/main_5_3.h)

add_executable(test_CKonto src/konten/CKonto.cpp
        src/konten/CKonto.h
        src/kunden/CBankkunde.cpp
        src/kunden/CBankkunde.h
        src/kunden/CKunde.cpp
        src/kunden/CKunde.h
        tests/test_CKonto.cpp)

add_executable(test_CSparbuch src/konten/CKonto.cpp
        src/konten/CKonto.h
        src/konten/CSparbuch.cpp
        src/konten/CSparbuch.h
        src/kunden/CBankkunde.cpp
        src/kunden/CBankkunde.h
        src/kunden/CKunde.cpp
        src/kunden/CKunde.h
        tests/test_CSparbuch.cpp)

add_executable(test_CGirokonto src/konten/CKonto.cpp
        src/konten/CKonto.h
        src/konten/CGirokonto.cpp
        src/konten/CGirokonto.h
        src/kunden/CBankkunde.cpp
        src/kunden/CBankkunde.h
        src/kunden/CKunde.cpp
        src/kunden/CKunde.h
        tests/test_CGirokonto.cpp)

add_executable(test_CKunde src/kunden/CKunde.cpp
        src/kunden/CKunde.h
        tests/test_CKunde.cpp)

add_executable(test_CBankkunde src/kunden/CBankkunde.cpp
        src/kunden/CBankkunde.h
        src/kunden/CKunde.cpp
        src/kunden/CKunde.h
        src/konten/CKonto.cpp
        src/konten/CKonto.h
        src/konten/CSparbuch.cpp
        src/konten/CSparbuch.h
        src/konten/CGirokonto.cpp
        src/konten/CGirokonto.h
        tests/test_CBankkunde.cpp)



enable_testing()
add_test(NAME CKonto COMMAND test_CKonto)
add_test(NAME CSparbuch COMMAND test_CSparbuch)
add_test(NAME CGirokonto COMMAND test_CGirokonto)
add_test(NAME CKunde COMMAND test_CKunde)
add_test(NAME CBankkunde COMMAND test_CBankkunde)

cmake_minimum_required(VERSION 4.2)
project(OOP_Hausaufgabe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Kontoverwaltung

add_library(kontoverwaltung STATIC
        src/kontoverwaltung/konten/CKonto.cpp
        src/kontoverwaltung/konten/CSparbuch.cpp
        src/kontoverwaltung/konten/CGirokonto.cpp
        src/kontoverwaltung/kunden/CKunde.cpp
        src/kontoverwaltung/kunden/CBankkunde.cpp
        incl/kontoverwaltung/konten/CKonto.h
        incl/kontoverwaltung/konten/CSparbuch.h
        incl/kontoverwaltung/konten/CGirokonto.h
        incl/kontoverwaltung/kunden/CKunde.h
        incl/kontoverwaltung/kunden/CBankkunde.h)
target_include_directories(kontoverwaltung PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/incl")

add_executable(main_kontoverwaltung src/kontoverwaltung/main_kontoverwaltung.cpp)
target_link_libraries(main_kontoverwaltung PRIVATE kontoverwaltung)

enable_testing()
foreach(klasse IN ITEMS CKonto CSparbuch CGirokonto CKunde CBankkunde)
    add_executable(test_${klasse} tests/kontoverwaltung/test_${klasse}.cpp)
    target_link_libraries(test_${klasse} PRIVATE kontoverwaltung)
    add_test(NAME ${klasse} COMMAND test_${klasse})
endforeach()

# Komplexe Zahlen

add_library(komplexe_zahlen STATIC
        src/komplexe_zahlen/CComplex.cpp
        incl/komplexe_zahlen/CComplex.h)
target_include_directories(komplexe_zahlen PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/incl")

add_executable(main_CComplex src/komplexe_zahlen/main_CComplex.cpp)
target_link_libraries(main_CComplex PRIVATE komplexe_zahlen)

# Funktionstemplates

add_executable(main_5_3
        src/funktionstemplates/main_5_3.cpp
        incl/funktionstemplates/main_5_3.h)

target_include_directories(main_5_3 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/incl")


add_custom_target(run_all
        COMMAND "$<TARGET_FILE:main_kontoverwaltung>"
        COMMAND "$<TARGET_FILE:main_CComplex>"
        COMMAND "$<TARGET_FILE:main_5_3>"
        DEPENDS main_kontoverwaltung main_CComplex main_5_3
        VERBATIM
)
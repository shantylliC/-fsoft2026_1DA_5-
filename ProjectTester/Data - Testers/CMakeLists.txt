cmake_minimum_required(VERSION 3.22)
project(TravelTester)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_DIR ../../Project/Datas)

include_directories(${PROJECT_DIR})

set(SOURCE_FILES
        ${PROJECT_DIR}/data.h
        ${PROJECT_DIR}/data.cpp
)

# Google Test como subpasta (igual ao exemplo do professor)
set(GOOGLE_TEST_LIB ${PROJECT_SOURCE_DIR}/googletest-main)
add_subdirectory(${GOOGLE_TEST_LIB})
include_directories(${GOOGLE_TEST_LIB}/googletest/include)

add_executable(TravelTester
        main.cpp
        ${SOURCE_FILES}
)

target_link_libraries(TravelTester gtest gtest_main)

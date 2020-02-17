cmake_minimum_required(VERSION 3.16.4)
project(Lyrics_Checker)

set(CMAKE_CXX_STANDARD 20)

set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking
find_package(Boost 1.72.0 REQUIRED COMPONENTS filesystem)
include_directories(${Boost_INCLUDE_DIR})
add_executable(${PROJECT_NAME} search.cpp)
# link Boost libraries to the new target
target_link_libraries(${PROJECT_NAME} stdc++fs ${Boost_LIBRARIES})

# link Boost with code library
#target_link_libraries(cmake_testapp_boost test_library)

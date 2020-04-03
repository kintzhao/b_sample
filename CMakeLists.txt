SET(PROJECT_NAME B-sample)

PROJECT(${PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# CMAKE_BUILD_TYPE
set(BUILD_TYPE Debug)

# setting path
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# libraries
#find_package(Eigen3 REQUIRED)
find_package(OpenCV QUIET)

# gcc flags
add_definitions("-DENABLE_SSE")
set(CMAKE_CXX_FLAGS
   "${SSE_FLAGS} -O0 -g -std=c++11 -march=native"
)

# include
include_directories(${PROJECT_SOURCE_DIR}/math)
include_directories( ${OpenCV_INCLUDE_DIRS} )
   
# src 
set(PROJECT_SRC 
   ${PROJECT_SOURCE_DIR}/main.cpp
   ${PROJECT_SOURCE_DIR}/b_spline.cpp)
                    
add_executable(${PROJECT_NAME} ${PROJECT_SRC} )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

add_executable(test test.cpp  b_spline.cpp)
target_link_libraries(test ${OpenCV_LIBS})



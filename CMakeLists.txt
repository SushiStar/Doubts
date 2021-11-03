########################################################################
# When you have doubts on some libs, api usages, go test here.
# Then log down what you've learned
#
# Author: Wei Du
# Email: wweeii.du@gmail.com
########################################################################

project(Doubts) 
cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DBG "-ggdb -O0 -pg -DDEBUG")

set(CMAKE_MODULE_PATH 
        ${CMAKE_MODULE_PATH}
        /usr/local/share/cmake/Modules
        /usr/local/lib/cmake/Modules
        /opt/dex/lib/cmake/Modules
    )
set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH}
        /usr/local/lib/
        /usr/local/
        /opt/dex/
        /opt/dex/lib/
    )

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)


# find_package(Eigen3 REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(Threads)


########################################################################
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
# set(SRCS
        # src/
    # )

add_executable(stl_transform src/stl_transform.cpp)
add_executable(string_test src/string.cpp)
add_executable(stl_math src/stl_math.cpp)
add_executable(bit_operation src/bitoperation.cpp)

add_executable(eigen_test src/eigen.cpp)
target_link_libraries(eigen_test Eigen3::Eigen)

add_executable(eigen_spline src/eigen_spline.cpp)
target_link_libraries(eigen_spline Eigen3::Eigen)

add_executable(stl_thread src/stl_thread.cpp)
target_link_libraries(stl_thread pthread)

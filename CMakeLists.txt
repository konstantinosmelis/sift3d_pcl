cmake_minimum_required(VERSION 3.5)
project(sift3d)
set(CMAKE_CXX_STANDARD 17)

set(PCL_DIR ./lib/pcl/share/pcl-1.14/)
find_package(PCL REQUIRED)
if(PCL_FOUND)
    include_directories(${PCL_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "PCL headers not found")
endif()

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
if(Python3_FOUND AND Python3_Interpreter_FOUND AND Python3_Development_FOUND)
    include_directories(${Python3_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Python3 headers not found")
endif()

execute_process(COMMAND ${Python3_EXECUTABLE} -c "import numpy; print(numpy.get_include())"
    OUTPUT_VARIABLE Python3NumPy_INCLUDE_DIRS
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE Python3NumPy_NOT_FOUND
)

if(Python3NumPy_NOT_FOUND)
    message(FATAL_ERROR "Python NumPy headers not found")
else()
    include_directories(${Python3NumPy_INCLUDE_DIRS})
endif()

add_library(sift3d SHARED
    src/sift3d_module.cpp
    src/sift3d.cpp
    src/lib_utils.cpp
)

target_include_directories(sift3d PRIVATE
    ${Python3_INCLUDE_DIRS}
)

target_link_libraries(sift3d PRIVATE
    ${Python3_LIBRARIES}
    ${PCL_LIBS}
)

set_target_properties(sift3d PROPERTIES
    PREFIX ""
    SUFFIX ".${Python3_SOABI}${CMAKE_SHARED_LIBRARY_SUFFIX}"
    OUTPUT_NAME "sift3d"
    LINKER_LANGUAGE C
)

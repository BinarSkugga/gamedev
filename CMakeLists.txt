cmake_minimum_required(VERSION 3.20)
project(gamedev)

set(CMAKE_CXX_STANDARD 23)
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

file(GLOB_RECURSE classes ${SRC}/*.cpp)
file(GLOB_RECURSE shaders ${SRC}/shaders/*)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} GLFW ${SRC}/headers)
file(COPY ${shaders} DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(gamedev ${classes})
target_link_libraries(gamedev ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw tbb)

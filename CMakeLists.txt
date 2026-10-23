cmake_minimum_required(VERSION 3.10)
project(BlackHole)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# standart c++17
set(Open_GL_PREFFERENCE GLVND)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# .h files dir:
include_directories(include)

# find packages
set(Open_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(GLEW)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# .cpp files dir:
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add executable
add_executable(BlackHole ${SOURCES})

# linking libraries
target_link_libraries(BlackHole
    PRIVATE
    OpenGL::GL
    GLEW::GLEW
    glfw
    glm::glm
)


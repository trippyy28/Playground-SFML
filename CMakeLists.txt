cmake_minimum_required(VERSION 3.16)
project(Playground LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add the executable
add_executable(Playground
    src/main.cpp
    src/AnimationB.cpp
    src/Healer.cpp
    src/Game.cpp
    src/Scene.cpp
    src/ResourceManager.cpp
    src/Entity.cpp
    src/FloatingShapes.cpp
    src/DjBooth.cpp
    src/Menu.cpp
    src/Bullets.cpp
)

# Link SFML libraries
target_link_libraries(Playground PRIVATE sfml-graphics sfml-audio)

# Set C++ standard
target_compile_features(Playground PRIVATE cxx_std_17)

# Enable debug symbols
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Copy OpenAL DLL for Windows
if(WIN32)
    add_custom_command(
        TARGET Playground
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Playground>
        VERBATIM)
endif()

# Install target
install(TARGETS Playground)

cmake_minimum_required(VERSION 3.13.4)

project(pw-monitor)

add_executable(${PROJECT_NAME} sources/main.cpp)

add_subdirectory(sources)

target_include_directories(${PROJECT_NAME} 
    PUBLIC sources/
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC sources/
)

target_link_libraries(${PROJECT_NAME}

    files
)
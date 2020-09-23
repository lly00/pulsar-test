set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin)

set(SOURCES
    ./pulsar.cpp
)

FIND_LIBRARY(PULSAR pulsar /usr/lib NO_DEFAULT_PATH)
include_directories(${PULSAR_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(PulsarTest main.cpp)
target_link_libraries(PulsarTest pulsar)
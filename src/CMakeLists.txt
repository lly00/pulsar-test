set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin)

set(SOURCES
    ./producer.cpp
    ./consumer.cpp
    ./pulsar.cpp
)

FIND_LIBRARY(PULSAR pulsar /usr/lib NO_DEFAULT_PATH)
include_directories(${PULSAR_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_library(Lib STATIC ${SOURCES})
add_executable(PulsarTest main.cpp)
target_link_libraries(PulsarTest pulsar)
target_link_libraries(PulsarTest Lib)

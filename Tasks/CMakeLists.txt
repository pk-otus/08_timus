
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TIMUS_TESTFILE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

configure_file(current_task.h.in ${CMAKE_CURRENT_SOURCE_DIR}/current_task.h)

file(GLOB_RECURSE TIMUS_TASKS *.cpp)

add_library(timus_tasks ${TIMUS_TASKS})
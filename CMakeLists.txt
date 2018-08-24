cmake_minimum_required(VERSION 3.2)

project(Timus)

set(TIMUS_CURRENT_TASK 1837)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
endif()

find_package(GTest REQUIRED)

add_subdirectory(Tasks)

add_executable(timus_test test_main.cpp)
add_executable(timus main.cpp)

set_target_properties(timus_test PROPERTIES INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS} )
target_link_libraries(timus_test timus_tasks ${GTEST_LIBRARIES})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties(timus PROPERTIES
		COMPILE_OPTIONS -W3 
	)	

else()
	set_target_properties(timus PROPERTIES
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra 
	)	
	target_link_libraries(timus_test pthread)
endif()

target_link_libraries(timus timus_tasks)

enable_testing()
add_test(CurrentTask timus_test)

add_custom_command(
	OUTPUT timus_test_completed
	COMMAND ctest -C $<CONFIGURATION> --output-on-failure
	COMMAND cmake -E touch timus_test_completed
	DEPENDS timus_test
)

add_custom_target(libtest_force ALL DEPENDS timus_test_completed)

install(TARGETS timus RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT a@a.a)

include (CPack)
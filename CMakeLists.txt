cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(proba_cpp VERSION 0.2)

SET(SOURCES_DIR src)

configure_file(
	${SOURCES_DIR}/config.hpp.in
	${CMAKE_CURRENT_BINARY_DIR}/config.hpp
)

set(TARGET_FIRST first)
set(SOURCES ${SOURCES_DIR}/options.cpp ${SOURCES_DIR}/version.cpp ${SOURCES_DIR}/option_app.cpp)
set(HEADERS ${SOURCES_DIR}/version.hpp ${SOURCES_DIR}/option_app.hpp)

find_package(Boost COMPONENTS program_options)


if (Boost_FOUND)
	add_executable(${TARGET_FIRST} ${SOURCES})
	target_include_directories(${TARGET_FIRST} PUBLIC ${Boost_INCLUDE_DIRS})
	target_link_libraries(${TARGET_FIRST} ${Boost_LIBRARIES})
endif()

set_target_properties(
	${TARGET_FIRST} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

target_include_directories(
	${TARGET_FIRST}
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)

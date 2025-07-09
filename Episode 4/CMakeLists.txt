cmake_minimum_required(VERSION 3.20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

project(Episode4 VERSION 1.0.0 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core)

qt_wrap_ui(UI_HEADERS UI/*.ui)
FILE(GLOB SOURCE_FILES *.cpp *.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${UI_HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core)

set_target_properties(${PROJECT_NAME} PROPERTIES
	WIN32_EXECUTABLE ON
	AUTOUIC ON
)
cmake_minimum_required(VERSION 3.1)
project(opencam VERSION 1.0.0)

add_library(
	blob
	blob.h
	blob.cpp
)

add_library(
	recorder
	recorder.h
	recorder.cpp 
)

#set(OpenCV_DIR "C:/Dev\openCV_build\build\install")
#set(OpenCV_DIR "C:/Dev/openCV_build/build/install")

find_package(OpenCV REQUIRED)

target_compile_definitions(recorder PUBLIC RASPBERRYPI)

add_executable(${PROJECT_NAME} main.cpp) 

target_link_libraries(blob ${OpenCV_LIBS})
target_link_libraries(recorder ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} blob recorder ${OpenCV_LIBS})

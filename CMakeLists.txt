PROJECT(v)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6) 
find_package(OpenCV REQUIRED)
include_directories(photo)
include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})

ADD_SUBDIRECTORY(photo)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(v ${DIR_SRCS}  )
TARGET_LINK_LIBRARIES( v opcv )

target_link_libraries(v ${OpenCV_LIBS})
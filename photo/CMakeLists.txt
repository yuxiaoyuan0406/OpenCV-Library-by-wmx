find_package(OpenCV REQUIRED)

find_package(raspicam REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${raspicam_INCLUDE_DIRS})


link_libraries(${OpenCV_LIBS})

link_libraries(${raspicam_LIBS})


link_libraries(${raspicam_CV_LIBS})


AUX_SOURCE_DIRECTORY(. DIR_OPCV_SRCS)

ADD_LIBRARY ( opcv ${DIR_OPCV_SRCS})

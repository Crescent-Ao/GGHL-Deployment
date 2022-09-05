cmake_minimum_required(VERSION 3.0.0)
project(ncnn_GGHL VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ncnn_GGHL main.cpp GGHL.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(OpenCV_DIR /home/crescent/build)
set(ncnn_DIR /home/crescent/ncnn/build/src)

include_directories(/home/crescent/GGHL-Deployment/ncnn/)

# find Opencv 
find_package(OpenCV REQUIRED)
find_package(ncnn REQUIRED)
target_link_libraries(ncnn_GGHL ${OpenCV_LIBS})
target_link_libraries(ncnn_GGHL ncnn)
include(CPack)

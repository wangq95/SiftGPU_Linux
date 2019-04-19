cmake_minimum_required(VERSION 2.8.3)
project(test_siftgpu)

# OpenCV依赖
find_package( OpenCV REQUIRED )

# OpenGL
find_package(OpenGL REQUIRED)

# GLUT
find_package(GLUT REQUIRED)

# Glew
find_package(Glew REQUIRED)

# SiftGPU：手动设置其头文件与库文件所在位置
include_directories("/home/mac-ar/SiftGPU/src/SiftGPU/" ${OpenGL_INCLUDE_DIR} ${CUDA_INCLUDE_DIR})
set(SIFTGPU_LIBS "/home/mac-ar/SiftGPU/bin/libsiftgpu.so")

add_executable( testSIFTGPU main.cpp )

target_link_libraries( testSIFTGPU
    ${OpenCV_LIBS}
    ${SIFTGPU_LIBS}
    ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES}
    ${CUDA_LIB_PATH}
)

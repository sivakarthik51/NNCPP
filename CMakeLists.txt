cmake_minimum_required(VERSION 3.7)
project(nnfs)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -pthread -std=c++14")

 include_directories("/usr/local/include" "/usr/local/opt/llvm/include")
 link_directories("/usr/local/lib" "/usr/local/opt/llvm/lib")

add_executable(
    nnfs
    src/main.cpp
    src/Neuron.cpp
    src/Layer.cpp
    src/Matrix.cpp
    src/NeuralNetwork.cpp
  
)
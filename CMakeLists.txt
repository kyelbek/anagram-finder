cmake_minimum_required(VERSION 3.23)
project(anagram-finder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")


add_executable(anagram-finder main.cpp Algorithm/Dictionary.cpp Algorithm/Dictionary.h Algorithm/AnagramChain.cpp Algorithm/AnagramChain.h io.cpp io.h helpers/WordFuncs.cpp helpers/WordFuncs.h)

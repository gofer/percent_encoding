#!/bin/sh
CXX=g++
CXXFLAGS=-Iinclude -std=c++11
${CXX} ${CXXFLAGS} -o test.out src/percent_encoding_encode.cpp src/percent_encoding_decode.cpp test/percent_encoding_test.cpp -lstdc++

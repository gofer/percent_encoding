TARGET = libpercent_encoding.a

SRCS = src/percent_encoding_encode.cpp src/percent_encoding_decode.cpp
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CXXFLAGS += -std=c++11 -Iinclude
ARFLAGS = rsv

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test: $(TARGET)
	@#cd test; make test GTEST_DIR=/usr/local/googletest/googletest-1.8.0
	@echo 'test!'

clean:
	#pushd test && make clean && popd
	rm -f src/*.o

distclean:
	#pushd test && make distclean && popd
	make clean && rm -f $(TARGET)
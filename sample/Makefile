TARGET = percent_encode.out

SRCS = percent_encoding_test.cpp
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CXXFLAGS += -std=c++11 -I../include
LDFLAGS = -L..

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ -lpercent_encoding -lstdc++

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

check: $(TARGET)
	@echo 'こんにちは' |  LD_LIBRARY_PATH=..:${LD_LIBRARY_PATH} ./$(TARGET) -s

clean:
	rm -f *.o

distclean:
	make clean && rm -f $(TARGET)

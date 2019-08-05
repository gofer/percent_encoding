TARGET = test.out

SRCS=test.cpp
OBJS=$(addsuffix .o,$(basename $(SRCS)))

LD = g++
LDFLAGS += -L.. $(shell pkg-config --libs gtest gtest_main)
CXXFLAGS += -std=c++11 -I../include $(shell pkg-config --cflags gtest gtest_main)

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -lpercent_encoding $(MYLIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

check: $(TARGET)
	@LD_LIBRARY_PATH=..:${LD_LIBRARY_PATH} ./$(TARGET)

clean:
	rm -f *.o

distclean:
	make clean && rm -f $(TARGET)

MAJOR_VERSION=0
VERSION=$(MAJOR_VERSION).0.1

STATIC_TARGET = libpercent_encoding.a
SHARED_TARGET = libpercent_encoding.so
SHARED_TARGETS = $(SHARED_TARGET).$(VERSION) $(SHARED_TARGET).$(MAJOR_VERSION)	$(SHARED_TARGET)
TARGET += $(STATIC_TARGET) $(SHARED_TARGETS)

SRCS = src/percent_encoding_encode.cpp src/percent_encoding_decode.cpp
OBJS = $(addsuffix .o,$(basename $(SRCS)))
SOBJS = $(addsuffix .so,$(basename $(SRCS)))

override CXXFLAGS += -std=c++11 -Iinclude
SHARED_CXXFLAGS += -shared -fPIC
SHARED_LDFLAGS += -shared -Wl,-soname=libpercent_encoding.so.$(VERSION)
ARFLAGS = -rsv

.SUFFIXES: .cpp .hpp .o .so .a
.PHONY: all test clean distclean

all: $(TARGET)

debug:
	make all CXXFLAGS='-g -D__DEBUG__'

$(STATIC_TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(SHARED_TARGET): $(SHARED_TARGET).$(VERSION)
	if [ ! -f $@ ]; then ln -s $(SHARED_TARGET).$(VERSION) $@; fi

$(SHARED_TARGET).$(MAJOR_VERSION): $(SHARED_TARGET).$(VERSION)
	if [ ! -f $@ ]; then ln -s $(SHARED_TARGET).$(VERSION) $@; fi

$(SHARED_TARGET).$(VERSION): $(SOBJS)
	$(CXX) $(LDFLAGS) $(SHARED_LDFLAGS) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.cpp.so:
	$(CXX) $(CXXFLAGS) $(SHARED_CXXFLAGS) -o $@ -c $<

check: $(TARGET)
	make -f Makefile all
	pushd test && make check && popd

clean:
	pushd test && make clean && popd
	pushd sample && make clean && popd
	rm -f src/*.{o,so}

distclean:
	pushd test && make distclean && popd
	pushd sample && make distclean && popd
	make clean
	for target in "$(TARGET)"; do rm -f $${target}; done

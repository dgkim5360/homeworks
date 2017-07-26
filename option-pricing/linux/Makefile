CXX=g++
TARGET=main
OBJS=obj/main.o
OBJS_SO=obj/pricing.o
SHAREDLIB=lib/libpricing.so
SRCS=src/main.cc include/pricing.h
SRCS_SO=src/pricing.cc
CXXFLAGS=-Wall -Werror -Iinclude
CXXFLAGS_SO=-Wall -Werror -fPIC -std=c++11
SHAREDFLAG=-shared
LDFLAGS=-Llib -lpricing

run: $(TARGET)
	LD_LIBRARY_PATH=./lib:$(LD_LIBRARY_PATH) ./main

$(TARGET): $(SHAREDLIB) $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(SHAREDLIB): $(OBJS_SO)
	$(CXX) $(SHAREDFLAG) -o $@ $<

$(OBJS_SO): $(SRCS_SO)
	$(CXX) $(CXXFLAGS_SO) -o $@ -c $<

clean:
	$(RM) $(TARGET) $(SHAREDLIB) $(OBJS) $(OBJS_SO)

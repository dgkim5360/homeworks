CXX=x86_64-w64-mingw32-g++
TARGET=main.exe
OBJS=obj/main.o
OBJS_DLL=obj/pricing.o
DLL=lib/pricing.dll
SRCS=src/main.cpp include/pricing.h
SRCS_DLL=src/pricing.cpp
CXXFLAGS=-Wall -Werror -Iinclude
CXXFLAGS_DLL=-DBUILDING_PRICING -Wall -Werror -Iinclude -std=c++11
SHAREDFLAG=-shared
LDFLAGS=-Llib -lpricing

$(TARGET): $(DLL) $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(DLL): $(OBJS_DLL)
	$(CXX) $(SHAREDFLAG) -o $@ $<

$(OBJS_DLL): $(SRCS_DLL)
	$(CXX) $(CXXFLAGS_DLL) -o $@ -c $<

clean:
	$(RM) $(TARGET) $(DLL) $(OBJS) $(OBJS_DLL)

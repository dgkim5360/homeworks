CXX=x86_64-w64-mingw32-g++
TARGET=main.exe
OBJS=obj/main.o
OBJS_DLL=obj/pricing.o
DLL=lib/libpricing.dll
SRCS=src/main.cpp include/pricing.h
SRCS_DLL=src/pricing.cpp
DEF=src/pricing.def
CXXFLAGS=-Wall -Werror -Iinclude -static-libgcc -static-libstdc++
CXXFLAGS_DLL=-DBUILDING_PRICING -Wall -Werror -Iinclude -std=c++11
SHAREDFLAG=-shared -Wl,--kill-at # -Wl,--add-stdcall-alias
LDFLAGS=-Llib -lpricing
MINGWPATH=/usr/lib/gcc/x86_64-w64-mingw32/5.3-win32

run: $(TARGET)
	cp $(MINGWPATH)/libstdc++-6.dll ./
	cp $(MINGWPATH)/libgcc_s_seh-1.dll ./
	cp $(DLL) ./
	wine main.exe

$(TARGET): $(DLL) $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(DLL): $(OBJS_DLL)
	$(CXX) $(SHAREDFLAG) -o $@ $< $(DEF)

$(OBJS_DLL): $(SRCS_DLL)
	$(CXX) $(CXXFLAGS_DLL) -o $@ -c $<

clean:
	$(RM) $(TARGET) $(DLL) $(OBJS) $(OBJS_DLL) *.dll

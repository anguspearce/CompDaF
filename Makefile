FILES := RaftlibServer
override CXXFLAGS += -lpthread -Wpedantic -Wall -Wextra -Wsign-conversion -Wconversion -std=c++2a -IuWebSockets/uSockets/src -IuWebSockets/src 
override LDFLAGS += uWebSockets/uSockets/*.o -lz 

DESTDIR ?=
prefix ?= /usr/local

.PHONY: examples
examples:
	$(MAKE) -C uWebSockets/uSockets; \
	for FILE in $(FILES); do $(CXX) -flto -O3 $(CXXFLAGS)  src/backend/$$FILE.cpp  -o $$FILE $(LDFLAGS) & done; \
	wait

clean:
	rm -rf $(FILES)
	rm -rf fuzzing/*.o benchmarks/*.o

pa15: pa15.o
	$(CXX) $(CXXFLAGS) pa15.o -o pa15

pa15.o: pa15.cpp
	$(CXX) $(CXXFLAGS) pa15.cpp -c

clean:
	rm -f pa15.o pa15

turnin:
	turnin -c cs202 -p pa15 -v pa15.cpp recursive.hpp Makefile

hello: hello.cpp
	c++ -O3 -shared -std=c++11 -Wall -fPIC -I ./third_party/pybind11/include `python3-config --cflags --ldflags --libs` hello.cpp -o hello.so
clean:
	rm -f *.o hello.so

#include <pybind11/pybind11.h>
#include <string>
#include <iostream>

#define self (*this) // !important


const std::string output(const std::string str)
{
    std::cout << str << std::endl;

    return str;
}



class SomeObject
{
    int value;

public:
    SomeObject(const int x) : value(x) {}
    SomeObject(const SomeObject& r) : value(r.value) {}

    const int get_value() const
    {
        return self.value;
    }

    void set_value(const int x)
    {
        self.value = x;
    }
};

namespace py = pybind11;

PYBIND11_PLUGIN(hello) {
    py::module m("hello", "pybind11 example plugin");

    m.def("output", &output, "output string");

    py::class_<SomeObject>(m, "SomeObject")
        .def(py::init<const int &>())
        .def("get_value", &SomeObject::get_value)
        .def("set_value", &SomeObject::set_value);
    
    return m.ptr();
}

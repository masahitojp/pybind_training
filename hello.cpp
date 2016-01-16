#include <pybind11/pybind11.h>
#include <string>
#include <iostream>

class SomeObject
{
    int value;

public:
    SomeObject(const int x) : value(x) {}
    SomeObject(const SomeObject& r) : value(r.value) {}

    const int get_value() const
    {
        return this->value;
    }

    void set_value(const int x)
    {
        this->value = x;
    }
};

const std::string output(const std::string str)
{
    std::cout << str << std::endl;

    return str;
}


int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_PLUGIN(hello) {
    py::module m("hello", "pybind11 example plugin");

    m.def("add", &add, "A function which adds two numbers",
      py::arg("i") = 1, py::arg("j") = 2);
    m.def("output", &output, "output string");

    py::class_<SomeObject>(m, "SomeObject")
        .def(py::init<const int &>())
        .def("get_value", &SomeObject::get_value)
        .def("set_value", &SomeObject::set_value);
    
    return m.ptr();
}

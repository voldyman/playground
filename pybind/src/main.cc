#include <pybind11/pybind11.h>
#include <iostream>

namespace py = pybind11;

class Printer {
  public:
    explicit Printer() {
    }

    void print(std::string str) {
        std::cout << str << std::endl;
    }
};

PYBIND11_PLUGIN(nativefn) {
    py::module m("nativefn", "native fn's for python");

    py::class_<Printer>(m, "Printer")
        .def(py::init<>())
        .def("pprint", &Printer::print);
}

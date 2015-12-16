#include <pybind11/pybind11.h>
#include <gtkmm.h>
#include <iostream>

namespace py = pybind11;

class Gui {
  public:
    explicit Gui() {
    }

    void show() {
        std::cout << "Showing" << std::endl;
    }
};

PYBIND11_PLUGIN(gui) {
    py::module m("gui", "gtk gui for python");

    py::class_<Gui>(m, "Gui")
        .def(py::init<>())
        .def("show", &Gui::show);
}

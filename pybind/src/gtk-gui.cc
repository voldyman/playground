#include <pybind11/pybind11.h>
#include <gtkmm.h>
#include <iostream>
#include <memory>

namespace py = pybind11;


  namespace sigc {
//  SIGC_FUNCTORS_HAVE_RESULT_TYPE
//    SIGC_FUNCTORS_DEDUCE_RESULT_TYPE_WITH_DECLTYPE
}


class Gui {
  public:
    explicit Gui() {
    }

    void show() {
        std::cout << "Showing" << std::endl;
        char **args;
        auto app =
            Gtk::Application::create("org.gtkmm.examples.base");

        Gtk::Window window;
        window.set_default_size(200, 200);

        app->run(window, 0, args);
    }
};

PYBIND11_PLUGIN(gui) {
    py::module m("gui", "gtk gui for python");

    py::class_<Gui>(m, "Gui")
        .def(py::init<>())
        .def("show", &Gui::show);
}

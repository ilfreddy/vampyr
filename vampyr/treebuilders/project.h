#pragma once

#include <pybind11/functional.h>

#include <MRCPP/treebuilders/project.h>

namespace vampyr {
template <int D> void project(pybind11::module &m) {
    using namespace mrcpp;
    namespace py = pybind11;
    using namespace pybind11::literals;

    m.def("project",
          py::overload_cast<double,
                            FunctionTree<D> &,
                            RepresentableFunction<D> &,
                            int,
                            bool>
                            (&mrcpp::project<D>),
          "prec"_a = -1.0,
          "out"_a,
          "inp"_a,
          "max_iter"_a = -1,
          "abs_prec"_a = false);

    m.def("project", [] (double prec,
                         FunctionTree<D> &out,
                         std::function<double(const Coord<D> &r)> inp,
                         int max_iter,
                         bool abs_prec) {
              auto old_threads = mrcpp_get_num_threads();
              mrcpp::set_max_threads(1);
              mrcpp::project<D>(prec, out, inp, max_iter, abs_prec);
              mrcpp::set_max_threads(old_threads);
          },
          "prec"_a = -1.0,
          "out"_a,
          "inp"_a,
          "max_iter"_a = -1,
          "abs_prec"_a = false);
}
} // namespace vampyr

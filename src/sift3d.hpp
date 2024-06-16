#ifndef SIFT3D_HPP
#define SIFT3D_HPP

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "lib_utils.hpp"

#ifdef __cplusplus
extern "C" {
#endif

// Function declaration
PyObject *print_array(PyObject *self, PyObject *args);

#ifdef __cplusplus
}
#endif

#endif // SIFT3D_HPP

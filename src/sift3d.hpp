#ifndef SIFT3D_HPP
#define SIFT3D_HPP

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

#define PY_SSIZE_T_CLEAN
#include <Python.h>

// #include "lib_utils.hpp"

#ifdef __cplusplus
extern "C" {
#endif

// Function declaration
static PyObject
*get_dimensions(PyObject *self, PyObject *args)
{
    PyObject *py_array = nullptr;
    PyArrayObject *numpy_array = nullptr;

    if (!PyArg_ParseTuple(args, "O", &py_array))
    {
        return nullptr;
    }

    /* Convert the data into a numpy array */
    numpy_array = (PyArrayObject *) PyArray_FROM_OTF(py_array, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);

    /* Get the dimensions of the array */
    npy_intp *dims = PyArray_DIMS(numpy_array);
    /* Get a pointer to the array data */
    double *data = (double *) PyArray_DATA(numpy_array);

    for (int i = 0; i < dims[0]; i++)
    {
        for (int j = 0; j < dims[1]; j++)
            printf("%f ", data[i * dims[1] + j]);
        printf("\n");
    }

    printf("(%d, %d)\n", dims[0], dims[1]);

    Py_RETURN_NONE;
}

#ifdef __cplusplus
}
#endif

#endif // SIFT3D_HPP

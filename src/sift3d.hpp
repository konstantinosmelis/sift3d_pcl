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
PyObject *
build_list(double *array, npy_intp *dimensions)
{
    PyObject *py_array = PyList_New(dimensions[0]);
    for (int i = 0; i < dimensions[0]; i++)
    {
        PyObject *value = Py_BuildValue("[iii]",
                                        data[i * 3 + 0],
                                        data[i * 3 + 1],
                                        data[i * 3 + 2]);
        PyList_SetItem(py_array, i, value);
    }
    return py_array;
}

static PyObject *
get_dimensions(PyObject *self, PyObject *args)
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

static PyObject *
sift_keypoints(PyObject *self, PyObject *args)
{
    PyObject *py_array_vertices = nullptr;
    PyObject *py_array_normals = nullptr;
    PyArrayObject *numpy_array_vertices = nullptr;
    PyArrayObject *numpy_array_normals = nullptr;

    if (!PyArg_ParseTuple(args, "OO", &py_array_vertices,
                                      &py_array_normals))
    {
        return nullptr;
    }

    /* Convert the data into a numpy array */
    numpy_array_vertices = (PyArrayObject *)
                            PyArray_FROM_OTF(py_array_vertices,
                                             NPY_DOUBLE,
                                             NPY_ARRAY_IN_ARRAY);

    numpy_array_normals = (PyArrayObject *)
                            PyArray_FROM_OTF(py_array_normals,
                                             NPY_DOUBLE,
                                             NPY_ARRAY_IN_ARRAY);

    /* Get the dimensions of the array */
    npy_intp *dims_vertices = PyArray_DIMS(numpy_array_vertices);
    npy_intp *dims_normals = PyArray_DIMS(numpy_array_normals);
    static_assert (dims_vertices[0] == dims_normals[0],
                   "The number of vertices and normals \
                    should be the same");
    
    /* Get a pointer to the array data */
    auto *data_vertices = (double *) PyArray_DATA(numpy_array_vertices);
    auto *data_normals = (double *) PyArray_DATA(numpy_array_normals);

    Py_RETURN_NONE;
}

#ifdef __cplusplus
}
#endif

#endif // SIFT3D_HPP

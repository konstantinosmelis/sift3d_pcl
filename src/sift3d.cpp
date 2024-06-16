#include "sift3d.hpp"

PyObject
*print_array(PyObject *self, PyObject *args)
{
    PyObject *py_array = nullptr;
    PyArrayObject *numpy_array = nullptr;

    if (!PyArg_ParseTuple(args, "O", &py_array))
    {
        return nullptr;
    }

    import_array(); /* Initialize NumPy C API first */
    /* Convert the data into a numpy array */
    numpy_array = (PyArrayObject *) PyArray_FROM_OT(py_array, NPY_DOUBLE);

    /* Get the dimensions of the array */
    npy_intp *dims = PyArray_DIMS(numpy_array);
    /* Get a pointer to the array data */
    double *data = (double *) PyArray_DATA(numpy_array);
    
    /* Cleanup */
    Py_DECREF(py_array);
    Py_DECREF(numpy_array);

    Py_RETURN_NONE;
}

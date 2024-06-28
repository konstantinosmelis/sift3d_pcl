#include "sift3d.hpp"

static PyMethodDef sift3d_methods[] = {
    {"get_dims", get_dimensions, METH_VARARGS, "Print the array"},
    {nullptr, nullptr, 0, nullptr}     /* Sentinel */
};

static struct PyModuleDef sift3d_module = {
    PyModuleDef_HEAD_INIT,
    "sift3d",                          /* name of module */
    "Simple module implementing the
    sift keypoints detection by PCL",  /* module documentation */
    -1,                                /* size of per-interpreter state of the
                                       module, or -1 if the module keeps state
                                       in global variables. */
    sift3d_methods                     /* methods */
};

PyMODINIT_FUNC
PyInit_sift3d(void)
{
    PyObject *m;
    m = PyModule_Create(&sift3d_module);
    assert (!PyErr_Occurred());
    import_array(); /* Initialize NumPy C API first */
    if (PyErr_Occurred())
        return nullptr;
    assert (PyArray_API);
    return m;
}

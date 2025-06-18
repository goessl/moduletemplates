#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* foo(PyObject* self, PyObject* args) {
    PyObject* a;
    PyObject* b;
    if(!PyArg_UnpackTuple(args, "foo", 2, 2, &a, &b)) {
        return NULL;
    }
    return PyNumber_Add(a, b);
}

static PyMethodDef Methods[] = {
    {"foo", foo, METH_VARARGS, "foo C implementation."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "_noo",
    "C extension providing foo",
    -1,
    Methods
};

PyMODINIT_FUNC PyInit__noo(void) {
    return PyModule_Create(&module);
}

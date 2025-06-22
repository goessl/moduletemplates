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

static PyMethodDef methods[] = {
    {"foo", foo, METH_VARARGS, "foo C implementation."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "_noo",
    .m_doc = "C extension providing foo",
    .m_size = -1,
    .m_methods = methods
};

PyMODINIT_FUNC PyInit__noo(void) {
    return PyModule_Create(&module);
}

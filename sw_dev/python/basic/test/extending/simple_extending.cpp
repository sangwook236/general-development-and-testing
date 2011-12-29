#include <Python.h>


/*
in python interperter:
	import simple_extending
	status = simple_extending.system("ls -l")
*/

static PyObject * extending_system(PyObject *self, PyObject *args)
{
	const char *command = NULL;
	if (!PyArg_ParseTuple(args, "s", &command))
		return NULL;

	const int retval = system(command);

	return Py_BuildValue("i", retval);
}

// method setting
static PyMethodDef simple_extending_methods[] = {
	{ "system", extending_system, METH_VARARGS, "system() doc string" },
	{ NULL, NULL }
};

// module setting
static struct PyModuleDef simple_extending_module = {
	PyModuleDef_HEAD_INIT,
	"simple_extending",
	"simple_extending module doc string",
	-1,
	simple_extending_methods,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC PyInit_simple_extending(void)  // this name has to agree with the module name in setup.py
{
	return PyModule_Create(&simple_extending_module);
}

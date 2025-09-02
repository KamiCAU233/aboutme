#include <Python.h>
#include <iostream>

int main() {
    // 初始化 Python 解释器
    Py_Initialize();

    // 定义 Python 代码字符串
    const char* pythonCode = R"(
def f(a, b):
    return a + b
)";

    // 执行 Python 代码
    PyRun_SimpleString(pythonCode);

    // 获取主模块和全局命名空间
    PyObject* pName = PyUnicode_DecodeFSDefault("__main__");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        // 获取函数对象
        PyObject* pFunc = PyObject_GetAttrString(pModule, "f");

        if (pFunc && PyCallable_Check(pFunc)) {
            // 准备参数
            PyObject* pArgs = PyTuple_New(2);
            PyObject* pValue1 = PyLong_FromLong(3);
            PyObject* pValue2 = PyLong_FromLong(5);
            PyTuple_SetItem(pArgs, 0, pValue1);
            PyTuple_SetItem(pArgs, 1, pValue2);

            // 调用函数
            PyObject* pResult = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pResult != NULL) {
                // 处理返回结果
                long result = PyLong_AsLong(pResult);
                std::cout << "The result of f(3, 5) is: " << result << std::endl;
                Py_DECREF(pResult);
            } else {
                PyErr_Print();
            }
            Py_DECREF(pFunc);
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
            std::cerr << "Cannot find function 'f'" << std::endl;
        }
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        std::cerr << "Failed to load '__main__'" << std::endl;
    }

    // 关闭 Python 解释器
    Py_Finalize();

    return 0;
}

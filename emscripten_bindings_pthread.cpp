#include <emscripten/bind.h>
#include <pthread.h>

using namespace emscripten;

struct Interface {
    virtual ~Interface() = default;
    virtual void invoke(std::string str) = 0;
};

struct InterfaceWrapper : public wrapper<Interface> {
    EMSCRIPTEN_WRAPPER(InterfaceWrapper);
    void invoke(std::string str) {
        return call<void>("invoke", str);
    }
};

void* callInvoke(void* arg) {
    InterfaceWrapper* interface_wrapper = (InterfaceWrapper*) arg;
    interface_wrapper->invoke("test");
    return 0;
}

void callInvokeInWorkerThread(InterfaceWrapper& interface_wrapper) {
    pthread_t worker_thread;
    pthread_create(&worker_thread, nullptr, callInvoke, &interface_wrapper);
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("callInvokeInWorkerThread", &callInvokeInWorkerThread);

    class_<Interface>("Interface")
        .function("invoke", &Interface::invoke, pure_virtual())
        .allow_subclass<InterfaceWrapper>("InterfaceWrapper");
}
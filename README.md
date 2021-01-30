Sample for reproducing the issue which occurs when using Emscripten bindings in pthread.</br></br>
Compiling instruction:</br>
```
$ mkdir build
$ emcc --bind -o build/emscripten_bindings_pthread.js -s USE_PTHREADS=1 -s PROXY_TO_PTHREAD=1 emscripten_bindings_pthread.cpp
```

Expected behavior:</br>
`invoke() called with "test" argument` log message displaying in browser console.</br>

Actual behavior:</br>
Error is thrown.</br>
`Uncaught TypeError: Cannot read property 'value' of undefined
    at requireHandle (http://localhost:8000/build/emscripten_bindings_pthread.js:2378:41)
    at __emval_call_void_method (http://localhost:8000/build/emscripten_bindings_pthread.js:3945:16)
    at <anonymous>:wasm-function[138]:0x2681
    at <anonymous>:wasm-function[137]:0x2603
    at <anonymous>:wasm-function[133]:0x2554
    at <anonymous>:wasm-function[132]:0x24fe
    at <anonymous>:wasm-function[47]:0xec1
    at Object.dynCall (http://localhost:8000/build/emscripten_bindings_pthread.js:1790:33)
    at onmessage (http://localhost:8000/build/emscripten_bindings_pthread.worker.js:130:39)`

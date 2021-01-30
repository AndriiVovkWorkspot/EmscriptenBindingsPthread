Sample for reproducing the issue which occurs when using Emscripten bindings in pthread.</br></br>
Compiling instruction:</br>
```
$ mkdir build
$ emcc --bind -o build/emscripten_bindings_pthread.js -s USE_PTHREADS=1 -s PROXY_TO_PTHREAD=1 emscripten_bindings_pthread.cpp

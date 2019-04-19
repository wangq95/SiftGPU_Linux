# SiftGPU -- Compile and Use

## Requirements

The SiftGPU is compiled on Linux OS, which requires these environments and tools:

- Ubuntu 16.04 LTS
- cmake 3.5 or cmake 2.8
- OpenCV2.4.13
- Glew 1.13.0
- OpenGL
- DevilImage
- Others

## Compile

### Install OpenGL
```bash
sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
```

### Download SiftGPU

```bash
git clone https://github.com/pitzer/SiftGPU.git
cd SiftGPU
```
Or you can download the project on [author's page](http://www.cs.unc.edu/~ccwu/siftgpu/). But this link sames to be lost.

### Download and install Glew

Download Glew from [here](http://glew.sourceforge.net/).
Please choose the version of 1.13.0, whatever ``.zip`` or ``.tgz`` file format, extract it and ``cd`` into that path, then

```bash
sudo make
sudo make install
```
This will produce a  ``lib`` file named ``libGLEW.so.1.13`` in the directory ``bin``, and then
```bash
sudo cp bin/libGLEW.so.1.13 /usr/lib64/
sudo ldconfig /usr/lib64/
```

### Compile SiftGPU

You can compile SiftGPU in two ways: Without CUDA acceleration i.e. CPU-Only and using CUDA, i.e. using GPU.

- CPU-Only

```
cd SiftGPU
sudo make
```

- Using GPU

```bash
cd SiftGPU
sudo vim Makefile
# 1. modify the siftgpu_enable_cuda=0 to siftgpu_enable_cuda=1 on two positions
# 2. modify the CUDA_INSTALL_PATH to where CUDA is installed, e.g.'/usr/local/cuda-9.0'
# 3. In addition, you can choose to change the siftgpu_cuda_options in your specific setting
# Finally, save and exit.
make
```

There should be a ``Lib`` file named ``libsiftgpu.so`` in directory ``bin``, you can easily check this ``Lib`` file whether it is correct.
```bash
ldd bin/libsiftgpu.so
```
which should output the linking information just like these:
```bash
linux-vdso.so.1 =>  (0x00007ffe2c182000)
    libGLEW.so.1.10 => /usr/lib/x86_64-linux-gnu/libGLEW.so.1.10 (0x00007ff2c899f000)
    libglut.so.3 => /usr/lib/x86_64-linux-gnu/libglut.so.3 (0x00007ff2c8755000)
    libGL.so.1 => /usr/lib/nvidia-384/libGL.so.1 (0x00007ff2c84b1000)
    libIL.so.1 => /usr/lib/x86_64-linux-gnu/libIL.so.1 (0x00007ff2c8196000)
    libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007ff2c7e83000)
    libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007ff2c7b7d000)
    libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007ff2c7966000)
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007ff2c759d000)
    libX11.so.6 => /usr/lib/x86_64-linux-gnu/libX11.so.6 (0x00007ff2c7268000)
    libXi.so.6 => /usr/lib/x86_64-linux-gnu/libXi.so.6 (0x00007ff2c7058000)
    libXxf86vm.so.1 => /usr/lib/x86_64-linux-gnu/libXxf86vm.so.1 (0x00007ff2c6e52000)
    libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007ff2c6c4e000)
    libGLX.so.0 => /usr/lib/nvidia-384/libGLX.so.0 (0x00007ff2c6a1e000)
    libGLdispatch.so.0 => /usr/lib/nvidia-384/libGLdispatch.so.0 (0x00007ff2c6750000)
    libtiff.so.5 => /usr/lib/x86_64-linux-gnu/libtiff.so.5 (0x00007ff2c64dd000)
    libpng12.so.0 => /usr/lib/x86_64-linux-gnu/libpng12.so.0 (0x00007ff2c62b7000)
    libmng.so.2 => /usr/lib/x86_64-linux-gnu/libmng.so.2 (0x00007ff2c603b000)
    liblcms.so.1 => /usr/lib/x86_64-linux-gnu/liblcms.so.1 (0x00007ff2c5e04000)
    libjpeg.so.8 => /usr/lib/x86_64-linux-gnu/libjpeg.so.8 (0x00007ff2c5baf000)
    /lib64/ld-linux-x86-64.so.2 (0x00007ff2c8e88000)
    libxcb.so.1 => /usr/lib/x86_64-linux-gnu/libxcb.so.1 (0x00007ff2c5990000)
    libXext.so.6 => /usr/lib/x86_64-linux-gnu/libXext.so.6 (0x00007ff2c577e000)
    liblzma.so.5 => /lib/x86_64-linux-gnu/liblzma.so.5 (0x00007ff2c555c000)
    libjbig.so.0 => /usr/lib/x86_64-linux-gnu/libjbig.so.0 (0x00007ff2c534e000)
    libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007ff2c5135000)
    liblcms2.so.2 => /usr/lib/x86_64-linux-gnu/liblcms2.so.2 (0x00007ff2c4ee0000)
    libXau.so.6 => /usr/lib/x86_64-linux-gnu/libXau.so.6 (0x00007ff2c4cdc000)
    libXdmcp.so.6 => /usr/lib/x86_64-linux-gnu/libXdmcp.so.6 (0x00007ff2c4ad6000)
```
Congratulations, the compile process has done!


## Usage

We provide an example using compiled SiftGPU, which you can find it at ``test_siftgpu``.

If you want to compile this example by yourself, you should

```bash
cd test_siftgpu
rm -rf build
cp ./FindGlew.cmake CMAKE_PATH
mkdir build && cd build
# Please change the path of the image for test in main.cpp
# save and exit
# Then, change:
#     include_directories("/home/mac-ar/SiftGPU/src/SiftGPU/" ${OpenGL_INCLUDE_DIR} ${CUDA_INCLUDE_DIR})
#     set(SIFTGPU_LIBS "/home/mac-ar/SiftGPU/bin/libsiftgpu.so")
# in test_siftgpu/CMakeLists.txt to satisfy your system setting.
# save and exit
cmake ..
make
```
``CMAKE_PATH`` is the path where ``cmake`` is installed. Usually like ``/usr/share/cmake-xx/Modules/``, or ``/usr/local/share/cmake-xx/Modules/``, please find the correct path of ``cmake`` in your own OS. This script guide the ``cmake`` to find ``GLEW``.
Just ignore the ``warnings`` or ``note`` information, no errors means successful compilation. An executable file, named ``testSIFTGPU``, is created in ``build``, just run this program to test the performance

```bash
./testSIFTGPU
```
Then the results will be output, you can change the ``main.cpp`` for your specific purpose, which could be better than mine.


## Solutions

- When you compile, you may face an error like:
```bash
CMake Error: The following variables are used in this project, but they are set to NOTFOUND.
Please set them or make sure they are set and tested correctly in the CMake files:
GLUT_Xmu_LIBRARY (ADVANCED)
    linked by target "openglsupport" in directory {$PATH}
```
You can solve this problem by:
```bash
sudo apt-get install libxmu-dev
```

- Running ``./testSIFTGPU``, you may face this:
```bash
freeglut ERROR: Function <glutDestroyWindow> called without first calling 'glutInit'.
```
You should open ``src/SiftGPU/LiteWindow.h`` and find ``virtual ~LiteWindow()   {  if(glut_id > 0) glutDestroyWindow(glut_id);  }``, modify it as below:
```bash
virtual ~LiteWindow()   
{  
    if(glut_id > 0) 
    {
    　　int argc = 0;
    　　char** argv;
    　　glutInit(&argc, argv); 
    　　glutDestroyWindow(glut_id); 
    } 
}
```

- Another error:
```bash
error: declaration of ‘operator new’ as non-function SIFTGPU_EXPORT void* operator new (size_t size);
```
Please open ``src/SiftGPU/SiftGPU.h``, add a head file ``#include <stddef.h>`` at the beginning of it.
Last but not least, you should make sure that your ``OpenGL`` has been installed and ``DO NOT`` run this program using Proxy terminal software without ``OpenGL`` support. Just run it using your PC or laptop.

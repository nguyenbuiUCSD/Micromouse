# Micromouse
IEEE Micromouse
This code is build based on Eclipse IDE with gcc-arm tool chain.
You can easily install this Eclipse - modified version recommned from ST here:
http://www.st.com/en/development-tools/sw4stm32.html

OR:
Use make file and gcc-arm tool chain. 
Navigate to Debug/Release folder. Type:
  make all
To complie. You need to install gcc-arm before using make file.

To flash to the chip, you can use ST-LINK Utility find here:
http://www.st.com/en/embedded-software/stsw-link004.html

or set up make flash. Google make flash for STM32F4

If you have System work bench (highly recommended), then flash and debug are much easier.

All issues and bugs are report through github.

If you want to make contribution to the project. Make a pull request, assign yourself an issues.
Finish and make a merge request.

Files structure:

/inc: all header files (*.h)
/src: source file (*.c)
Other folder are libraries and start up code. Do not modified. All configuration can be done at higher layer.

Layer:

Main -> Runner -> Driver -> Controller -> Standard Peripheral library -> Hardware IO
|         |         |           |-------> Utilize SPL to implement an median layer between user code and hardware
|         |         |-------------------> Drive the mouse with left turn, right turn, ... used all fcns from Controller lyer
|         |-----------------------------> Maze solving algorithm, include search and solve the maze.
|---------------------------------------> User interface.

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

2016 IEEE UCSD California Micromouse (CAMM):

https://www.youtube.com/watch?v=ZlR1eT7DGK4


![13217428_1119412684748493_9006213683976071644_o](https://user-images.githubusercontent.com/17399214/52556336-1a8ddc80-2da1-11e9-9239-3a01d868f351.jpg)
![13254728_1119412674748494_8515416766969404322_o](https://user-images.githubusercontent.com/17399214/52556339-1b267300-2da1-11e9-924a-cdbe3c65e2e5.jpg)


![13247932_1119412634748498_1958810507137196921_o](https://user-images.githubusercontent.com/17399214/52556333-1a8ddc80-2da1-11e9-9968-96d6779f3ae4.jpg)
![13244185_1119412681415160_3168289892820804519_o](https://user-images.githubusercontent.com/17399214/52556332-1a8ddc80-2da1-11e9-94e3-c79955422922.jpg)


![13235345_1119412661415162_97589979850380628_o](https://user-images.githubusercontent.com/17399214/52556331-1a8ddc80-2da1-11e9-9abc-82f7e3ea8e94.jpg)
![13254925_1119412618081833_4175102874641885381_o](https://user-images.githubusercontent.com/17399214/52556337-1b267300-2da1-11e9-89da-4857ce465a84.jpg)


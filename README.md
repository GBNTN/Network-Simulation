# Network-Simulation
project

## Description:
this program allows the user to launch simulations of a network of random nodes with the help of :
* an std::vector<double> of values for the nodes 
* an std::multimap<size_t,size_t> of links, containing the index of the nodes in values, in order to create the network.

## How to use it ?
I used Cmake, so the user need to follow the step :
1. open terminal
2. go in the directory where the program is
3. tap the command : **_cmake._**
4. then : **_make_**

At this step the user will have two executor file :
* Networksimulation
* testNetSim
 
 5. the user can launch the execution by taping the comand : **./**<file to execute>

Another solution (_cleaner way_) :
1. create the folders : **build** and **src**
2. put the files in src 
3. go to build
4. tap the command : **_cmake .._**
5. then : **_make_**

## Documentation and Test :
I used **gtest** to create test in order to test the good executions of the methods of network.h
In order to have a good description of what do each methods, **Doxygen** was used.

to create the file **Doxyfile**, you can (if you used  the 1st method above) :
1. open terminal
2. go in the directory where the program is
3. tap the command : **_cmake._**
4. then : **_make doc_**
5. finally tap : **_doxygen -g_**





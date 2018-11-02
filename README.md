# Network-Simulation
project

## Description: 
This program allows the user to launch simulations of a network of random nodes with the help of :
* an std::vector<double> of values for the nodes; 
* an std::multimap<size_t,size_t> of links, containing the index of the nodes in values, in order to create the network.

## How to use it ?
I used Cmake, so the user need to follow the step :
1. open terminal
2. go in the directory where the program is
3. tap the command : **_cmake ._**
4. then : **_make_**

At this step the user will have two executor file :
* Networksimulation
* testNetSim
 
 5. the user can launch the execution by taping the comand : **./** file_to_execute

Another solution (_cleaner way_) :
1. create the folders : **build** and **src**
2. put the files in src 
3. go to build
4. tap the command : **_cmake .._**
5. then : **_make_**

## Built with :
* [Tclap library](http://tclap.sourceforge.net) - indroduce parameters
* [Doxygen](http://www.stack.nl/~dimitri/doxygen/manual/starting.html) - documentation of the _.h_
* [Gtest](https://github.com/google/googletest) - test the methods (especially of _network.h_)

## Documentation :
To create the file **Doxyfile**, you can (if you used  the 1st method above) :
1. open terminal
2. go in the directory where the program is
3. tap the command : **_cmake ._**
4. then : **_make doc_**
5. finally tap : **_doxygen -g_**





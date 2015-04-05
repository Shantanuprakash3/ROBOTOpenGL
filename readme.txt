The following list has been implemented:
1. Eyes, mouth, nose using cube GLUT primitives. 
2. The robot is in a 3D environment consisting of a floor where the robot can walk.
3. gluLookAt() is used to set up a perspective projection. 
4. The robot walks forwards and backwards. 
It loops back to the centre when it comes too close to either edge (using modular arithmetic).
5. As the user presses ‘w’, the robot toggles between filled and wireframe mode.
6. reShaping the window does not distort anything.

The program has been tested and runs well on Visual Studio 2013 on Windows 7 64-bit. 

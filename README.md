##  Particle System

A minimal particle system acting as a foundation a small graphical interface.

#### Folder structure

- /include: Header files
- /src: Cpp files
- /unittest: test to see that the particle system is working as intended

#### Setup instructions
Dependencies:
 - [CMake](https://cmake.org/download/) For cross-platform compiler project generation.
 - [Vcpkg](https://github.com/microsoft/vcpkg) For dependency management
 - C++20 Required, e.g. [Visual Studio](https://visualstudio.microsoft.com/downloads/)


1)  Make a project folder 

2)  In the project folder:
    * git clone https://github.com/microsoft/vcpkg 
    * git clone https://github.com/Mdeeq08/Particlesystem.git

2)  Open CMake (we recommend using the GUI here), enter the source path to the particlesystem git repo
    and select one of the "presets" ("MSVC 2022", "Xcode", "Ninja", "Unix Makefiles")
    and hit configure. This will build and the dependencies using vcpkg and make them available to 
    the project. Then the will be configured 

3)  Hit Generate and then Open Project to open the project in your IDE.

4)  Build and run the 'application' executable "main".


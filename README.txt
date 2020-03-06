A project consists of two parts: ServiceManagerCOMObject and ServiceManagerCOMClient.
The first one is a COM object implementing Windows Service management functionality.
The second one is a UI client application which uses COM object from above. 
UI app is written in C++ using Qt framework distributed under GPLv3 licence.
You can find a text of the license in provided LICENSE.txt file.
You can find .DLL file containing COM object and .EXE UI app in root folder of the repository.
For using COM Object don't forget to register .DLL file (using RegSvr32 command, for example).
Both projects uses CMake building system and can be build in VS 2019.
UI application has a dependency to the COM Object project and also require installed Qt framework to be build.
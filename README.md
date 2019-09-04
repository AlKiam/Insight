# Insight Engine, free and OpenSource Game Framework. Using OpenGL
### 3D cross-platform game framework
Insight is a **C and C++**, multiplatform game framework to create 2D games. It provides a varaity of new classes to handle different aspects like **window, input, shaders, GUI, physics...**

Unfortunately we have not managed to port the engine to Android or HTML, nor translate it into any other language, we will try this in later versions.

### Free and open source
Insight is completely free and open source under GNU General Public License. No strings attached, no royalties, nothing. The users' games are theirs, down to the last line of engine code. We don't want to make profit from this project.

### Example code
```c
#include "Window.h"

int main(void) {
   
   Window* window = mk_Window(1280, 720, "OpenGL", false);
   
   while (WindowIsRunning(window)) {

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

    }
    
    return 0;
}
```
### Output
<img width="854" height="480" src="https://raw.githubusercontent.com/AlKiam/Insight2D/master/images/examplewindow.png" alt="window output"/>

## Dependencies
  * **GLFW** https://www.glfw.org/
  * **OpenGL** https://glad.dav1d.de/ or http://glew.sourceforge.net/
  * **stb_image** https://github.com/nothings/stb/blob/master/stb_image.h
  * **cglm** https://github.com/recp/cglm
  
## Compilation (With GCC)
**If you are using GLAD**
```cmd
gcc main.c glad.c -I"includes" -L"linkers" -glfw -opengl32
```
**If you are using GLEW**
```
gcc main.c -I"includes" -L"linkers" -glfw -opengl32 -glew32
```

##### Examples
<img width="854" height="480" src="https://raw.githubusercontent.com/AlKiam/Insight2D/master/images/example%20game.png" alt="window output"/>



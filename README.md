# gmath
Header-only math library for linear (and non-linear) transformations made to work with OpenGL.

## Features
* Matrix class
* Vector class
* Transformations
  * Translation
  * Rotation
  * Scale
* Projections
  * Orthographic
  * Perspective

## Notes
* in memory matrices are laid out in row-major order, therefore `transpose` prarmerer in `glUniformMat**` shuld be set to `GL_TRUE` when sending matrix to a shader
* order of matrix multiplication is reversed (just like in glm)

## Example usage
```c++
#include <gmath>

gm::mat4 model = gm::rotate(gm::mat(1.f), gm::vec3(0.f, 0.f, 1.f), gm::randians(90.f));
gm::mat4 view = gm::lookAt(gm::vec3(-1.f, 0.f, 0.f), gm::vec3(0.f, 0.f, 0.f), gm::vec3(0.f, 1.f, 0.f));
gm::mat4 projection = gm::perspective(gm::radians(60.f), 4.f/3.f, 0.1f, 100.f);

gm::mat4 MVP = projection * view * model;
```

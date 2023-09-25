#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include "../lib/glfw3.h"

#ifdef __cplusplus
extern "C" {
#endif


GLFWwindow *sgl_window_create(uint32_t width, uint32_t height, const char *winname);

#ifdef __cplusplus
}
#endif

#endif // !WINDOW_H

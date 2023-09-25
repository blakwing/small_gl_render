#include "../include/window.h"
#include "../include/glad.h"
#include <stdio.h>

/*
 * Frame buffer resize callback.
 * */
void fb_resize_callback(GLFWwindow *pWindow, int width, int height)
{
        glViewport(0, 0, width, height);
}

/*
 * Initialize "small gl render" by creating window and loading OpenGL
 * and other necesary things.
 * */
GLFWwindow *sgl_window_create(uint32_t width, uint32_t height, const char *winname)
{
        GLFWwindow *pWindow;
        glfwInit();

        // create window and check everything is in working order
        {
                pWindow = glfwCreateWindow(width, height, winname, NULL, NULL);

                if (pWindow == NULL) {
                        printf("pWindow == NULL\n");
                        glfwTerminate();
                        return NULL;
                }

                glfwMakeContextCurrent(pWindow);

                if (!gladLoadGLLoader ( (GLADloadproc)glfwGetProcAddress ) ) {
                        printf("glad load failed\n");
                        glfwTerminate();
                        return NULL;
                }

        }

        glViewport(0, 0, width, height);
        glfwSetFramebufferSizeCallback(pWindow, fb_resize_callback);

        return pWindow;
}


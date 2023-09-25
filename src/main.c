#include "../include/glad.h"
#include "../lib/stb_image.h"
#include "../lib/ncug/ncug.h"
#include "../include/window.h"
#include "../include/shader.h"
#include "../include/square.h"

int main()
{
        uint32_t shader_program;
        GLFWwindow *pWindow = sgl_window_create(500, 500, "hi");

        {
                uint32_t shader_vert = sgl_shader_create("./assets/vertx.glsl", GL_VERTEX_SHADER);
                uint32_t shader_frag = sgl_shader_create("./assets/frag.glsl", GL_FRAGMENT_SHADER);

                shader_program = sgl_shader_program_create((uint32_t []){shader_vert, shader_frag}, 2);

                sgl_shader_delete((uint32_t []){shader_vert, shader_frag}, 2);
        }

        struct VAO square = sgl_square_create();

        double current_time;

        int32_t color = glGetUniformLocation(shader_program, "color");

        while (!glfwWindowShouldClose(pWindow) && !key_held(pWindow, GLFW_KEY_ESCAPE)) 
        {
                current_time = glfwGetTime();
                double delta_time = get_delta_time(current_time);

                glfwPollEvents();
                glClear(GL_COLOR_BUFFER_BIT);

                glUseProgram(shader_program);
                glUniform4f(color, 1.0f, 1.0f, 0.0f, 1.0f);

                glBindVertexArray(square.VAO);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

                glfwSwapBuffers(pWindow);
        }

        glfwTerminate();
        return 0;
}

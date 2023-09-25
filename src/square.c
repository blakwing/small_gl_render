#include "../include/square.h"
#include "../include/glad.h"

struct VAO sgl_square_create()
{
        struct VAO vert;

        glGenVertexArrays(1, &vert.VAO);
        glBindVertexArray(vert.VAO);
        
        glGenBuffers(1, &vert.VBO);
        glGenBuffers(1, &vert.EBO);
        
        {
                float vertices[] = {
                        0.5f,  0.5f, 0.0f,
                        0.5f, -0.5f, 0.0f,
                        -0.5f, -0.5f, 0.0f,
                        -0.5f,  0.5f, 0.0f
                };

                uint32_t indices[] = {
                        0, 1, 3,
                        1, 2, 3
                };
                
                glBindBuffer(GL_ARRAY_BUFFER, vert.VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vert.EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
                
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
                glEnableVertexAttribArray(0);
        }

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        return vert;
}

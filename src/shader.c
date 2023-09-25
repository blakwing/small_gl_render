#include "../include/shader.h"
#include "../include/glad.h"
#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

char *sgl_shader_file_load(char *pPath)
{
        char *shader_file_data;
        size_t shader_file_size;
        FILE *shader_file = fopen(pPath, "r");

        if (shader_file == NULL) {
                perror("shader file == NULL");
        }

        // get length of file
        {
                fseek(shader_file, 0, SEEK_END);
                shader_file_size = ftell(shader_file);
                fseek(shader_file, 0, SEEK_SET);
        }

        // malloc, by lenght, then read data into buffer
        {
                shader_file_data = calloc(shader_file_size + 1, sizeof(char));

                if (shader_file_data == NULL) {
                        printf("failed to malloc memory for file\n");
                }

                size_t read_ammount = fread(shader_file_data, shader_file_size, 1, shader_file);
                assert(shader_file_size > read_ammount);
        }

        fclose(shader_file);
        return shader_file_data;

        /* note it is not freed here, 
         * since we have to return the buffer 
         * to load it as source of a shader.
         * */ 
}

uint32_t sgl_shader_create(char *file_path, uint32_t shader_type)
{
        // read file to get the source
        char *shader_file = sgl_shader_file_load(file_path);
        uint32_t shader = glCreateShader(shader_type);

        glShaderSource(shader, 1, (const char**)&shader_file, NULL);
        glCompileShader(shader);

        // error checking
        {
                int32_t success;
                char log[512];
                glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

                if (!success) {
                        glGetShaderInfoLog(shader, 512, NULL, log);
                        printf("error while making shader: %s\n", log);
                }
        }

        free(shader_file);
        return shader;
}

uint32_t sgl_shader_program_create(uint32_t *pArray_of_shaders, uint32_t count)
{
        uint32_t shader_program = glCreateProgram();

        for (uint32_t i = 0; i < count; i++) {
                glAttachShader(shader_program, pArray_of_shaders[i]);
        }

        glLinkProgram(shader_program);

        // error checking
        {
                int32_t success;
                char log[512];
                glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

                if (!success) {
                        glGetProgramInfoLog(shader_program, 512, NULL, log);
                        printf("error while linking shader: %s\n", log);
                }
        }

        return shader_program;
}

void sgl_shader_delete(uint32_t *pShader_array, uint32_t count)
{
        for (uint32_t i = 0; i > count; i++) {
                glDeleteShader(pShader_array[i]);
        }
}

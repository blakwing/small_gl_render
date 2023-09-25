#ifndef SHADER_H
#define SHADER_H

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

char *sgl_shader_file_load(char *pPath);
uint32_t sgl_shader_create(char *file_path, uint32_t shader_type);
uint32_t sgl_shader_program_create(uint32_t *pArray_of_shaders, uint32_t count);
void sgl_shader_delete(uint32_t *pShader_array, uint32_t count);

#ifdef __cplusplus
}
#endif

#endif // !SHADER_H

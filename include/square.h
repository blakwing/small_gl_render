#ifndef SQUARE_H
#define SQUARE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct VAO {
        uint32_t VAO, EBO, VBO;
};

struct VAO sgl_square_create();

#ifdef __cplusplus
}
#endif

#endif // !SQUARE_H

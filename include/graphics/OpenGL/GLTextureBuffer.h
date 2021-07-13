#pragma once

#include <GL/glew.h>

#include "graphics/IVertexBufferObject.h"

namespace GE
{

    class GLTextureBuffer final : IVertexBufferObject
    {
        public:
            GLTextureBuffer() = default;
            GLTextureBuffer(float* data, const unsigned count);
            ~GLTextureBuffer();

        private:
            GLuint m_vboId;
    };

}
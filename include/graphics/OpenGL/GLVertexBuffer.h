#pragma once

#include <GL/glew.h>

#include "graphics/IVertexBufferObject.h"

namespace GE
{

    class GLVertexBuffer final : public IVertexBufferObject
    {
        public:
            GLVertexBuffer() = default;
            GLVertexBuffer(float* data, const unsigned count);
            ~GLVertexBuffer();

        private:
            GLuint m_vboId;
    };

}
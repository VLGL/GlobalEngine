#pragma once

#include <GL/glew.h>

#include "graphics/IVertexBufferObject.h"

namespace GE
{

    class GLIndexBuffer final : public IVertexBufferObject
    {
        public:
            GLIndexBuffer() = default;
            GLIndexBuffer(unsigned* data, const unsigned count);
            ~GLIndexBuffer();

            unsigned getCount() const noexcept;

        private:
            GLuint   m_vboId;
            unsigned m_count;
    };

}
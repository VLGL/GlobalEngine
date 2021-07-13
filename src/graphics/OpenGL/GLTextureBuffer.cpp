#include "graphics/OpenGL/GLTextureBuffer.h"

namespace GE
{
    GLTextureBuffer::GLTextureBuffer(float* data, const unsigned count)
    {
		glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    GLTextureBuffer::~GLTextureBuffer()
    {
		glDeleteBuffers(1, &m_vboId);
    }
}
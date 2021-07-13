#include "graphics/OpenGL/GLVertexBuffer.h"

namespace GE
{

    GLVertexBuffer::GLVertexBuffer(float* data, const unsigned count)
    {
      glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
      glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*)0);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    GLVertexBuffer::~GLVertexBuffer()
    {
      glDeleteBuffers(1, &m_vboId);
    }

}
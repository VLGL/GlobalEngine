#include "graphics/OpenGL/GLIndexBuffer.h"

namespace GE
{

    GLIndexBuffer::GLIndexBuffer(unsigned* data, const unsigned count) :
        m_count { count }
    {
        glGenBuffers(1, &m_vboId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned), data, GL_STATIC_DRAW);
    }

    GLIndexBuffer::~GLIndexBuffer()
    {
		glDeleteBuffers(1, &m_vboId);
    }

    unsigned GLIndexBuffer::getCount() const noexcept
    {
        return m_count;
    }
}
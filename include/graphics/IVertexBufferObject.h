#pragma once

#include <boost/core/noncopyable.hpp>

namespace GE
{

    class IVertexBufferObject
    {
        public:
            virtual ~IVertexBufferObject() = default;

        protected:
            IVertexBufferObject() = default;
    };

}
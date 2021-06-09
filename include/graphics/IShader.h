#pragma once

#include <filesystem>

#include "core/Memory.h"

namespace GE
{

	using Path = std::filesystem::path;

	class IShader
	{
		public:
			virtual ~IShader() = default;

			virtual void bind()   const = 0;
			virtual void unbind() const = 0;
	};

	class IShaderFactory
	{
		public:
			virtual ~IShaderFactory() = default;
			virtual Shared<IShader> createShader(Path, Path) { return nullptr; };

		protected:
			// Hack
			IShaderFactory() = default;
	};

} // GE

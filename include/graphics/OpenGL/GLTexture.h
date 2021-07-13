#pragma once

#include <filesystem>

#include <GL/glew.h>

namespace GE
{

	namespace fs = std::filesystem;
	using Path = std::filesystem::path;

	class GLTexture final
	{
		public:
			GLTexture() = delete;
			~GLTexture();
			explicit GLTexture(const Path & texturePath);

			void apply() const;
			void unapply() const;

		private:
			GLuint m_textureId { 0 };
			int m_width        { 0 };
			int m_height       { 0 };

			uint8_t * m_texture = nullptr;
	};

} // GE

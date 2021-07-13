#pragma once

#include "core/Memory.h"
#include "graphics/IDrawable.h"

namespace GE
{

	class GLModel;
	class GLTexture;

	class GLTexturedModel final : public IDrawable
	{
		public:
			GLTexturedModel() = delete;
			GLTexturedModel(Shared<GLModel> model,
			                Shared<GLTexture> texture);

			const Shared<GLModel>   & getModel()   const;
			const Shared<GLTexture> & getTexture() const;

			void draw() const override;

		private:
			Shared<GLModel>   m_model   = nullptr;
			Shared<GLTexture> m_texture = nullptr;
	};

} // GE

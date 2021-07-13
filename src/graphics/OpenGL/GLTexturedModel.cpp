#include "graphics/OpenGL/GLTexturedModel.h"
#include "graphics/OpenGL/GLTexture.h"
#include "graphics/OpenGL/GLModel.h"

namespace GE
{

	GLTexturedModel::GLTexturedModel(Shared<GLModel> model,
	                                 Shared<GLTexture> texture) :
		m_model   { model },
		m_texture { texture }
	{ }

	const Shared<GLModel> & GLTexturedModel::getModel()   const
	{
		return m_model;
	}

	const Shared<GLTexture> & GLTexturedModel::getTexture() const
	{
		return m_texture;
	}

	void GLTexturedModel::draw() const
	{
		m_texture->apply();
		m_model->draw();
		m_texture->unapply();
	}

} // GE

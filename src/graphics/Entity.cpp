#include "graphics/Entity.h"

namespace GE
{

	Entity::Entity(Shared<GLTexturedModel> texturedModel,
	               Shared<IShader> shader) :
		m_texturedModel { texturedModel },
		m_shader        { shader }
	{

	}

	Entity::Entity(Shared<GLTexturedModel> texturedModel,
	               Shared<IShader> shader,
	               const vec3 & position,
	               const vec3 & rotation,
	               const vec3 & scaling) :
		m_texturedModel { texturedModel },
		m_shader        { shader },
		m_position      { position },
		m_rotation      { rotation },
		m_scaling       { scaling }
	{

	}

	Entity::Entity(Entity && other) noexcept
	{
		// Free resources
		m_texturedModel.reset();
		m_shader.reset();

		m_texturedModel = other.m_texturedModel;
		m_shader = other.m_shader;

		// Free resources
		other.m_texturedModel.reset();
		other.m_shader.reset();

		m_position = std::move(other.m_position);
		m_rotation = std::move(other.m_rotation);
		m_scaling  = std::move(other.m_scaling);
	}

	Entity & Entity::operator=(Entity && other) noexcept
	{
		if (&other != this)
		{
			// Free resources
			m_texturedModel.reset();
			m_shader.reset();

			m_texturedModel = other.m_texturedModel;
			m_shader = other.m_shader;

			// Free resources
			other.m_texturedModel.reset();
			other.m_shader.reset();

			m_position = std::move(other.m_position);
			m_rotation = std::move(other.m_rotation);
			m_scaling  = std::move(other.m_scaling);
		}

		return *this;
	}

	void Entity::setShader(Shared<IShader> shader)
	{
		m_shader = shader;
	}

	Shared<GLTexturedModel> Entity::getTexturedModel() const
	{
		return m_texturedModel;
	}

	Shared<IShader> Entity::getShader() const
	{
		return m_shader;
	}

	void Entity::draw() const
	{
		m_shader->bind();
		m_texturedModel->draw();
		m_shader->unbind();
	}

	void Entity::rotate(const vec3 & rotation) noexcept
	{
		m_rotation += rotation;
	}

	void Entity::scale(const vec3 & scale) noexcept
	{
		m_scaling *= scale;
	}

	void Entity::move(const vec3 & move) noexcept
	{
		m_position += move;
	}

	const vec3 & Entity::getPosition() const noexcept
	{
		return m_position;
	}

	const vec3 & Entity::getRotation() const noexcept
	{
		return m_rotation;
	}

	const vec3 & Entity::getScalingFactor() const noexcept
	{
		return m_scaling;
	}

	void Entity::setPosition(const vec3 & position) noexcept
	{
		m_position = position;
	}

	void Entity::setRotation(const vec3 & rotation) noexcept
	{
		m_rotation = rotation;
	}

	void Entity::setScalingFactor(const vec3 & scalingFactor) noexcept
	{
		m_scaling = scalingFactor;
	}

} // GE

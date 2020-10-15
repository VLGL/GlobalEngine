#include <iostream>
#include <gtest/gtest.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

TEST(GLFW, GLFWInit)
{
	ASSERT_EQ(glfwInit(), GLFW_TRUE);
}

TEST(GLEW, GLEWInit)
{
	ASSERT_EQ(glfwInit(), GLFW_TRUE);

	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	GLFWwindow * window = glfwCreateWindow(400,
	                                       400,
	                                       "Test",
	                                       nullptr,
	                                       nullptr);

	ASSERT_NE(window, nullptr);

	glfwMakeContextCurrent(window);

	ASSERT_EQ(glewInit(), GLEW_OK);

	glfwDestroyWindow(window);
}
int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

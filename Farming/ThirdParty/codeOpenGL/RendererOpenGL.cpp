#include "pch.h"
#include "RendererOpenGL.h"
#include "glad/glad.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "FarmingWindow.h"


namespace Farming
{
	RendererOpenGL::RendererOpenGL()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			FARMING_ERROR("ERROR: Failed to initialize GLAD");
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		mDefaultShaders.LoadSourceCode(
			"../Farming/Assets/Shaders/defaultVertex.glsl",
			"../Farming/Assets/Shaders/defaultFragment.glsl" );
	}


	RendererOpenGL::~RendererOpenGL()
	{

	}


	void RendererOpenGL::Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders)
	{
		float vertices[] = {
			// The first two are vertex coordinates, last two are texture coordinates
			xCoord,					 yCoord,				   0.0f, 0.0f, // bottom-left (0)
			xCoord,					 yCoord + pic.GetHeight(), 0.0f, 1.0f, // upper-left (1)
			xCoord + pic.GetWidth(), yCoord + pic.GetHeight(), 1.0f, 1.0f, // upper-right (2)
			xCoord + pic.GetWidth(), yCoord,				   1.0f, 0.0f  // bottom-right (3)
		};

		unsigned int indices[] = {
			0, 1, 2, // first triangle
			0, 2, 3 // second triangle
		};

		unsigned VAO{ 0 };
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned VBO{ 0 };
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0)); // 2 are vertex coordinates, 4 is how many floats, describes the vertex coordinates
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float))); // Describes texture coordinates for the vertex, 2*sizeof ---> offset of 2 (Go to the other 2 coordinates rather than the first 2)
		glEnableVertexAttribArray(1);

		unsigned EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// draw our first triangle
		shaders.Bind();
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		// glDrawArrays(GL_TRIANGLES, 0, 3);
		// glBindVertexArray(0); // no need to unbind it every time 
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void RendererOpenGL::Draw(Image& pic, int xCoord, int yCoord)
	{
		float vertices[] = {
			// The first two are vertex coordinates, last two are texture coordinates
			xCoord,					 yCoord,				   0.0f, 0.0f, // bottom-left (0)
			xCoord,					 yCoord + pic.GetHeight(), 0.0f, 1.0f, // upper-left (1)
			xCoord + pic.GetWidth(), yCoord + pic.GetHeight(), 1.0f, 1.0f, // upper-right (2)
			xCoord + pic.GetWidth(), yCoord,				   1.0f, 0.0f  // bottom-right (3)
		};

		unsigned int indices[] = {
			0, 1, 2, // first triangle
			0, 2, 3 // second triangle
		};

		unsigned VAO{ 0 };
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned VBO{ 0 };
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0)); // 2 are vertex coordinates, 4 is how many floats, describes the vertex coordinates
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float))); // Describes texture coordinates for the vertex, 2*sizeof ---> offset of 2 (Go to the other 2 coordinates rather than the first 2)
		glEnableVertexAttribArray(1);

		unsigned EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// draw our first triangle
		mDefaultShaders.Bind();
		mDefaultShaders.SetUniform2Ints(
			"ScreenSize", 
			FarmingWindow::GetWindow()->GetWidth(), 
			FarmingWindow::GetWindow()->GetHeight());
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		// glDrawArrays(GL_TRIANGLES, 0, 3);
		// glBindVertexArray(0); // no need to unbind it every time 
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void RendererOpenGL::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}

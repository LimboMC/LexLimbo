//-------> OPENGL
#include<glad/glad.h>
#include<GLFW/glfw3.h>
//-------->Lex
#include<lex.h>
#include<lexgl.h>
//________//
#include<stdio.h>
const char* vertexShaderSource = "#version 460 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 460 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";
LexKeyBoard Key;
int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(800, 800, "Hello Limbo", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	LViewport(0, 0, 800, 800);
	GLuint Vertex, Fragment,Program;
	Vertex = LShaderVer();
	Fragment = LShaderFrag();
	LShaderSource(Vertex, 1, &vertexShaderSource);
	LShaderSource(Fragment, 1, &fragmentShaderSource);
	Program = LCreateProgram();
	LAttachShader(Program,Vertex, Fragment);
	LLinkProgram(Program);
	LDeleteShaderDouble(Vertex, Fragment);
	LexColor Color = { 1.0,1.0,1.0,1.0 };
	float vertices[] = {
	0.25f,  0.25f, 0.0f,  // top right
	0.25f, -0.25f, 0.0f,  // bottom right
    -0.25f, -0.25f, 0.0f,  // bottom left
    -0.25f,  0.25f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
	    0, 1, 3,   // first triangle
	    1, 2, 3    // second triangle
	};
	GLuint VBO,VAO,EBO;
	LGenVerArray(1, &VAO);
	LGenVerBuff(1, &VBO);
	LGenVerBuff(1, &EBO);
	LBindVerArrays(VAO);
	LBindVerBuff(LEX_ARRAY_BUFFER,VBO);
	LBufferData(LEX_ARRAY_BUFFER, LEX_STATIC_DRAW,sizeof(vertices), vertices);
	LBindVerBuff(LEX_ELEMENT_ARRAY_BUFFER,EBO);
	LBufferData(LEX_ELEMENT_ARRAY_BUFFER, LEX_STATIC_DRAW,sizeof(indices),indices);
	LVerAttribPointer(0, 3, LEX_FLOAT, LEX_FALSE, 3 * sizeof(float), (void*)0);
	LEnableVerAttribArray(0);
	LUnBind(LEX_UNBIND);
	while (!glfwWindowShouldClose(window)) {
		LColorClear(Color);
		LBindVerArrays(VAO);
		LUseProgram(Program);
		LDrawElement(LEX_TRIANGLES, 6, LEX_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	LDeleteVerArray(1, &VAO);
	LDeleteBuffer(1, &VBO);
	LDeleteBuffer(1, &EBO);
	LDeleteProgram(Program);
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
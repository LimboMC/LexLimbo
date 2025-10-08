#include<lex.h>
#include<lexcore.h>
#include<stdarg.h>
#include<lexgl.h>
#include <stdio.h>
void LColorClear(LexColor color) {
	glClearColor(color.R, color.G, color.B, color.A);
	glClear(GL_COLOR_BUFFER_BIT);
}
//Lex Shader Vertex And Fragment
GLuint LShaderVer(void)
{
	return glCreateShader(GL_VERTEX_SHADER);
}
GLuint LShaderFrag(void) {
	return glCreateShader(GL_FRAGMENT_SHADER);
}
void LShaderSource(GLuint Shader, GLsizei Size, const GLchar* const* ShaderVertex) {
	glShaderSource(Shader, Size, ShaderVertex, NULL);
	glCompileShader(Shader);
}
void LDeleteShader(GLuint Size, GLuint Shader, ...) {
	va_list Shaders;
	va_start(Shaders, Shader);
	for (GLuint i = 0; i < Size; i++) {
		GLuint Sha = va_arg(Shaders, GLuint);
		glDeleteShader(Sha);
	}
	va_end(Shaders);
}
void LIsShader(GLuint Size, GLuint Shader, ...) {
	va_list IsShader;
	va_start(IsShader, Shader);
	for (GLuint i = 0; i < Size; i++) {
		GLuint Sha = va_arg(IsShader, GLuint);
		glIsShader(Sha);
	}
	va_end(IsShader);
}
//Program Shader
GLuint LCreateProgram(void) {
	return glCreateProgram();
}
void LAttachShader(GLuint Program, GLuint Vertex, GLuint Fragment) {
	glAttachShader(Program, Vertex);
	glAttachShader(Program, Fragment);
}
void LLinkProgram(GLuint Program) {
	glLinkProgram(Program);
}
void LUseProgram(GLuint Program) {
	glUseProgram(Program);
}
void LDeleteProgram(GLuint Program) {
	glDeleteProgram(Program);
}
//Verex Array and Veretx Buffers And Element Buffers
void LGenVerBuff(GLsizei Size, GLuint* Buffer) {
	*Buffer = 0;
	glGenBuffers(Size, Buffer);
}
void LGenVerArray(GLsizei Size, GLuint* Array) {
	*Array = 0;
	glGenVertexArrays(Size, Array);
}
void LBindVerBuff(GLuint Target, GLuint VBO) {
	glBindBuffer(Target, VBO);
}
void LBindVerArrays(GLuint VAO) {
	glBindVertexArray(VAO);
}
void LBufferData(GLuint Target, GLuint Use, GLsizeiptr Size, const void* data) {
	glBufferData(Target, Size, data, Use);
}
void LEnableVerAttribArray(GLuint Index) {
	glEnableVertexAttribArray(Index);
}
void LVerAttribPointer(GLuint Index, GLint Size, GLuint Type, GLboolean Bool, GLsizei Sizei) {
	glVertexAttribPointer(Index, Size, Type, Bool, Sizei, (void*)0);
}
void LDeleteBuffer(int SizeBuffer, GLuint* Buffer, ...) {
	va_list buffer;
	va_start(buffer, &Buffer);
	for (int i = 0; i < SizeBuffer; i++) {
		GLuint* Buf = va_arg(buffer, GLuint);
		glDeleteBuffers(1, &Buf);
	}
	va_end(buffer);
	glDeleteBuffers(1,&Buffer);
}
void LIsBuffers(int Size, GLuint Buffer, ...) {
	va_list buffer;
	va_start(buffer, Buffer);
	for (int i = 0; i < Size; i++) {
		GLuint Buf = va_arg(buffer, GLuint);
		glIsBuffer(Buf);
	}
	va_end(buffer);
	glIsBuffer(Buffer);
}
void LDeleteVerArray(GLuint *Array) {
	glDeleteVertexArrays(1,&Array);
}
void LDrawElement(GLuint Mode, GLsizei Size, GLuint Type, const void* indices) {
	glDrawElements(Mode, Size, Type, indices);
}
void LDrawArray(GLuint Mode, GLint First, GLsizei Size) {
	glDrawArrays(Mode, First, Size);
}
void LViewport(GLint x, GLint y, GLsizei Width, GLsizei Height) {
	glViewport(x, y, Width, Height);
}
void LUnBind(GLuint Mode) {
	if (Mode == LEX_ARRAY_BUFFER) {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	if (Mode == LEX_ELEMENT_ARRAY_BUFFER) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	if (Mode == 0) {
		glBindVertexArray(0);
	}
	if (Mode == LEX_UNBIND) {
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
void LexSetPosWindow(int X, int Y) {
	glfwWindowHint(GLFW_POSITION_X, X);
	glfwWindowHint(GLFW_POSITION_Y, Y);
}
void LSetWindowMode(GLFWwindow* window,int Mode,GLboolean ModeBool) {
	if (Mode == LEX_MAXIMIZED_WINDOW && ModeBool == LEX_FALSE) {
		glfwMaximizeWindow(window);
	}
	else if (Mode == LEX_MINIMIZED_WINDOW && ModeBool == LEX_FALSE) {
		glfwIconifyWindow(window);
	}
	else if (Mode == LEX_HIDE_WINDOW && ModeBool == LEX_FALSE) {
		glfwHideWindow(window);
	}
	else if (Mode == LEX_VISIBLE_WINDOW) {
		glfwWindowHint(LEX_VISIBLE_WINDOW, ModeBool);
	}
	else if (Mode == LEX_FLOAT_WINDOW) {
		glfwWindowHint(LEX_FLOAT_WINDOW, ModeBool);
	}
	else if (Mode == LEX_MOUSE_PASSTHROUGH_WINDOW) {
		glfwWindowHint(LEX_MOUSE_PASSTHROUGH_WINDOW, ModeBool);
	}
	else if (Mode == LEX_FOCUSED_WINDOW) {
		glfwWindowHint(LEX_FOCUSED_WINDOW, ModeBool);
	}
	else if (Mode == LEX_TRANSPARENT_FRAMEBUFFER_WINDOW) {
		glfwWindowHint(LEX_TRANSPARENT_FRAMEBUFFER_WINDOW, ModeBool);
	}
	else if (Mode == LEX_RESIZABLE_WINDOW) {
		glfwWindowHint(LEX_RESIZABLE_WINDOW, ModeBool);
	}
	else if (Mode == GLFW_FOCUS_ON_SHOW) {
		glfwWindowHint(GLFW_FOCUS_ON_SHOW, ModeBool);
	}
	else if (Mode == LEX_AUTO_ICONIFY_WINDOW) {
		glfwWindowHint(LEX_AUTO_ICONIFY_WINDOW, ModeBool);
	}
	else {
		printf("Error: Mode Window Size Not Found\n");
	}
}
void LWindowOpacity(GLFWwindow* window, float opacity) {
	glfwSetWindowOpacity(window, opacity);
}
void LEXLoadGL(void) {
	gladLoadGLLoader((GLADloadproc)(void*)glfwGetProcAddress);
}
GLFWwindow* LInitWindow(int Width, int Height, const char* Title) {
	GLFWwindow* window = glfwCreateWindow(Width, Height, Title,NULL, NULL);
	if (window == NULL) { 
	printf("ERROR WINDOW !");
	return NULL;
	}
	return window;
}
void LSetColorBits(GLuint ModeColorBits) {
	if (ModeColorBits == LEX_RBGA_NORMAL_BIT8) {
		glfwWindowHint(LEX_RED_BITS, 8);
		glfwWindowHint(LEX_GREEN_BITS, 8);
		glfwWindowHint(LEX_BLUE_BITS, 8);
		glfwWindowHint(LEX_ALPHA_BITS, 8);
	}
	else if (ModeColorBits == LEX_RBGA_NORMAL_BIT10) {
		glfwWindowHint(LEX_RED_BITS, 10);
		glfwWindowHint(LEX_GREEN_BITS, 10);
		glfwWindowHint(LEX_BLUE_BITS, 10);
		glfwWindowHint(LEX_ALPHA_BITS, 10);
	}
	else if (ModeColorBits == LEX_RBGA16_BITS) {
		glfwWindowHint(LEX_RED_BITS, 16);
		glfwWindowHint(LEX_GREEN_BITS, 16);
		glfwWindowHint(LEX_BLUE_BITS, 16);
		glfwWindowHint(LEX_ALPHA_BITS, 16);
	}
	else if (ModeColorBits == LEX_RBGA10_A2_BITS) {
		glfwWindowHint(LEX_RED_BITS, 10);
		glfwWindowHint(LEX_GREEN_BITS, 10);
		glfwWindowHint(LEX_BLUE_BITS, 10);
		glfwWindowHint(LEX_ALPHA_BITS, 2);
	}
	else printf("ERROR : MODE COLOR NOT SUPPORT !");
}
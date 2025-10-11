#include<lex.h>
#include<lexcore.h>
#include<stdarg.h>
#include<lexgl.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void LColorClear(LexColor color) {
	glClearColor(color.R, color.G, color.B, color.A);
	glClear(GL_COLOR_BUFFER_BIT);
}
//Window
///////----------------
typedef struct LEXCORE {
	GLFWwindow* Window;
}LEXCORE;
LEXCORE Core;
///////----------------
////--Function Core--//
void LCreateWindow(int Width, int Height, const char* Title) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	Core.Window = glfwCreateWindow(Width, Height, Title, NULL, NULL);
	if (Core.Window == NULL) {
		printf("ERROR WINDOW !");
	}
}
void LSetCursorMode(int ModeCursor) {
	if(ModeCursor == LCURSOR_CAPTURED)
		glfwSetInputMode(Core.Window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
	else if(ModeCursor == LCURSOR_DISABLED)
		glfwSetInputMode(Core.Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	else if(ModeCursor == LCURSOR_HIDDEN)
		glfwSetInputMode(Core.Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	else if(ModeCursor == LCURSOR_NORMAL)
		glfwSetInputMode(Core.Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	else
		printf("ERROR : MODE CURSOR NOT SUPPORT !");
}
int LWindowShouldClose(void) {
	glfwWindowShouldClose(Core.Window);
}
void LPollSwapWindow(void) {
	glfwSwapBuffers(Core.Window);
	glfwPollEvents();
}
void LDestroyWindow(void) {
	glfwDestroyWindow(Core.Window);
	glfwTerminate();
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
void LexSetPosWindow(int X, int Y) {
	glfwWindowHint(GLFW_POSITION_X, X);
	glfwWindowHint(GLFW_POSITION_Y, Y);
}
void LSetWindowMode(int ModeWindow, int ModeBool) {
	glfwWindowHint(ModeWindow, ModeBool);
}
void LSetStatusWindow(int Mode) {
	if (Mode == LEX_MAXIMIZED_WINDOW) {
		glfwMaximizeWindow(Core.Window);
	}
	else if (Mode == LEX_MINIMIZED_WINDOW) {
		glfwIconifyWindow(Core.Window);
	}
	else if (Mode == LEX_HIDE_WINDOW) {
		glfwHideWindow(Core.Window);
	}
	else {
		printf("Error: Mode Window Size Not Found\n");
	}
}
void LWindowOpacity(float opacity) {
	glfwSetWindowOpacity(Core.Window, opacity);
}
//Lex Shader Vertex And Fragment
void LShaderVerFrag(GLuint *Ver,GLuint *Frag)
{
	*Ver = glCreateShader(GL_VERTEX_SHADER);
	*Frag = glCreateShader(GL_FRAGMENT_SHADER);
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
void LGenVerBuff(int Size, GLuint* Buffer) {
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
void LBufferData(GLuint Target, GLuint Uses, GLsizeiptr Size, const void* data) {
	glBufferData(Target,Size,data, Uses);
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
	glfwMakeContextCurrent(Core.Window);
	gladLoadGLLoader((GLADloadproc)(void*)glfwGetProcAddress);
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
void LWaitEvent(void) {
	glfwWaitEvents();
}
void LWaitTimeEventOut(double TimeWait) {
	glfwWaitEventsTimeout(TimeWait);
}
void LDestroyCursor(GLFWcursor *Cursor) {
	glfwDestroyCursor(Cursor);
}
int LGetKeyInput(int Key) {
	return glfwGetKey(Core.Window,Key);
}
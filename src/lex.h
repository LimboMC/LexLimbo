#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#ifndef LEX_LIBRARY
#define LEX_LIBRARY
typedef struct LexColor {
	float R; float G; //RED,GREEN
	float B; float A; //BLUE,ALPHA
}LexColor;
#if defined(__cplusplus)
extern"C" {
#endif // defined(__cplusplus)
#include<lexcore.h>
	void LColorClear(LexColor color);
	GLuint LShaderVer(void);
	GLuint LShaderFrag(void);
	void LShaderSource(GLuint Shader, GLsizei Size, const GLchar* const* ShaderVertex);
	void LDeleteShader(GLuint Size, GLuint Shader, ...);
	void LIsShader(GLuint Size, GLuint Shader, ...);
	GLuint LCreateProgram(void);
	void LAttachShader(GLuint Program, GLuint Vertex, GLuint Fragment);
	void LLinkProgram(GLuint Program);
	void LUseProgram(GLuint Program);
	void LDeleteProgram(GLuint Program);
	void LGenVerBuff(GLsizei Size, GLuint* Buffer);
	void LGenVerArray(GLsizei Size, GLuint* Array);
	void LBindVerBuff(GLuint Target, GLuint VBO);
	void LBindVerArrays(GLuint VAO);
	void LBufferData(GLuint Target, GLuint Use, GLsizeiptr Size, const void* data);
	void LEnableVerAttribArray(GLuint Index);
     void LVerAttribPointer(GLuint Index, GLint Size, GLuint Type, GLboolean Bool, GLsizei Sizei);
	void LDeleteBuffer(GLsizei SizeBuffer, GLuint Buffer, ...);
	void LIsBuffers(GLsizei Size, GLuint Buffer, ...);
	void LDeleteVerArray(GLsizei Size, GLuint Array);
	void LDrawElement(GLuint Mode, GLsizei Size, GLuint Type, const void* indices);
	void LDrawArray(GLuint Mode, GLint First, GLsizei Size);
	void LViewport(GLint x, GLint y, GLsizei Width, GLsizei Height);
	void LUnBind(GLuint Mode);
	void LexSetPosWindow(int X, int Y);
	void LSetWindowMode(GLFWwindow* window, int Mode, int ModeBool);
	void LWindowOpacity(GLFWwindow* window, float Opacity);
	void LWindowMoniter(GLFWwindow* window, GLFWmonitor* monitor, int X, int Y, int Width, int Height);
	void LEXLoadGL(void);
	GLFWwindow* LCreateWindow(int Width, int Height, const char* Title, GLFWmonitor* moniter);
#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#endif // !LEX_LIBRARY
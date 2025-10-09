#pragma once
#ifndef LEX_LIMBO_CORE
#define LEX_LIMBO_CORE
#include<glad/glad.h>
#include<GLFW/glfw3.h>
void LCreateWindow(int Width, int Height, const char* Title);
void LexSetPosWindow(int X, int Y);
void LSetWindowMode(int Mode, GLboolean ModeBool);
void LWindowOpacity(float Opacity);
void LMakeCotext(void);
int LWindowShouldClose(void);
void LPollSwapWindow(void);
void LDestroyWindow(void);
void LSetColorBits(GLuint ModeColorBits);
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
void LDeleteVerArray(GLuint *Array);
void LDrawElement(GLuint Mode, GLsizei Size, GLuint Type, const void* indices);
void LDrawArray(GLuint Mode, GLint First, GLsizei Size);
void LViewport(GLint x, GLint y, GLsizei Width, GLsizei Height);
void LUnBind(GLuint Mode);
#endif // !LEX_LIMBO_CORE
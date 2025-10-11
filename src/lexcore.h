#pragma once
#ifndef LEX_LIMBO_CORE
#define LEX_LIMBO_CORE
#include<glad/glad.h>
#include<GLFW/glfw3.h>
void LCreateWindow(int Width, int Height, const char* Title);
void LexSetPosWindow(int X, int Y);
void LSetWindowMode(int ModeWindow, int ModeBool);
void LSetCursorMode(int ModeCursor);
void LWindowOpacity(float Opacity);
int LWindowShouldClose(void);
void LPollSwapWindow(void);
void LDestroyWindow(void);
void LSetColorBits(GLuint ModeColorBits);
void LShaderVerFrag(GLuint* Ver, GLuint* Frag);
void LShaderSource(GLuint Shader, GLsizei Size, const GLchar* const* ShaderVertex);
void LDeleteShader(GLuint Size, GLuint Shader, ...);
void LIsShader(GLuint Size, GLuint Shader, ...);
GLuint LCreateProgram(void);
void LAttachShader(GLuint Program, GLuint Vertex, GLuint Fragment);
void LLinkProgram(GLuint Program);
void LUseProgram(GLuint Program);
void LDeleteProgram(GLuint Program);
void LGenVerBuff(int Size, GLuint* Buffer);
void LGenVerArray(GLsizei Size, GLuint* Array);
void LBindVerBuff(GLuint Target, GLuint VBO);
void LBindVerArrays(GLuint VAO);
void LBufferData(GLuint Target, GLuint Uses, GLsizeiptr Size, const void* data);
void LSetStatuWindow(int Mode);
void LEnableVerAttribArray(GLuint Index);
void LVerAttribPointer(GLuint Index, GLint Size, GLuint Type, GLboolean Bool, GLsizei Sizei);
void LDeleteBuffer(GLsizei SizeBuffer, GLuint* Buffer, ...);
void LIsBuffers(GLsizei Size, GLuint Buffer, ...);
void LDeleteVerArray(GLuint *Array);
void LDrawElement(GLuint Mode, GLsizei Size, GLuint Type, const void* indices);
void LDrawArray(GLuint Mode, GLint First, GLsizei Size);
void LViewport(GLint x, GLint y, GLsizei Width, GLsizei Height);
void LUnBind(GLuint Mode);
void LWaitTimeEventOut(double TimeWait);
void LWaitEvent(void);
void LDestroyCursor(GLFWcursor* Cursor);
int LGetKeyInput(int Key);
#endif // !LEX_LIMBO_CORE
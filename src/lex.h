#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#ifndef LEX_LIBRARY
#define LEX_LIBRARY
#include<lexcore.h>
typedef struct LexColor {
	float R;float G;
	float B;float A;
} LexColor;
typedef enum{
//Alphanumeric
LKEY_0 = 48,                 //Key_0
LKEY_1 = 49,                 //Key_1
LKEY_2 = 50,                 //Key_2
LKEY_3 = 51,                 //Key_3
LKEY_4 = 52,                 //Key_4
LKEY_5 = 53,                 //Key_5
LKEY_6 = 54,                 //Key_6
LKEY_7 = 55,                 //Key_7
LKEY_8 = 56,                 //Key_8
LKEY_9 = 57,                 //Key_9
LKEY_A = 65,                 //Key_A
LKEY_B = 66,                 //Key_B
LKEY_C = 67,                 //Key_C
LKEY_D = 68,                 //Key_D
LKEY_E = 69,                 //Key_E
LKEY_F = 70,                 //Key_F
LKEY_G = 71,                 //Key_G
LKEY_H = 72,                 //Key_H
LKEY_I = 73,                 //Key_I
LKEY_J = 74,                 //Key_J
LKEY_K = 75,                 //Key_K
LKEY_L = 76,                 //Key_L
LKEY_M = 77,                 //Key_M
LKEY_N = 78,                 //Key_N
LKEY_O = 79,                 //Key_O
LKEY_P = 80,                 //Key_P
LKEY_Q = 81,                 //Key_Q
LKEY_R = 82,                 //Key_R
LKEY_S = 83,                 //Key_S
LKEY_T = 84,                 //Key_T
LKEY_V = 86,                 //Key_V
LKEY_W = 87,                 //Key_W
LKEY_X = 88,                 //Key_X
LKEY_Y =  89,                //Key_Y
LKEY_Z  = 90,                //KeyZ
LKEY_SPACE = 32,             //Key_Space
LKEY_APOSTROPHE = 39,        //Key_'
LKEY_COMMA = 44,             //Key_,
LKEY_MINUS = 45,             //Key_-
LKEY_PERIOD = 46,            //Key_.
LKEY_SLASH = 47,             //Key_/
LKEY_LEFT_BRACKET = 91,      //Key_[
LKEY_BACKSLASH = 92,         /* Key_\ */
LKEY_RIGHT_BRACKET = 93,     //Key_]
LKEY_GRAVE_ACCENT = 96,      //Key_`
LKEY_EQUAL = 61,             // =
LKEY_WORLD_1 = 161,          /* non-US #1 */
LKEY_WORLD_2 = 162,          /* non-US #2 */
/* Modifier keys */
LKEY_ESCAPE = 256,           //Key_ESC
LKEY_ENTER = 257,            //Key_ENTER
LKEY_TAB = 258,              //Key_TAB
LKEY_BACKSPACE = 259,        //Key_BACKSPACE
LKEY_INSERT = 260,           //Key_INSERT
LKEY_DELETE = 261,           //Key_DELETE
LKEY_RIGHT = 262,            //Key ->
LKEY_LEFT = 263,             //Key <-
LKEY_DOWN = 264,             //Key_Down
LKEY_UP = 265,               //Key_Up
LKEY_PAGE_UP = 266,          //Key_PG_UP
LKEY_PAGE_DOWN = 267,        //Key_PG_DOWN
LKEY_HOME = 268,             //Key_HOME
LKEY_END = 269,              //Key_END
LKEY_CAPS_LOCK = 280,        //Key_CAPS_LOCK
LKEY_LEFT_SHIFT = 340,       //Key_LEFT_SHIFT
LKEY_LEFT_CONTROL = 341,     //Key_LEFT_CONTROL
LKEY_LEFT_ALT = 342,         //Key_LEFT_ALT
LKEY_LEFT_SUPER = 343,       //Key_LEFT_SUPER
LKEY_RIGHT_SHIFT = 344,      //Key_RIGHT_SHIFT
LKEY_RIGHT_CONTROL = 345,    //Key_RIGHT_CONTROL
LKEY_RIGHT_ALT = 346,        //Key_RIGHT_ALT
LKEY_RIGHT_SUPER = 347,      //Key_RIGHT_SUPER
LKEY_MENU = 348,             //Key_MENU
//Function Key
LKEY_F1 = 290,               //Key_F1
LKEY_F2 = 291,               //Key_F2
LKEY_F3 = 292,               //Key_F3
LKEY_F4 = 293,               //Key_F4
LKEY_F5 = 294,               //Key_F5
LKEY_F6 = 295,               //Key_F6
LKEY_F7 = 296,               //Key_F7
LKEY_F8 = 297,               //Key_F8
LKEY_F9 = 298,               //Key_F9
LKEY_F10 = 299,              //Key_F10
LKEY_F11 = 300,              //Key_F11
LKEY_F12 = 301,              //Key_F12
LKEY_F13 = 302,              //Key_F13
LKEY_F14 = 303,              //Key_F14
LKEY_F15 = 304,              //Key_F15
LKEY_F16 = 305,              //Key_F16
LKEY_F17 = 306,              //Key_F17
LKEY_F18 = 307,              //Key_F18
//KeyPad Key
LKEY_KP_0 = 320,             //KeyPad_0
LKEY_KP_1 = 321,             //KeyPad_1
LKEY_KP_2 = 322,             //KeyPad_2
LKEY_KP_3 = 323,             //KeyPad_3
LKEY_KP_4 = 324,             //KeyPad_4
LKEY_KP_5 = 325,             //KeyPad_5
LKEY_KP_6 = 326,             //KeyPad_6
LKEY_KP_7 = 327,             //KeyPad_7
LKEY_KP_8 = 328,             //KeyPad_8
LKEY_KP_9 = 329,             //KeyPad_9
LKEY_KP_DECIMAL = 330,       //KeyPad_. (Decimal)
LKEY_KP_DIVIDE = 331,        //KeyPad_/
LKEY_KP_MULTIPLY = 332,      //KeyPad_*
LKEY_KP_SUBTRACT = 333,      //KeyPad_-
LKEY_KP_ADD = 334,           //KeyPad_+
LKEY_KP_ENTER = 335,         //KeyPad_ENTER
LKEY_KP_EQUAL = 336,         //KeyPad_=
}LexInput;
typedef struct LexSetKey {
	int key;
	int scancode;
	int action;
	int mods;
}LexSetKey;
#if defined(__cplusplus)
extern"C" {
#endif // defined(__cplusplus)
	void LColorClear(LexColor color);
	void LexSetPosWindow(int X, int Y);
	void LSetWindowMode(int Mode, GLboolean ModeBool);
	void LMakeContext(void);
	void LWindowOpacity(float Opacity);
	int LWindowShouldClose(void);
	void LPollSwapWindow(void);
	void LDestroyWindow(void);
	void LCreateWindow(int Width, int Height, const char* Title);
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
	void LDeleteBuffer(int SizeBuffer, GLuint* Buffer, ...);
	void LIsBuffers(int Size, GLuint Buffer, ...);
	void LDeleteVerArray(GLuint *Array);
	void LDrawElement(GLuint Mode, GLsizei Size, GLuint Type, const void* indices);
	void LDrawArray(GLuint Mode, GLint First, GLsizei Size);
	void LViewport(GLint x, GLint y, GLsizei Width, GLsizei Height);
	void LUnBind(GLuint Mode);
#if defined(__cplusplus)
}
#endif // defined(__cplusplus)
	//Verex Array and Veretx Buffers And Element Buffers
	void LGenVerBuff(GLsizei Size,GLuint *Buffer) {
		*Buffer = 0;
		glGenBuffers(Size, Buffer);
	}
	void LGenVerArray(GLsizei Size, GLuint *Array) {
		*Array = 0;
		glGenVertexArrays(Size, Array);
	}
	void LBindVerBuff(GLuint Target,GLuint VBO) {
		glBindBuffer(Target,VBO);
	}
	void LBindVerArrays(GLuint VAO) {
		glBindVertexArray(VAO);
	}
	void LBufferData(GLuint Target, GLuint Use, GLsizeiptr Size,const void *data) {
		glBufferData(Target, Size, data, Use);
	}
	void LEnableVerAttribArray(GLuint Index) {
		glEnableVertexAttribArray(Index);
	}
	void LVerAttribPointer(GLuint Index,GLint Size,GLuint Type,GLboolean Bool,GLsizei Sizei,const void *Pointer ) {
		glVertexAttribPointer(Index, Size, Type, Bool, Sizei, Pointer);
	}
	void LDeleteBuffer(GLsizei Size,GLuint Buffer) {
		glDeleteBuffers(Size,&Buffer);
	}
	void LDeleteVerArray(GLsizei Size, GLuint Array) {
		glDeleteVertexArrays(Size, &Array);
	}
	void LDrawElement(GLuint Mode,GLsizei Size,GLuint Type,const void * indices) {
		glDrawElements(Mode, Size, Type, indices);
	}
	void LexLoadGL() {
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}
	typedef enum {
		LKey_0 = 48,
		LKey_1 = 49,
		LKey_2 = 50,
		LKey_3 = 51,
		LKey_4 = 52,
		LKey_5 = 53,
		LKey_6 = 54,
		LKey_7 = 55,
		LKey_8 = 56,
		LKey_9 = 57,
		LKey_A = 65,
		LKey_B = 66,
		LKey_C = 67,
		LKey_D = 68,
		LKey_E = 69,
		LKey_F = 70,
		LKey_G = 71,
		LKey_H = 72,
		LKey_I = 73,
		LKey_J = 74,
		LKey_K = 75,
		LKey_L = 76,
		LKey_M = 77,
		LKey_N = 78,
		LKey_O = 79,
		LKey_P = 80,
		LKey_Q = 81,
		LKey_R = 82,
		LKey_S = 83,
		LKey_T = 84,
		LKey_U = 85,
		LKey_V = 86,
		LKey_W = 87,
		LKey_X = 88,
		LKey_Y = 89,
		LKey_Z = 90,
		//Function keys
		LKEY_ESCAPE = 256,
		LKEY_ENTER = 257,
		LKEY_TAB = 258,
		LKEY_BACKSPACE = 259,
		LKEY_INSERT = 260,
		LKEY_DELETE = 261,
		LKEY_RIGHT = 262,
		LKEY_LEFT = 263,
		LKEY_DOWN = 264,
		LKEY_UP = 265,
		LKEY_PAGE_UP = 266,
		LKEY_PAGE_DOWN = 267,
		LKEY_HOME = 268,
		LKEY_END = 269,
		LKEY_CAPS_LOCK = 280,
		LKEY_SCROLL_LOCK = 281,
		LKEY_NUM_LOCK = 282,
		LKEY_PRINT_SCREEN = 283,
		LKEY_PAUSE = 284,
		LKEY_F1 = 290,
		LKEY_F2 = 291,
		LKEY_F3 = 292,
		LKEY_F4 = 293,
		LKEY_F5 = 294,
		LKEY_F6 = 295,
		LKEY_F7 = 296,
		LKEY_F8 = 297,
		LKEY_F9 = 298,
		LKEY_F10 = 299,
		LKEY_F11 = 300,
		LKEY_F12 = 301,
		LKEY_F13 = 302,
		LKEY_F14 = 303,
		LKEY_F15 = 304,
		LKEY_F16 = 305,
		LKEY_F17 = 306,
		LKEY_F18 = 307,
		LKEY_F19 = 308,
		LKEY_F20 = 309,
		LKEY_F21 = 310,
		LKEY_F22 = 311,
		LKEY_F23 = 312,
		LKEY_F24 = 313,
		LKEY_F25 = 314,
		LKEY_KP_0 = 320,
		LKEY_KP_1 = 321,
		LKEY_KP_2 = 322,
		LKEY_KP_3 = 323,
		LKEY_KP_4 = 324,
		LKEY_KP_5 = 325,
		LKEY_KP_6 = 326,
		LKEY_KP_7 = 327,
		LKEY_KP_8 = 328,
		LKEY_KP_9 = 329,
		LKEY_KP_DECIMAL = 330,
		LKEY_KP_DIVIDE = 331,
		LKEY_KP_MULTIPLY = 332,
		LKEY_KP_SUBTRACT = 333,
		LKEY_KP_ADD = 334,
		LKEY_KP_ENTER = 335,
		LKEY_KP_EQUA = 336,
		LKEY_LEFT_SHIFT = 340,
		LKEY_LEFT_CONTROL = 341,
		LKEY_LEFT_ALT = 342,
		LKEY_LEFT_SUPER = 343,
		LKEY_RIGHT_SHIFT = 344,
		LKEY_RIGHT_CONTROL = 345,
		LKEY_RIGHT_ALT = 346,
		LKEY_RIGHT_SUPER = 347,
		LKEY_MENU = 348
	} LexKeyBoard;
#endif // !LEX_LIBRARY
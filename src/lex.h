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
typedef enum {
LEX_MOUSE_BUTTON_LEFT = 0,
LEX_MOUSE_BUTTON_RIGHT = 1,
LEX_MOUSE_BUTTON_MIDDLE = 2,
LEX_MOUSE_BUTTON_4 = 3,
LEX_MOUSE_BUTTON_5 = 4,
LEX_MOUSE_BUTTON_6 = 5,
LEX_MOUSE_BUTTON_7 = 6,
LEX_MOUSE_BUTTON_LAST = 7,
}LexMouse;
typedef enum {
LEX_RELEASE = 0,
LEX_PRESS = 1,
LEX_REPEAT = 2,
}LexStatus;
typedef enum {
LCURSOR_NORMAL = 0x00034001,
LCURSOR_HIDDEN = 0x00034002,
LCURSOR_DISABLED = 0x00034003,
LCURSOR_CAPTURED = 0x00034004,
}LexModeCursor;
typedef enum {
LEX_JOYSTICK_1 = 0,
LEX_JOYSTICK_2 = 1,
LEX_JOYSTICK_3 = 2,
LEX_JOYSTICK_4 = 3,
LEX_JOYSTICK_5 = 4,
LEX_JOYSTICK_6 = 5,
LEX_JOYSTICK_7 = 6,
LEX_JOYSTICK_8 = 7,
LEX_JOYSTICK_9 = 8,
LEX_JOYSTICK_10 = 9,
LEX_JOYSTICK_11 = 10,
LEX_JOYSTICK_12 = 11,
LEX_JOYSTICK_13 = 12,
LEX_JOYSTICK_14 = 13,
LEX_JOYSTICK_15 = 14,
LEX_JOYSTICK_16 = 15,
}LexJoystick;
typedef enum {
LEX_GAMEPAD_BUTTON_A = 0,
LEX_GAMEPAD_BUTTON_B = 1,
LEX_GAMEPAD_BUTTON_X = 2,
LEX_GAMEPAD_BUTTON_Y = 3,
LEX_GAMEPAD_BUTTON_LEFT_BUMPER = 4,
LEX_GAMEPAD_BUTTON_RIGHT_BUMPER = 5,
LEX_GAMEPAD_BUTTON_BACK = 6,
LEX_GAMEPAD_BUTTON_START = 7,
LEX_GAMEPAD_BUTTON_GUIDE = 8,
LEX_GAMEPAD_BUTTON_LEFT_THUMB = 9,
LEX_GAMEPAD_BUTTON_RIGHT_THUMB = 10,
LEX_GAMEPAD_BUTTON_DPAD_UP = 11,
LEX_GAMEPAD_BUTTON_DPAD_RIGHT = 12,
LEX_GAMEPAD_BUTTON_DPAD_DOWN = 13,
LEX_GAMEPAD_BUTTON_DPAD_LEFT = 14,
LEX_GAMEPAD_BUTTON_CROSS = 0,
LEX_GAMEPAD_BUTTON_CIRCLE = 1,
LEX_GAMEPAD_BUTTON_SQUARE = 2,
LEX_GAMEPAD_BUTTON_TRIANGLE =  3,
}LexGamePad;
typedef struct LexTexture {
	unsigned char* Image;
	int Width;
	int Height;
} LexTexture;
typedef struct LexLabel {
	double X,Y;
	int Width,Height;
	LexColor Color;
	LexTexture Texture;
} LexLabel;
typedef struct LexButton {
	double X,Y;
	int Width, Height;
	LexColor Color;
	LexTexture Texture;
} LexButton;
#if defined(__cplusplus)
extern"C" {
#endif // defined(__cplusplus)
	void LColorClear(LexColor color);
	void LexSetPosWindow(int X, int Y);
	void LSetWindowMode(int ModeWindow,int ModeBool);
	void LSetCursorMode(int ModeCursor);
	void LWindowOpacity(float Opacity);
	int LWindowShouldClose(void);
	void LPollSwapWindow(void);
	void LDestroyWindow(void);
	void LCreateWindow(int Width, int Height, const char* Title);
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
	void LSetStatusWindow(int Mode);
	void LEnableVerAttribArray(GLuint Index);
     void LVerAttribPointer(GLuint Index, GLint Size, GLuint Type, GLboolean Bool, GLsizei Sizei);
	void LDeleteBuffer(int SizeBuffer, GLuint* Buffer, ...);
	void LIsBuffers(int Size, GLuint Buffer, ...);
	void LDeleteVerArray(GLuint *Array);
	void LDrawElement(GLuint Mode, GLsizei Size, GLuint Type, const void* indices);
	void LDrawArray(GLuint Mode, GLint First, GLsizei Size);
	void LViewport(GLint x, GLint y, GLsizei Width, GLsizei Height);
	void LUnBind(GLuint Mode);
	void LWaitTimeEventOut(double TimeWait);
	void LWaitEvent(void);
	void LDestroyCursor(GLFWcursor* Cursor);
	int LGetKeyInput(int Key);
	//GUI LEX

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)
#endif // !LEX_LIBRARY
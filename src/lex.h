#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<lexgl.h>
#include <stdarg.h>
	typedef struct LexColor {
		float Red;
		float Blue;
		float Green;
		float Alpha;
	} LexColor;
	void LColorClear(LexColor color) {
		glClearColor(color.Red, color.Green, color.Blue, color.Alpha);
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
		glShaderSource(Shader, Size, ShaderVertex,NULL);
		glCompileShader(Shader);
	}
	void LDeleteShader(GLuint Size,GLuint Shader,...) {
		va_list Shaders;
		va_start(Shaders,Shader);
		for(int  i= 0;i<Size;i++){
			GLuint Sha = va_arg(Shaders,GLuint);
			glDeleteShader(Sha);
		}
		va_end(Shaders);
	}
	void LIsShader(GLuint Size,GLuint Shader,...) {
		va_list IsShader;
		va_start(IsShader, Shader);
		for (int i = 0; i < Size; i++) {
			GLuint Sha = va_arg(IsShader, GLuint);
			glIsShader(Sha);
		}
		va_end(IsShader);
	}
	//Program Shader
	GLuint LCreateProgram(void){
		return glCreateProgram();
	}
	void LAttachShader(GLuint Program,GLuint Vertex,GLuint Fragment) {
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
	void LVerAttribPointer(GLuint Index,GLint Size,GLuint Type,GLboolean Bool,GLsizei Sizei) {
		glVertexAttribPointer(Index, Size, Type, Bool, Sizei, (void*)0);
	}
	void LDeleteBuffer(GLsizei SizeBuffer,GLuint Buffer,...) {
		va_list buffer;
		va_start(buffer,Buffer);
		GLuint SizeBuf = 1;
		for (int i = 0; i < SizeBuffer; i++) {
			GLuint Buf = va_arg(buffer, GLuint);
			glDeleteBuffers(1, &Buf);
		}
		va_end(buffer);
		glDeleteBuffers(1,&Buffer);
	}
	void LIsBuffers(GLsizei Size, GLuint Buffer,...) {
		va_list buffer;
		va_start(buffer, Buffer);
		for (int i = 0; i < Size; i++) {
			GLuint Buf = va_arg(buffer, GLuint);
			glIsBuffer(Buf);
		}
		va_end(buffer);
		glIsBuffer(Buffer);
	}
	void LDeleteVerArray(GLsizei Size, GLuint Array) {
		glDeleteVertexArrays(Size, &Array);
	}
	void LDrawElement(GLuint Mode,GLsizei Size,GLuint Type,const void * indices) {
		glDrawElements(Mode, Size, Type, indices);
	}
	void LDrawArray(GLuint Mode,GLint First,GLsizei Size) {
		glDrawArrays(Mode, First, Size);
	}
	void LViewport(GLint x,GLint y,GLsizei Width,GLsizei Height) {
		glViewport(x, y, Width, Height);
	}
	void LUnBind(GLuint Mode) {
		if (Mode == LEX_ARRAY_BUFFER) {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		if(Mode ==LEX_ELEMENT_ARRAY_BUFFER){
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
	void LexSetPosWindow(int X,int Y) {
		glfwWindowHint(GLFW_POSITION_X, X);
		glfwWindowHint(GLFW_POSITION_Y, Y);
	}
	void LSetWindowMode(GLFWwindow *window,int Mode,int ModeBool) {
		if (Mode == LEX_MAXIMIZED_WINDOW && ModeBool == NULL) {
			glfwMaximizeWindow(window);
		}
		else if (Mode == LEX_MINIMIZED_WINDOW &&ModeBool == NULL){
			glfwIconifyWindow(window);
		}
		else if(Mode == LEX_HIDE_WINDOW && ModeBool == NULL){
			glfwHideWindow(window);
		}
		else if (Mode == LEX_VISIBLE_WINDOW) {
			glfwWindowHint(LEX_VISIBLE_WINDOW,ModeBool);
		}
		else if (Mode == LEX_FLOAT_WINDOW) {
			glfwWindowHint(LEX_FLOAT_WINDOW,ModeBool);
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
	void LWindowOpacity(GLFWwindow*window,float opacity) {
		glfwSetWindowOpacity(window,opacity);
	}
	void LWindowMoniter(GLFWwindow* window,int X,int Y,int W,int Height,int RefeshRate) {
		const GLFWmonitor* monitor = glfwGetWindowMonitor(window);
		glfwSetWindowMonitor(window,monitor,X,Y,W,Y,RefeshRate);
	}
	void LEXLoadGL(void) {
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}
	GLFWwindow * LCreateWindow(int Width, int Height, const char* Title,GLFWmonitor *moniter) {
		GLFWwindow * window = glfwCreateWindow(Width, Height, Title,moniter, NULL);
		return window;
	}
	//Lex KeyBoard
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
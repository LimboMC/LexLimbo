#include<lexcore.h>
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
	glShaderSource(Shader, Size, ShaderVertex, NULL);
	glCompileShader(Shader);
}
void LDeleteShader(GLuint Size, GLuint Shader, ...) {
	va_list Shaders;
	va_start(Shaders, Shader);
	for (int i = 0; i < Size; i++) {
		GLuint Sha = va_arg(Shaders, GLuint);
		glDeleteShader(Sha);
	}
	va_end(Shaders);
}
void LIsShader(GLuint Size, GLuint Shader, ...) {
	va_list IsShader;
	va_start(IsShader, Shader);
	for (int i = 0; i < Size; i++) {
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
void LDeleteBuffer(GLsizei SizeBuffer, GLuint Buffer, ...) {
	va_list buffer;
	va_start(buffer, Buffer);
	GLuint SizeBuf = 1;
	for (int i = 0; i < SizeBuffer; i++) {
		GLuint Buf = va_arg(buffer, GLuint);
		glDeleteBuffers(1, &Buf);
	}
	va_end(buffer);
	glDeleteBuffers(1, &Buffer);
}
void LIsBuffers(GLsizei Size, GLuint Buffer, ...) {
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
void LSetWindowMode(GLFWwindow* window, int Mode, int ModeBool) {
	if (Mode == LEX_MAXIMIZED_WINDOW && ModeBool == NULL) {
		glfwMaximizeWindow(window);
	}
	else if (Mode == LEX_MINIMIZED_WINDOW && ModeBool == NULL) {
		glfwIconifyWindow(window);
	}
	else if (Mode == LEX_HIDE_WINDOW && ModeBool == NULL) {
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
void LWindowMoniter(GLFWwindow* window, int X, int Y, int W, int Height, int RefeshRate) {
	const GLFWmonitor* monitor = glfwGetWindowMonitor(window);
	glfwSetWindowMonitor(window, monitor, X, Y, W, Y, RefeshRate);
}
void LEXLoadGL(void) {
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}
GLFWwindow* LCreateWindow(int Width, int Height, const char* Title, GLFWmonitor* moniter) {
	GLFWwindow* window = glfwCreateWindow(Width, Height, Title, moniter, NULL);
	return window;
}
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>

typedef unsigned int Shader;

static unsigned int new_shader(unsigned int type, const char* src)
{
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);

	//Error Handeling

	int errState = 0;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &errState);
	if (!errState)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errState);
		char* err = (char*)malloc(sizeof(char) * errState);
		glGetShaderInfoLog(shader, errState, &errState, err);
		
		fprintf(stderr, (type == GL_VERTEX_SHADER) ? "\nVERTEX_SHADER_ERROR: %s\n" : "\nFRAGMENT_SHADER_ERROR: %s\n", err);
	}

	return shader;
}

static const char* read_file(const char* path)
{

	char* buffer = NULL;
	long length;
	FILE * f = fopen(path, "rb"); //was "rb"

	if (f)
	{
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);
		buffer = (char*)malloc((length + 1) * sizeof(char));
		if (buffer)
		{
			fread(buffer, sizeof(char), length, f);
		}

		fclose(f);
	}
	else 
	{
		fprintf(stderr, "Error: %s: %s\n", path, strerror(errno));
		#ifdef _DEBUG
		getchar();
		#endif
		exit(-1);
	}
	buffer[length] = '\0';

	return buffer;
}

Shader mk_Shader(const char* vsPath, const char* fsPath) 
{
	Shader self;
	self = glCreateProgram();
	unsigned int vs = new_shader(GL_VERTEX_SHADER, read_file(vsPath));
	unsigned int fs = new_shader(GL_FRAGMENT_SHADER, read_file(fsPath));

	glAttachShader(self, vs);
	glAttachShader(self, fs);

	glLinkProgram(self);
	glValidateProgram(self);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return self;
}

const void ShaderBind(Shader self) 
{
	glUseProgram(self);
}
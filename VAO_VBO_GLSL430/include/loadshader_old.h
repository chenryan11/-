#pragma once
// ---------------------------------------------------------------------------
// LoadShader.h
// Quick and dirty LoadShader function for the OpenGL Programming Guide 4.3
// Red Book.
//
// Author: Qoheleth
// [url]http://www.opengl.org/discussion_boards/showthread.php/180175-Redbook-8th-sample-code?p=1245842#post1245842[/url]
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
 
#include <GL/glew.h>
#include <GL/freeglut.h>
 
struct ShaderInfo {
	GLenum vTarget;
	const char *vShaderFile;
	GLenum fTarget;
	const char *fShaderFile;
};
 
GLuint LoadShaders( ShaderInfo shaderInfo );
const char* getShaderProgram( const char *filePath, string &shaderProgramText );

GLuint LoadShaders( ShaderInfo shaderInfo )
{
	GLuint program;
	GLuint vertexShader;
	GLuint fragmentShader;
	vertexShader   = glCreateShader( GL_VERTEX_SHADER );	// create a vertex shader object
	fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );	// create a fragment shader object
 
	// load and compile vertex shader
	string shaderProgramText;
	const char* text = getShaderProgram( shaderInfo.vShaderFile, shaderProgramText );
	GLint length = shaderProgramText.size();
	glShaderSource( vertexShader, 1, &text, NULL );
	glCompileShader( vertexShader );
 
	for ( int i = 0; i < length; i++ )
	{
		cout << text[ i ];
	}
 
	GLint status;
	glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &status );
 
	if ( !( status == GL_TRUE ) )
		cerr << "\nVertex Shader compilation failed..." << '\n';
 
	char *infoLog = new char[ 100 ];
	GLsizei bufSize = 100;
	glGetShaderInfoLog( vertexShader, bufSize, NULL, infoLog );
	for ( int i = 0; i < bufSize; i++ )
		cout << infoLog[ i ];
	delete [] infoLog;
 
	// load and compile fragment shader
	shaderProgramText = "";
	text = getShaderProgram( shaderInfo.fShaderFile, shaderProgramText );
	glShaderSource( fragmentShader, 1, &text, NULL );
	glCompileShader( fragmentShader );
 
	glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &status );
 
	if ( !( status == GL_TRUE ) )
		cerr << "\nFragment Shader compilation failed..." << '\n';
 
	bufSize = 0;
	infoLog = new char[bufSize];	
	glGetShaderInfoLog( fragmentShader, bufSize, NULL, infoLog );
	for ( int i = 0; i < bufSize; i++ )
		cout << infoLog[ i ] << endl;
	delete [] infoLog;
 
	// create the shader program
	program = glCreateProgram();
 
	// attach the vertex and fragment shaders to the program
	glAttachShader( program, vertexShader );
	glAttachShader( program, fragmentShader );
 
	// link the objects for an executable program
	glLinkProgram( program );
 
	glGetProgramiv( program, GL_LINK_STATUS, &status );
	if ( !( status == GL_TRUE ) )
		cout << "Link failed..." << endl;
 
	// return the program
	return program;
}
 
const char* getShaderProgram( const char *filePath, string &shader )
{
	fstream shaderFile( filePath, ios::in );
 
	if ( shaderFile.is_open() )
	{
		std::stringstream buffer;
		buffer << shaderFile.rdbuf();
		shader = buffer.str();
		buffer.clear();
	}
	shaderFile.close();
 
	return shader.c_str();
}

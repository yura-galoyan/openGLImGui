#include "Shader.hpp"

#include <glad/glad.h>

#include <sstream>
#include <fstream>
#include <iostream>

Shader::Shader(const std::string_view vertexPath,const std::string_view fragmentPath ){
    auto vertexCode = getFileContents(vertexPath);
    auto fragmentCode = getFileContents(fragmentPath);
    auto vId  = compileShader(vertexCode,"vertex");
    auto fId  = compileShader(fragmentCode,"fragment");
    compileShaderProgram(vId, fId);
};

void Shader::use(){ 
    glUseProgram(id);
}  

void Shader::setBool(const std::string &name, bool value) const {         
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value); 
}
void Shader::setInt(const std::string &name, int value) const { 
    glUniform1i(glGetUniformLocation(id, name.c_str()), value); 
}
void Shader::setFloat(const std::string &name, float value) const { 
    glUniform1f(glGetUniformLocation(id, name.c_str()), value); 
}


std::string Shader::getFileContents(const std::string_view path) const{
    std::stringstream buf;
    std::ifstream fin(std::string("resources/") + path.data());
    if(!fin.is_open()){
        fin.close();
        fin.open(std::string("../resources/") + path.data()); 
    }
    buf << fin.rdbuf();
    fin.close();
    return buf.str();
}

void Shader::compileShaderProgram(unsigned int vertexId,unsigned int fragmentId){
    id = glCreateProgram();
    glAttachShader(id, vertexId);
    glAttachShader(id, fragmentId);
    glLinkProgram(id);
    
    int  success;
    char infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
  
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);
};


unsigned int Shader::compileShader(const std::string& code, std::string_view name) const{
    auto shaderCode = code.c_str();
    unsigned int shaderId;
    if(name == "vertex"){
        shaderId = glCreateShader(GL_VERTEX_SHADER);
    }else if(name == "fragment"){
        shaderId = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else{
        std::cout<<"error when creating vertex/fragment shader"<<std::endl;
    }
    glShaderSource( shaderId,1,&shaderCode,NULL );
    glCompileShader(shaderId);

    //this is how you check GLSL errors
    int  success;
    char infoLog[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        std::cout << "ERROR::"<< name <<"::COMPILATION_FAILED" <<infoLog << std::endl;
    }   
    return shaderId; 
}

ShaderBuilder ShaderBuilder::add_vertexCode(std::string_view path){
    vPath = path;
    return *this;
}

ShaderBuilder ShaderBuilder::add_fragmentCode(std::string_view path){
    fPath = path;
    return *this;
}

Shader ShaderBuilder::create(){
    return Shader{vPath, fPath};
}

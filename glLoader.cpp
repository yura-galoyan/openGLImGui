#include "glLoader.hpp"

#include <vector>
#include <iostream>

namespace GlLoader{


DrawingDetails loadMeshIntoGPU(  std::vector<Vertex> pointsPositions,   std::vector<unsigned int> indices){

    unsigned int VAO, VBO, EBO;

    glGenVertexArrays(1, &VAO); 
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO); 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, pointsPositions.size() * sizeof(Vertex), pointsPositions.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),  (const void*)offsetof(Vertex,position) );
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0); 
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    return DrawingDetails{ VAO, indices.size()};  

}

const bool unloadMeshfromGPU( std::vector<DrawingDetails>& objectDetails  ){
    
    for(auto& detail : objectDetails){
        glDeleteBuffers(1, &detail.VAO);
    }

    objectDetails.clear();
    objectDetails.shrink_to_fit();

    return true;
}

unsigned int loadShaders(const char* vertexShaderSource, const char* fragmentShaderSource ){


    std::cout<<vertexShaderSource<<"\n"<<std::endl;
    std::cout<<fragmentShaderSource<<"\n"<<std::endl;

    //init vertex Shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource( vertexShader,1,&vertexShaderSource,NULL );
    glCompileShader(vertexShader);

    //this is how you check GLSL errors
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //init fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    //combine shaders
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog<< std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;

};

}
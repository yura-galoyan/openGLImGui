
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>



#ifndef GLTYPES_HPP
#define GLTYPES_HPP

struct Vertex
{
    Vertex( float x, float y , float z){
        position[0] = x;
        position[1] = y;
        position[2] = z;
    }

    float position[3] = {0.f, 0.f, 0.f};
};

struct DrawingDetails
{
    DrawingDetails(unsigned int VAO_,unsigned int count ){
        VAO = VAO_;
        elementsCount = count; 
    }
    
    unsigned int VAO{};
    unsigned int elementsCount{};   
};


#endif //GLTYPES_HPP

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <fstream> //std::ifstream
#include <iterator> //std::istream_iterator
#include <sstream>

#include "glTypes.hpp"
#include "glLoader.hpp"
#include "GlDrawer.hpp"

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
};

int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    std::vector<DrawingDetails> drawingObjectDetails;
    std::vector<Vertex> vertexesPositions;

    std::vector<unsigned int> indices{0,1,2};
    vertexesPositions.push_back( Vertex{  0.f,   0.5f, 0.0f }   );
    vertexesPositions.push_back( Vertex{ -0.5f, -0.5f, 0.0f }   );
    vertexesPositions.push_back( Vertex{  0.5f, -0.5f, 0.0f }   );

    drawingObjectDetails.push_back( GlLoader::loadMeshIntoGPU(vertexesPositions, indices));

    std::stringstream buf;


    std::ifstream fin("../shaderVertex.frag");
    buf << fin.rdbuf();
    std::string vertexShaderSource = buf.str();
    buf.str("");
    fin.close();
    fin.open("../shaderFragment.frag");
    buf << fin.rdbuf();
    std::string fragmentShaderSource = buf.str();
    fin.close();

    unsigned int shaderProgram = GlLoader::loadShaders(vertexShaderSource.data(), fragmentShaderSource.data() );
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // render loop
    while(!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);
        // rendering commands here
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);


        glDrawer::draw(drawingObjectDetails);



        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    GlLoader::unloadMeshfromGPU(drawingObjectDetails);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}
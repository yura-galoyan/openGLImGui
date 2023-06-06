
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
#include <cmath> //std::sin

#include "Shader.hpp"
#include "glTypes.hpp"
#include "glLoader.hpp"
#include "glDrawer.hpp"

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
};

inline std::string getFileContents(const std::string_view path){

    std::stringstream buf;
    std::ifstream fin(path.data());
    if(!fin.is_open()){
       fin.open(std::string("../") + path.data()); 
    }
    buf << fin.rdbuf();
    fin.close();
    return buf.str();
}

int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (!window){
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

    //imgui stuff

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    std::vector<DrawingDetails> drawingObjectDetails;
    std::vector<Vertex> vertexesPositions;

    std::vector<unsigned int> indices{0,1,2};
    vertexesPositions.push_back( Vertex{  0.f,   0.5f, 0.0f }   );
    vertexesPositions.push_back( Vertex{ -0.5f, -0.5f, 0.0f }   );
    vertexesPositions.push_back( Vertex{  0.5f, -0.5f, 0.0f }   );

    drawingObjectDetails.push_back( GlLoader::loadMeshIntoGPU(vertexesPositions, indices));

    ShaderBuilder shaderBuilder;
    Shader shader1 = shaderBuilder.add_fragmentCode("shaderFragment.fs").add_vertexCode("shaderVertex.vs").create();
    int vertexColorLocation = glGetUniformLocation(shader1.get_id(), "ourColor");
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // render loop


    float rgba[4] = {0};

    while(!glfwWindowShouldClose(window)){
        // input
        processInput(window);
        // rendering commands here
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ColorPicker4("trianglePicker123",rgba);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glUniform4f(vertexColorLocation, rgba[0], rgba[1], rgba[2],rgba[3]);

        shader1.use();
        glDrawer::draw(drawingObjectDetails);

        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    GlLoader::unloadMeshfromGPU(drawingObjectDetails);
    glDeleteProgram(shader1.get_id());

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}
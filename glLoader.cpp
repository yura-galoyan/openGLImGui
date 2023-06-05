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


}
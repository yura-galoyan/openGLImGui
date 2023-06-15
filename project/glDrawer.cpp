#include "glDrawer.hpp"

void glDrawer::draw(const std::vector<DrawingDetails>& objectDetails){
    for(const auto& detail: objectDetails){
        glBindVertexArray(detail.VAO);
        glDrawElements(  GL_TRIANGLES, detail.elementsCount, GL_UNSIGNED_INT, nullptr );
    }
    glBindVertexArray(0);
}
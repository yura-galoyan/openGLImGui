#include "glTypes.hpp"
#include <vector>
#include <string_view>

namespace GlLoader{
    DrawingDetails loadMeshIntoGPU(  std::vector<Vertex> pointsPositions,   std::vector<unsigned int> indices);
    const bool unloadMeshfromGPU( std::vector<DrawingDetails>& objectDetails  );
    unsigned int loadShaders(const char* vertexShaderSource, const char* fragmentShaderSource );
}   
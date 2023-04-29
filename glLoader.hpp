#include "glTypes.hpp"
#include <vector>


namespace GlLoader{
    DrawingDetails loadMeshIntoGPU(  std::vector<Vertex> pointsPositions,   std::vector<unsigned int> indices);
    const bool unloadMeshfromGPU( std::vector<DrawingDetails>& objectDetails  );
};
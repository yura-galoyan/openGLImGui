#include "glTypes.hpp"



namespace GlLoader{
    const DrawingDetails loadMeshIntoGPU(  std::vector<Vertex> pointsPositions,   std::vector<unsigned int> indices);
    const bool unloadMeshfromGPU( std::vector<DrawingDetails>& objectDetails  );
};
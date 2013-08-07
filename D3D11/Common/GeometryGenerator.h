//////////////////////////////////////////////////////////////////////////
//
// Generate shapes procedurally
//
//
// All triangles are generated "outward" facing.  If you want "inward" 
// facing triangles (for example, if you want to place the camera inside
// a sphere to simulate a sky), you will need to:
//   1. Change the Direct3D cull mode or manually reverse the winding order.
//   2. Invert the normal.
//   3. Update the texture coordinates and tangent vectors.
//////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <DirectXMath.h>
#include <vector>

struct BoundingSphere
{
    BoundingSphere() 
        : mCenter(0.0f, 0.0f, 0.0f)
        , mRadius(0.0f) 
    {

    }

    DirectX::XMFLOAT3 mCenter;
    float mRadius;
};

struct VertexData
{
    VertexData() 
        : mPosition(0.0f, 0.0f, 0.0f)
        , mNormal(0.0f, 0.0f, 0.0f)
        , mTangentU(0.0f, 0.0f, 0.0f)
        , mTexCoord(0.0f, 0.0f)
    {

    }

    VertexData(const DirectX::XMFLOAT3& position, 
               const DirectX::XMFLOAT3& normal, 
               const DirectX::XMFLOAT3& tangentU, 
               const DirectX::XMFLOAT2& texCoord)
        : mPosition(position)
        , mNormal(normal)
        , mTangentU(tangentU)
        , mTexCoord(texCoord)
    {

    }

    VertexData(const float positionX, 
               const float positionY, 
               const float positionZ,
               const float normalX, 
               const float normalY, 
               const float normalZ,
               const float tangentUx, 
               const float tangentUy, 
               const float tangentUz,
               const float texCoordU, 
               const float texCoordV)
        : mPosition(positionX, positionY, positionZ)
        , mNormal(normalX, normalY, normalZ)
        , mTangentU(tangentUx, tangentUy, tangentUz)
        , mTexCoord(texCoordU, texCoordV)
    {
    }

    DirectX::XMFLOAT3 mPosition;
    DirectX::XMFLOAT3 mNormal;
    DirectX::XMFLOAT3 mTangentU;
    DirectX::XMFLOAT2 mTexCoord;
};

struct MeshData
{
    std::vector<VertexData> mVertices;
    std::vector<uint32_t> mIndices;
};

namespace GeometryGenerator
{
    // Creates a box centered at the origin with the given dimensions.
    void generateBox(const float width, 
                     const float height, 
                     const float depth, 
                     MeshData& meshData);

    // Creates a sphere centered at the origin with the given radius. 
    // The slices and stacks parameters control the degree of tessellation.
    void generateSphere(const float radius, 
                        const uint32_t sliceCount, 
                        const uint32_t stackCount, 
                        MeshData& meshData);

    // Creates a geosphere centered at the origin with the given radius.  
    // The depth controls the level of tessellation.
    void generateGeosphere(const float radius, 
                           const uint32_t numSubdivisions, 
                           MeshData& meshData);

    // Creates a cylinder parallel to the y-axis, and centered about the origin.  
    // The bottom and top radius can vary to form various cone shapes rather than true
    // cylinders. The slices and stacks parameters control the degree of tessellation.
    void generateCylinder(const float bottomRadius, 
                          const float topRadius, 
                          const float height, 
                          const uint32_t sliceCount, 
                          const uint32_t stackCount, 
                          MeshData& meshData);

    // Creates an mxn grid in the xz-plane with numRows rows and numRows columns, 
    // centered at the origin with the specified width and depth.
    void generateGrid(const float width, 
                      const float depth, 
                      const uint32_t numRows, 
                      const uint32_t numColumns, 
                      MeshData& meshData);

    // Creates an mxn grid in the xz-plane with numRows rows and numRows columns, 
    // centered at the origin with the specified width and depth.
    void generateGridForInterlockingTiles(const float width, 
                                          const float depth, 
                                          const uint32_t numRows, 
                                          const uint32_t numColumns, 
                                          MeshData& meshData);

    // Creates a quad covering the screen in NDC coordinates.  
    // This is useful for postprocessing effects.
    void generateFullscreenQuad(MeshData& meshData);
}

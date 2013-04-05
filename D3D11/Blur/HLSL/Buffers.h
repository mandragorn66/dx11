#pragma once

#include <DirectXMath.h>

#include <LightHelper.h>

namespace Shaders
{
    struct LandPerFrameBuffer
    {
        DirectionalLight mDirectionalLight;
        SpotLight mSpotLight;
        DirectX::XMFLOAT3 mEyePositionW;
    };

    struct LandPerObjectBuffer
    {
        DirectX::XMFLOAT4X4 mWorld;
        DirectX::XMFLOAT4X4 mWorldInverseTranspose;
        DirectX::XMFLOAT4X4 mWorldViewProjection;
        DirectX::XMFLOAT4X4 mTexTransform;
        Material mMaterial;
    };

    struct ScreenQuadVSPerFrameBuffer
    {
        DirectX::XMFLOAT4X4 mWorldInverseTranspose;
        DirectX::XMFLOAT4X4 mWorldViewProjection;
        DirectX::XMFLOAT4X4 mTexTransform;
    };
}
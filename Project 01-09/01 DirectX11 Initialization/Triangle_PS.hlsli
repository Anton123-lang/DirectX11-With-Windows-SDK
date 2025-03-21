#include "Triangle.hlsli"

// 像素着色器
float4 PS(VertexOut pIn) : SV_Target
{
    return pIn.color;   
}

// 将顶点颜色输出到屏幕上
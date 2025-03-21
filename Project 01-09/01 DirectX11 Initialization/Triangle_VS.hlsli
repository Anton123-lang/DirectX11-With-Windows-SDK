#include "Triangle.hlsli"

// 顶点着色器
VertexOut VS(VertexIn vIn)
{
    VertexOut vOut;
    vOut.posH = float4(vIn.pos, 1.0f);
    vOut.color = vIn.color; // 这里alpha通道的值默认为1.0
    return vOut;
}

//将顶点位置从模型空间转换到裁剪空间，并将颜色传递给像素着色器
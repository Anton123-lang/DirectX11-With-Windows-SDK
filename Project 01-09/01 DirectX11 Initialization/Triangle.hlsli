// Triangle.hlsli

struct VertexIn
{
    float3 pos : POSITION;
    float4 color : COLOR;
};

struct VertexOut
{
    float4 posH : SV_POSITION;
    float4 color : COLOR;
};

//定义了顶点着色器的输入和输出
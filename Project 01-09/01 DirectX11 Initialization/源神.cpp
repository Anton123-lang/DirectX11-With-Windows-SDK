#include <directxmath.h>

struct VertexPosColor
{
    DirectX::XMFLOAT3 pos;
    DirectX::XMFLOAT4 color;
    static const D3D11_INPUT_ELEMENT_DESC inputLayout[2];
};

typedef struct D3D11_INPUT_ELEMENT_DESC
{
    LPCSTR SemanticName;        // 语义名
    UINT SemanticIndex;         // 语义索引
    DXGI_FORMAT Format;         // 数据格式
    UINT InputSlot;             // 输入槽索引(0-15)
    UINT AlignedByteOffset;     // 初始位置(字节偏移量)      
    D3D11_INPUT_CLASSIFICATION InputSlotClass; // 输入类型
    UINT InstanceDataStepRate;  // 忽略
}     D3D11_INPUT_ELEMENT_DESC;

const D3D11_INPUT_ELEMENT_DESC VertexPosColor::inputLayout[2] = {
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
};

HRESULT ID3D11Device::CreateInputLayout(
    const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, // [In]输入布局描述
    UINT NumElements,                                   // [In]上述数组元素个数
    const void* pShaderBytecodeWithInputSignature,      // [In]顶点着色器字节码
    SIZE_T BytecodeLength,                              // [In]顶点着色器字节码长度
    ID3D11InputLayout** ppInputLayout);                 // [Out]获取的输入布局

void ID3D11DeviceContext::IASetInputLayout(
    ID3D11InputLayout* pInputLayout);   // [In]输入布局
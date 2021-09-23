//
// Created by fordchen on 2021/9/14.
//

#include "VertexBuffer.h"
#include <QDebug>

CFENGINE_RENDER_START
VertexBuffer::VertexBuffer(std::vector<float>& vertices, std::shared_ptr<VertexLayout> layout): GLResource(){
    glGenBuffers(1, &handle_);
    glBindBuffer(GL_ARRAY_BUFFER, handle_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    auto stride = layout->m_stride;
    for(int i = 0; i < layout->m_attribute.size(); i++){
        auto info = layout->m_attribute[i];
        glVertexAttribPointer(i, info.num, info.type, GL_FALSE, stride * info.typeSize, (void*)(info.offset * info.typeSize));
        glEnableVertexAttribArray(i);
    }

    std::cout << "----------VertexBuffer()--" << handle_ << std::endl;
}

VertexBuffer::~VertexBuffer() {
    std::cout << "~VertexBuffer()--" << handle_ << std::endl;
    glDeleteBuffers(1, &handle_);
}
CFENGINE_RENDER_END

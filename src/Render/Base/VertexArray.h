//
// Created by fordchen on 2021/9/14.
//

#ifndef CFRENDERENGINE_VERTEXARRAY_H
#define CFRENDERENGINE_VERTEXARRAY_H

#include <memory>

#include "GLResource.h"

namespace render{

class VertexBuffer;
class IndexBuffer;

class VertexArray : public GLResource{
public:
    VertexArray();

    void use();
    void bindVertexBuffer(std::shared_ptr<VertexBuffer> vertexBuffer);
    void bindIndexBuffer(std::shared_ptr<IndexBuffer> indexBuffer);

    ~VertexArray();

    unsigned int vertexCount();

    std::string id_;

private:
    std::shared_ptr<VertexBuffer> vbo_;
    std::shared_ptr<IndexBuffer> ibo_;

};

}
#endif //CFRENDERENGINE_VERTEXARRAY_H

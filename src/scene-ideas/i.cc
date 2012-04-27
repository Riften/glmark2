#include "characters.h"

using LibMatrix::vec2;

LetterI::LetterI()
{
    // Vertex data...
    vertexData_.push_back(vec2(0.548767, 9.414791));
    vertexData_.push_back(vec2(2.795284, 9.757771));
    vertexData_.push_back(vec2(1.457663, 9.311897));
    vertexData_.push_back(vec2(2.503751, 9.157557));
    vertexData_.push_back(vec2(1.714898, 8.986067));
    vertexData_.push_back(vec2(2.109325, 7.785638));
    vertexData_.push_back(vec2(1.286174, 7.013934));
    vertexData_.push_back(vec2(1.800643, 6.070740));
    vertexData_.push_back(vec2(0.994641, 5.161843));
    vertexData_.push_back(vec2(1.783494, 4.767417));
    vertexData_.push_back(vec2(0.943194, 4.167202));
    vertexData_.push_back(vec2(1.852090, 4.304394));
    vertexData_.push_back(vec2(1.063237, 3.549839));
    vertexData_.push_back(vec2(2.023580, 3.978564));
    vertexData_.push_back(vec2(1.406217, 3.172562));
    vertexData_.push_back(vec2(2.315113, 3.875670));
    vertexData_.push_back(vec2(2.006431, 3.018221));
    vertexData_.push_back(vec2(2.812433, 3.944266));
    vertexData_.push_back(vec2(2.726688, 3.429796));
    vertexData_.push_back(vec2(3.258307, 4.132905));
    vertexData_.push_back(vec2(1.989282, 10.923902));
    vertexData_.push_back(vec2(2.778135, 12.295820));
    vertexData_.push_back(vec2(2.966774, 11.678456));
    vertexData_.push_back(vec2(3.687031, 12.947481));

    // Index data...
    indexData_.push_back(0);
    indexData_.push_back(1);
    indexData_.push_back(2);
    indexData_.push_back(3);
    indexData_.push_back(4);
    indexData_.push_back(5);
    indexData_.push_back(6);
    indexData_.push_back(7);
    indexData_.push_back(8);
    indexData_.push_back(9);
    indexData_.push_back(10);
    indexData_.push_back(11);
    indexData_.push_back(12);
    indexData_.push_back(13);
    indexData_.push_back(14);
    indexData_.push_back(15);
    indexData_.push_back(16);
    indexData_.push_back(17);
    indexData_.push_back(18);
    indexData_.push_back(19);
    indexData_.push_back(20);
    indexData_.push_back(21);
    indexData_.push_back(22);
    indexData_.push_back(23);
    indexData_.push_back(0);
    indexData_.push_back(2);
    indexData_.push_back(4);
    indexData_.push_back(6);
    indexData_.push_back(8);
    indexData_.push_back(10);
    indexData_.push_back(12);
    indexData_.push_back(14);
    indexData_.push_back(16);
    indexData_.push_back(18);
    indexData_.push_back(19);
    indexData_.push_back(17);
    indexData_.push_back(15);
    indexData_.push_back(13);
    indexData_.push_back(11);
    indexData_.push_back(9);
    indexData_.push_back(7);
    indexData_.push_back(5);
    indexData_.push_back(3);
    indexData_.push_back(1);
    indexData_.push_back(20);
    indexData_.push_back(22);
    indexData_.push_back(23);
    indexData_.push_back(21);

    // Primitive state so that the draw call can issue the primitives we want.
    unsigned int curOffset(0);
    primVec_.push_back(PrimitiveState(GL_TRIANGLE_STRIP, 20, curOffset));
    curOffset += (20 * sizeof(unsigned int));
    primVec_.push_back(PrimitiveState(GL_TRIANGLE_STRIP, 4, curOffset));
    curOffset += (4 * sizeof(unsigned int));
    primVec_.push_back(PrimitiveState(GL_TRIANGLE_STRIP, 20, curOffset));
    curOffset += (20 * sizeof(unsigned int));
    primVec_.push_back(PrimitiveState(GL_TRIANGLE_STRIP, 4, curOffset));
}

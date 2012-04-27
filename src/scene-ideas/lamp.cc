#include "lamp.h"
#include "shader-source.h"
#include "log.h"
#include "scene.h"

using std::string;
using LibMatrix::vec3;
using LibMatrix::vec4;
using LibMatrix::Stack4;

const string Lamp::modelviewName_("modelview");
const string Lamp::projectionName_("projection");
const string Lamp::light0PositionName_("light0Position");
const string Lamp::light1PositionName_("light1Position");
const string Lamp::light2PositionName_("light2Position");
const string Lamp::vertexAttribName_("vertex");
const string Lamp::normalAttribName_("normal");

Lamp::Lamp() :
    valid_(false)
{
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.000000, 0.000000, 1.000000));
    vertexData_.push_back(vec3(0.438371, 0.000000, 0.898794));
    vertexData_.push_back(vec3(0.379641, 0.219186, 0.898794));
    vertexData_.push_back(vec3(0.219186, 0.379641, 0.898794));
    vertexData_.push_back(vec3(0.000000, 0.438371, 0.898794));
    vertexData_.push_back(vec3(-0.219186, 0.379641, 0.898794));
    vertexData_.push_back(vec3(-0.379641, 0.219186, 0.898794));
    vertexData_.push_back(vec3(-0.438371, 0.000000, 0.898794));
    vertexData_.push_back(vec3(-0.379641, -0.219186, 0.898794));
    vertexData_.push_back(vec3(-0.219186, -0.379641, 0.898794));
    vertexData_.push_back(vec3(0.000000, -0.438371, 0.898794));
    vertexData_.push_back(vec3(0.219186, -0.379641, 0.898794));
    vertexData_.push_back(vec3(0.379641, -0.219186, 0.898794));
    vertexData_.push_back(vec3(0.438371, 0.000000, 0.898794));
    vertexData_.push_back(vec3(0.788011, 0.000000, 0.615662));
    vertexData_.push_back(vec3(0.682437, 0.394005, 0.615662));
    vertexData_.push_back(vec3(0.394005, 0.682437, 0.615662));
    vertexData_.push_back(vec3(0.000000, 0.788011, 0.615662));
    vertexData_.push_back(vec3(-0.394005, 0.682437, 0.615662));
    vertexData_.push_back(vec3(-0.682437, 0.394005, 0.615662));
    vertexData_.push_back(vec3(-0.788011, 0.000000, 0.615662));
    vertexData_.push_back(vec3(-0.682437, -0.394005, 0.615662));
    vertexData_.push_back(vec3(-0.394005, -0.682437, 0.615662));
    vertexData_.push_back(vec3(0.000000, -0.788011, 0.615662));
    vertexData_.push_back(vec3(0.394005, -0.682437, 0.615662));
    vertexData_.push_back(vec3(0.682437, -0.394005, 0.615662));
    vertexData_.push_back(vec3(0.788011, 0.000000, 0.615662));
    vertexData_.push_back(vec3(0.978148, 0.000000, 0.207912));
    vertexData_.push_back(vec3(0.847101, 0.489074, 0.207912));
    vertexData_.push_back(vec3(0.489074, 0.847101, 0.207912));
    vertexData_.push_back(vec3(0.000000, 0.978148, 0.207912));
    vertexData_.push_back(vec3(-0.489074, 0.847101, 0.207912));
    vertexData_.push_back(vec3(-0.847101, 0.489074, 0.207912));
    vertexData_.push_back(vec3(-0.978148, 0.000000, 0.207912));
    vertexData_.push_back(vec3(-0.847101, -0.489074, 0.207912));
    vertexData_.push_back(vec3(-0.489074, -0.847101, 0.207912));
    vertexData_.push_back(vec3(0.000000, -0.978148, 0.207912));
    vertexData_.push_back(vec3(0.489074, -0.847101, 0.207912));
    vertexData_.push_back(vec3(0.847101, -0.489074, 0.207912));
    vertexData_.push_back(vec3(0.978148, 0.000000, 0.207912));
    vertexData_.push_back(vec3(0.970296, 0.000000, -0.241922));
    vertexData_.push_back(vec3(0.840301, 0.485148, -0.241922));
    vertexData_.push_back(vec3(0.485148, 0.840301, -0.241922));
    vertexData_.push_back(vec3(0.000000, 0.970296, -0.241922));
    vertexData_.push_back(vec3(-0.485148, 0.840301, -0.241922));
    vertexData_.push_back(vec3(-0.840301, 0.485148, -0.241922));
    vertexData_.push_back(vec3(-0.970296, 0.000000, -0.241922));
    vertexData_.push_back(vec3(-0.840301, -0.485148, -0.241922));
    vertexData_.push_back(vec3(-0.485148, -0.840301, -0.241922));
    vertexData_.push_back(vec3(0.000000, -0.970296, -0.241922));
    vertexData_.push_back(vec3(0.485148, -0.840301, -0.241922));
    vertexData_.push_back(vec3(0.840301, -0.485148, -0.241922));
    vertexData_.push_back(vec3(0.970296, 0.000000, -0.241922));
    vertexData_.push_back(vec3(0.766044, 0.000000, -0.642788));
    vertexData_.push_back(vec3(0.663414, 0.383022, -0.642788));
    vertexData_.push_back(vec3(0.383022, 0.663414, -0.642788));
    vertexData_.push_back(vec3(0.000000, 0.766044, -0.642788));
    vertexData_.push_back(vec3(-0.383022, 0.663414, -0.642788));
    vertexData_.push_back(vec3(-0.663414, 0.383022, -0.642788));
    vertexData_.push_back(vec3(-0.766044, 0.000000, -0.642788));
    vertexData_.push_back(vec3(-0.663414, -0.383022, -0.642788));
    vertexData_.push_back(vec3(-0.383022, -0.663414, -0.642788));
    vertexData_.push_back(vec3(0.000000, -0.766044, -0.642788));
    vertexData_.push_back(vec3(0.383022, -0.663414, -0.642788));
    vertexData_.push_back(vec3(0.663414, -0.383022, -0.642788));
    vertexData_.push_back(vec3(0.766044, 0.000000, -0.642788));

    //
    // The original implementation of both the logo and the lamp represented
    // the vertex and normal data in a triply-dimensioned array of floats and
    // all of the calls referenced double-indexed arrays of vector data.
    // To my mind, this made the code look clunky and overly verbose.
    // Representing the data as a STL vector of vec3 (itself a 3-float vector
    // quantity) provides both an efficient container and allows for more
    // concise looking code.  The slightly goofy loops (using the original 2
    // dimensional indices to compute a single offset into the STL vector) are 
    // a compromise to avoid rearranging the original data.
    //
    // - jesse 2010/10/04
    //
    for (unsigned int i = 0; i < 5; i++)
    {
        for (unsigned int j = 0; j < 13; j++)
        {
            indexData_.push_back(i * 13 + j);
            indexData_.push_back((i + 1) * 13 + j);
        }
    }
    unsigned int curIndex(5 * 13);
    for (unsigned int i = 0; i < 12; i++)
    {
        indexData_.push_back(curIndex + i);
    }
}

Lamp::~Lamp()
{
    if (valid_)
    {
        glDeleteBuffers(2, &bufferObjects_[0]);
    }
}

void
Lamp::init()
{
    // Make sure we don't re-initialize...
    if (valid_)
    {
        return;
    }

    // Initialize shader sources from input files and create programs from them
    // The program for handling lighting...
    string lit_vtx_filename(GLMARK_DATA_PATH"/shaders/lamp-lit.vert");
    string lit_frg_filename(GLMARK_DATA_PATH"/shaders/lamp-lit.frag");
    ShaderSource lit_vtx_source(lit_vtx_filename);
    ShaderSource lit_frg_source(lit_frg_filename);
    if (!Scene::load_shaders_from_strings(litProgram_, lit_vtx_source.str(),
                                          lit_frg_source.str()))
    {
        Log::error("No valid program for lit lamp rendering\n");
        return;
    }

    // The simple program with no lighting...
    string unlit_vtx_filename(GLMARK_DATA_PATH"/shaders/lamp-unlit.vert");
    string unlit_frg_filename(GLMARK_DATA_PATH"/shaders/lamp-unlit.frag");
    ShaderSource unlit_vtx_source(unlit_vtx_filename);
    ShaderSource unlit_frg_source(unlit_frg_filename);
    if (!Scene::load_shaders_from_strings(unlitProgram_, unlit_vtx_source.str(),
                                          unlit_frg_source.str()))
    {
        Log::error("No valid program for unlit lamp rendering.\n");
        return;
    }

    // We need 2 buffers for our work here.  One for the vertex data.
    // and one for the index data.
    glGenBuffers(2, &bufferObjects_[0]);

    // First, setup the vertex data by binding the first buffer object, 
    // allocating its data store, and filling it in with our vertex data.
    glBindBuffer(GL_ARRAY_BUFFER, bufferObjects_[0]);
    glBufferData(GL_ARRAY_BUFFER, vertexData_.size() * sizeof(vec3), vertexData_.data(), GL_STATIC_DRAW);

    // Now repeat for our index data.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObjects_[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexData_.size() * sizeof(unsigned int), indexData_.data(), GL_STATIC_DRAW);

    // We're ready to go.
    valid_ = true;
}

void
Lamp::draw(Stack4& modelview, Stack4& projection, const vec4* lightPositions)
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferObjects_[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObjects_[1]);

    litProgram_.start();
    int vertexIndex(litProgram_[vertexAttribName_].location());
    int normalIndex(litProgram_[normalAttribName_].location());
    glVertexAttribPointer(vertexIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glVertexAttribPointer(normalIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexIndex);
    glEnableVertexAttribArray(normalIndex);
    litProgram_[modelviewName_] = modelview.getCurrent();
    litProgram_[projectionName_] = projection.getCurrent();
    litProgram_[light0PositionName_] = lightPositions[0];
    litProgram_[light1PositionName_] = lightPositions[1];
    litProgram_[light2PositionName_] = lightPositions[2];
    static const unsigned int sui(sizeof(unsigned int));
    for (unsigned int i = 0; i < 5; i++)
    {
        glDrawElements(GL_TRIANGLE_STRIP, 26, GL_UNSIGNED_INT, reinterpret_cast<const GLvoid*>(i * 26 * sui));
    }
    glDisableVertexAttribArray(normalIndex);
    glDisableVertexAttribArray(vertexIndex);
    litProgram_.stop();

    unlitProgram_.start();
    vertexIndex = unlitProgram_[vertexAttribName_].location();
    glVertexAttribPointer(vertexIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexIndex);
    unlitProgram_[modelviewName_] = modelview.getCurrent();
    unlitProgram_[projectionName_] = projection.getCurrent();
    // FIXME - replacing a GL_POLYGON with a GL_TRIANGLE_STRIP won't work, but
    //         I need it to build first.
    glDrawElements(GL_TRIANGLE_STRIP, 12, GL_UNSIGNED_INT, reinterpret_cast<const GLvoid*>(5 * 26 * sui));
    glDisableVertexAttribArray(vertexIndex);
    unlitProgram_.stop();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

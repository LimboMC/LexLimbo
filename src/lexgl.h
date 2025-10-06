#include<glad/glad.h>
#ifndef LEX_LIMBO_OPENGL
#define LEX_LIMBO_OPENGL
#define LEX_TEXTURE_WRAP_S                       0x2802      // GL_TEXTURE_WRAP_S
#define LEX_TEXTURE_WRAP_T                       0x2803      // GL_TEXTURE_WRAP_T
#define LEX_TEXTURE_MAG_FILTER                   0x2800      // GL_TEXTURE_MAG_FILTER
#define LEX_TEXTURE_MIN_FILTER                   0x2801      // GL_TEXTURE_MIN_FILTER

#define LEX_TEXTURE_FILTER_NEAREST               0x2600      // GL_NEAREST
#define LEX_TEXTURE_FILTER_LINEAR                0x2601      // GL_LINEAR
#define LEX_TEXTURE_FILTER_MIP_NEAREST           0x2700      // GL_NEAREST_MIPMAP_NEAREST
#define LEX_TEXTURE_FILTER_NEAREST_MIP_LINEAR    0x2702      // GL_NEAREST_MIPMAP_LINEAR
#define LEX_TEXTURE_FILTER_LINEAR_MIP_NEAREST    0x2701      // GL_LINEAR_MIPMAP_NEAREST
#define LEX_TEXTURE_FILTER_MIP_LINEAR            0x2703      // GL_LINEAR_MIPMAP_LINEAR
#define LEX_TEXTURE_FILTER_ANISOTROPIC           0x3000      // Anisotropic filter (custom identifier)
#define LEX_TEXTURE_MIPMAP_BIAS_RATIO            0x4000      // Texture mipmap bias, percentage ratio (custom identifier)

#define LEX_TEXTURE_WRAP_REPEAT                  0x2901      // GL_REPEAT
#define LEX_TEXTURE_WRAP_CLAMP                   0x812F      // GL_CLAMP_TO_EDGE
#define LEX_TEXTURE_WRAP_MIRROR_REPEAT           0x8370      // GL_MIRRORED_REPEAT
#define LEX_TEXTURE_WRAP_MIRROR_CLAMP            0x8742      // GL_MIRROR_CLAMP_EXT

// Matrix modes (equivalent to OpenGL)
#define LEX_MODELVIEW                            0x1700      // GL_MODELVIEW
#define LEX_PROJECTION                           0x1701      // GL_PROJECTION
#define LEX_TEXTURE                              0x1702      // GL_TEXTURE

// Primitive assembly draw modes
#define LEX_LINES                                0x0001      // GL_LINES
#define LEX_TRIANGLES                            0x0004      // GL_TRIANGLES
#define LEX_QUADS                                0x0007      // GL_QUADS

// GL equivalent data types
#define LEX_UNSIGNED_BYTE                        0x1401      // GL_UNSIGNED_BYTE
#define LEX_FLOAT                                0x1406      // GL_FLOAT
#define LEX_INT                                  0x1404      // GL_INT
#define LEX_SHORT                                0x1402      // GL_SHORT
#define LEX_DOUBLE                               0x140A      // GL_DOUBLE
#define LEX_BYTE                                 0x1400      // GL_BYTE
#define LEX_UNSIGNED_SHORT                       0x1403      // GL_UNSIGNED_SHORT
#define LEX_UNSIGNED_INT                         0x1405      // GL_UNSIGNED_INT
#define LEX_TRUE                                 1           // GL_TRUE
#define LEX_FALSE                                0           // GL_FALSE
#define LEX_UNSIGNED_INT                         0x1405      // GL_UNSIGNED_INT
// GL buffer usage hint
#define LEX_STREAM_DRAW                          0x88E0      // GL_STREAM_DRAW
#define LEX_STREAM_READ                          0x88E1      // GL_STREAM_READ
#define LEX_STREAM_COPY                          0x88E2      // GL_STREAM_COPY
#define LEX_STATIC_DRAW                          0x88E4      // GL_STATIC_DRAW
#define LEX_STATIC_READ                          0x88E5      // GL_STATIC_READ
#define LEX_STATIC_COPY                          0x88E6      // GL_STATIC_COPY
#define LEX_DYNAMIC_DRAW                         0x88E8      // GL_DYNAMIC_DRAW
#define LEX_DYNAMIC_READ                         0x88E9      // GL_DYNAMIC_READ
#define LEX_DYNAMIC_COPY                         0x88EA      // GL_DYNAMIC_COPY

// GL Shader type
#define LEX_FRAGMENT_SHADER                      0x8B30      // GL_FRAGMENT_SHADER
#define LEX_VERTEX_SHADER                        0x8B31      // GL_VERTEX_SHADER
#define LEX_COMPUTE_SHADER                       0x91B9      // GL_COMPUTE_SHADER

// GL blending factors
#define LEX_ZERO                                 0           // GL_ZERO
#define LEX_ONE                                  1           // GL_ONE
#define LEX_SRC_COLOR                            0x0300      // GL_SRC_COLOR
#define LEX_ONE_MINUS_SRC_COLOR                  0x0301      // GL_ONE_MINUS_SRC_COLOR
#define LEX_SRC_ALPHA                            0x0302      // GL_SRC_ALPHA
#define LEX_ONE_MINUS_SRC_ALPHA                  0x0303      // GL_ONE_MINUS_SRC_ALPHA
#define LEX_DST_ALPHA                            0x0304      // GL_DST_ALPHA
#define LEX_ONE_MINUS_DST_ALPHA                  0x0305      // GL_ONE_MINUS_DST_ALPHA
#define LEX_DST_COLOR                            0x0306      // GL_DST_COLOR
#define LEX_ONE_MINUS_DST_COLOR                  0x0307      // GL_ONE_MINUS_DST_COLOR
#define LEX_SRC_ALPHA_SATURATE                   0x0308      // GL_SRC_ALPHA_SATURATE
#define LEX_CONSTANT_COLOR                       0x8001      // GL_CONSTANT_COLOR
#define LEX_ONE_MINUS_CONSTANT_COLOR             0x8002      // GL_ONE_MINUS_CONSTANT_COLOR
#define LEX_CONSTANT_ALPHA                       0x8003      // GL_CONSTANT_ALPHA
#define LEX_ONE_MINUS_CONSTANT_ALPHA             0x8004      // GL_ONE_MINUS_CONSTANT_ALPHA

// GL blending functions/equations
#define LEX_FUNC_ADD                             0x8006      // GL_FUNC_ADD
#define LEX_MIN                                  0x8007      // GL_MIN
#define LEX_MAX                                  0x8008      // GL_MAX
#define LEX_FUNC_SUBTRACT                        0x800A      // GL_FUNC_SUBTRACT
#define LEX_FUNC_REVERSE_SUBTRACT                0x800B      // GL_FUNC_REVERSE_SUBTRACT
#define LEX_BLEND_EQUATION                       0x8009      // GL_BLEND_EQUATION
#define LEX_BLEND_EQUATION_RGB                   0x8009      // GL_BLEND_EQUATION_RGB   // (Same as BLEND_EQUATION)
#define LEX_BLEND_EQUATION_ALPHA                 0x883D      // GL_BLEND_EQUATION_ALPHA
#define LEX_BLEND_DST_RGB                        0x80C8      // GL_BLEND_DST_RGB
#define LEX_BLEND_SRC_RGB                        0x80C9      // GL_BLEND_SRC_RGB
#define LEX_BLEND_DST_ALPHA                      0x80CA      // GL_BLEND_DST_ALPHA
#define LEX_BLEND_SRC_ALPHA                      0x80CB      // GL_BLEND_SRC_ALPHA
#define LEX_BLEND_COLOR                          0x8005      // GL_BLEND_COLOR
#define LEX_READ_FRAMEBUFFER                     0x8CA8      // GL_READ_FRAMEBUFFER
#define LEX_DRAW_FRAMEBUFFER                     0x8CA9      // GL_DRAW_FRAMEBUFFER
//GL Vertex
#define LEX_ARRAY_BUFFER                         0x8892
#define LEX_ELEMENT_ARRAY_BUFFER                 0x8893
//
#define LEX_UNBIND                               0x9999     // Unbind all buffers and arrays

#endif // !LEX_LIMBO_OPENGL
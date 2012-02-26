#include "stdafx.h"

#include "LuaGLES2_util.h"

static const lualgesConst luagles_const[] = {
/* ClearBufferMask */
 { GL_DEPTH_BUFFER_BIT, "GL_DEPTH_BUFFER_BIT" },               
 { GL_STENCIL_BUFFER_BIT, "GL_STENCIL_BUFFER_BIT" },             
 { GL_COLOR_BUFFER_BIT, "GL_COLOR_BUFFER_BIT" },               

/* Boolean */
 { GL_FALSE, "GL_FALSE" },                          
 { GL_TRUE, "GL_TRUE" },                           

/* BeginMode */
 { GL_POINTS, "GL_POINTS" },                         
 { GL_LINES, "GL_LINES" },                          
 { GL_LINE_LOOP, "GL_LINE_LOOP" },                      
 { GL_LINE_STRIP, "GL_LINE_STRIP" },                     
 { GL_TRIANGLES, "GL_TRIANGLES" },                      
 { GL_TRIANGLE_STRIP, "GL_TRIANGLE_STRIP" },                 
 { GL_TRIANGLE_FAN, "GL_TRIANGLE_FAN" },                   

/* AlphaFunction (not supported in ES20) */
/*      { GL_NEVER, "GL_NEVER" }, */
/*      { GL_LESS, "GL_LESS" }, */
/*      { GL_EQUAL, "GL_EQUAL" }, */
/*      { GL_LEQUAL, "GL_LEQUAL" }, */
/*      { GL_GREATER, "GL_GREATER" }, */
/*      { GL_NOTEQUAL, "GL_NOTEQUAL" }, */
/*      { GL_GEQUAL, "GL_GEQUAL" }, */
/*      { GL_ALWAYS, "GL_ALWAYS" }, */

/* BlendingFactorDest */
 { GL_ZERO, "GL_ZERO" },                           
 { GL_ONE, "GL_ONE" },                            
 { GL_SRC_COLOR, "GL_SRC_COLOR" },                      
 { GL_ONE_MINUS_SRC_COLOR, "GL_ONE_MINUS_SRC_COLOR" },            
 { GL_SRC_ALPHA, "GL_SRC_ALPHA" },                      
 { GL_ONE_MINUS_SRC_ALPHA, "GL_ONE_MINUS_SRC_ALPHA" },            
 { GL_DST_ALPHA, "GL_DST_ALPHA" },                      
 { GL_ONE_MINUS_DST_ALPHA, "GL_ONE_MINUS_DST_ALPHA" },            

/* BlendingFactorSrc */
/*      { GL_ZERO, "GL_ZERO" }, */
/*      { GL_ONE, "GL_ONE" }, */
 { GL_DST_COLOR, "GL_DST_COLOR" },                      
 { GL_ONE_MINUS_DST_COLOR, "GL_ONE_MINUS_DST_COLOR" },            
 { GL_SRC_ALPHA_SATURATE, "GL_SRC_ALPHA_SATURATE" },             
/*      { GL_SRC_ALPHA, "GL_SRC_ALPHA" }, */
/*      { GL_ONE_MINUS_SRC_ALPHA, "GL_ONE_MINUS_SRC_ALPHA" }, */
/*      { GL_DST_ALPHA, "GL_DST_ALPHA" }, */
/*      { GL_ONE_MINUS_DST_ALPHA, "GL_ONE_MINUS_DST_ALPHA" }, */

/* BlendEquationSeparate */
 { GL_FUNC_ADD, "GL_FUNC_ADD" },                       
 { GL_BLEND_EQUATION, "GL_BLEND_EQUATION" },                 
 { GL_BLEND_EQUATION_RGB, "GL_BLEND_EQUATION_RGB" },                 /* same as BLEND_EQUATION */
 { GL_BLEND_EQUATION_ALPHA, "GL_BLEND_EQUATION_ALPHA" },           

/* BlendSubtract */
 { GL_FUNC_SUBTRACT, "GL_FUNC_SUBTRACT" },                  
 { GL_FUNC_REVERSE_SUBTRACT, "GL_FUNC_REVERSE_SUBTRACT" },          

/* Separate Blend Functions */
 { GL_BLEND_DST_RGB, "GL_BLEND_DST_RGB" },                  
 { GL_BLEND_SRC_RGB, "GL_BLEND_SRC_RGB" },                  
 { GL_BLEND_DST_ALPHA, "GL_BLEND_DST_ALPHA" },                
 { GL_BLEND_SRC_ALPHA, "GL_BLEND_SRC_ALPHA" },                
 { GL_CONSTANT_COLOR, "GL_CONSTANT_COLOR" },                 
 { GL_ONE_MINUS_CONSTANT_COLOR, "GL_ONE_MINUS_CONSTANT_COLOR" },       
 { GL_CONSTANT_ALPHA, "GL_CONSTANT_ALPHA" },                 
 { GL_ONE_MINUS_CONSTANT_ALPHA, "GL_ONE_MINUS_CONSTANT_ALPHA" },       
 { GL_BLEND_COLOR, "GL_BLEND_COLOR" },                    

/* Buffer Objects */
 { GL_ARRAY_BUFFER, "GL_ARRAY_BUFFER" },                   
 { GL_ELEMENT_ARRAY_BUFFER, "GL_ELEMENT_ARRAY_BUFFER" },           
 { GL_ARRAY_BUFFER_BINDING, "GL_ARRAY_BUFFER_BINDING" },           
 { GL_ELEMENT_ARRAY_BUFFER_BINDING, "GL_ELEMENT_ARRAY_BUFFER_BINDING" },   

 { GL_STREAM_DRAW, "GL_STREAM_DRAW" },                    
 { GL_STATIC_DRAW, "GL_STATIC_DRAW" },                    
 { GL_DYNAMIC_DRAW, "GL_DYNAMIC_DRAW" },                   

 { GL_BUFFER_SIZE, "GL_BUFFER_SIZE" },                    
 { GL_BUFFER_USAGE, "GL_BUFFER_USAGE" },                   

 { GL_CURRENT_VERTEX_ATTRIB, "GL_CURRENT_VERTEX_ATTRIB" },          

/* CullFaceMode */
 { GL_FRONT, "GL_FRONT" },                          
 { GL_BACK, "GL_BACK" },                           
 { GL_FRONT_AND_BACK, "GL_FRONT_AND_BACK" },                 

/* DepthFunction */
/*      { GL_NEVER, "GL_NEVER" }, */
/*      { GL_LESS, "GL_LESS" }, */
/*      { GL_EQUAL, "GL_EQUAL" }, */
/*      { GL_LEQUAL, "GL_LEQUAL" }, */
/*      { GL_GREATER, "GL_GREATER" }, */
/*      { GL_NOTEQUAL, "GL_NOTEQUAL" }, */
/*      { GL_GEQUAL, "GL_GEQUAL" }, */
/*      { GL_ALWAYS, "GL_ALWAYS" }, */

/* EnableCap */
 { GL_TEXTURE_2D, "GL_TEXTURE_2D" },                     
 { GL_CULL_FACE, "GL_CULL_FACE" },                      
 { GL_BLEND, "GL_BLEND" },                          
 { GL_DITHER, "GL_DITHER" },                         
 { GL_STENCIL_TEST, "GL_STENCIL_TEST" },                   
 { GL_DEPTH_TEST, "GL_DEPTH_TEST" },                     
 { GL_SCISSOR_TEST, "GL_SCISSOR_TEST" },                   
 { GL_POLYGON_OFFSET_FILL, "GL_POLYGON_OFFSET_FILL" },            
 { GL_SAMPLE_ALPHA_TO_COVERAGE, "GL_SAMPLE_ALPHA_TO_COVERAGE" },       
 { GL_SAMPLE_COVERAGE, "GL_SAMPLE_COVERAGE" },                

/* ErrorCode */
 { GL_NO_ERROR, "GL_NO_ERROR" },                       
 { GL_INVALID_ENUM, "GL_INVALID_ENUM" },                   
 { GL_INVALID_VALUE, "GL_INVALID_VALUE" },                  
 { GL_INVALID_OPERATION, "GL_INVALID_OPERATION" },              
 { GL_OUT_OF_MEMORY, "GL_OUT_OF_MEMORY" },                  

/* FrontFaceDirection */
 { GL_CW, "GL_CW" },                             
 { GL_CCW, "GL_CCW" },                            

/* GetPName */
 { GL_LINE_WIDTH, "GL_LINE_WIDTH" },                     
 { GL_ALIASED_POINT_SIZE_RANGE, "GL_ALIASED_POINT_SIZE_RANGE" },       
 { GL_ALIASED_LINE_WIDTH_RANGE, "GL_ALIASED_LINE_WIDTH_RANGE" },       
 { GL_CULL_FACE_MODE, "GL_CULL_FACE_MODE" },                 
 { GL_FRONT_FACE, "GL_FRONT_FACE" },                     
 { GL_DEPTH_RANGE, "GL_DEPTH_RANGE" },                    
 { GL_DEPTH_WRITEMASK, "GL_DEPTH_WRITEMASK" },                
 { GL_DEPTH_CLEAR_VALUE, "GL_DEPTH_CLEAR_VALUE" },              
 { GL_DEPTH_FUNC, "GL_DEPTH_FUNC" },                     
 { GL_STENCIL_CLEAR_VALUE, "GL_STENCIL_CLEAR_VALUE" },            
 { GL_STENCIL_FUNC, "GL_STENCIL_FUNC" },                   
 { GL_STENCIL_FAIL, "GL_STENCIL_FAIL" },                   
 { GL_STENCIL_PASS_DEPTH_FAIL, "GL_STENCIL_PASS_DEPTH_FAIL" },        
 { GL_STENCIL_PASS_DEPTH_PASS, "GL_STENCIL_PASS_DEPTH_PASS" },        
 { GL_STENCIL_REF, "GL_STENCIL_REF" },                    
 { GL_STENCIL_VALUE_MASK, "GL_STENCIL_VALUE_MASK" },             
 { GL_STENCIL_WRITEMASK, "GL_STENCIL_WRITEMASK" },              
 { GL_STENCIL_BACK_FUNC, "GL_STENCIL_BACK_FUNC" },              
 { GL_STENCIL_BACK_FAIL, "GL_STENCIL_BACK_FAIL" },              
 { GL_STENCIL_BACK_PASS_DEPTH_FAIL, "GL_STENCIL_BACK_PASS_DEPTH_FAIL" },   
 { GL_STENCIL_BACK_PASS_DEPTH_PASS, "GL_STENCIL_BACK_PASS_DEPTH_PASS" },   
 { GL_STENCIL_BACK_REF, "GL_STENCIL_BACK_REF" },               
 { GL_STENCIL_BACK_VALUE_MASK, "GL_STENCIL_BACK_VALUE_MASK" },        
 { GL_STENCIL_BACK_WRITEMASK, "GL_STENCIL_BACK_WRITEMASK" },         
 { GL_VIEWPORT, "GL_VIEWPORT" },                       
 { GL_SCISSOR_BOX, "GL_SCISSOR_BOX" },                    
/*      { GL_SCISSOR_TEST, "GL_SCISSOR_TEST" }, */
 { GL_COLOR_CLEAR_VALUE, "GL_COLOR_CLEAR_VALUE" },              
 { GL_COLOR_WRITEMASK, "GL_COLOR_WRITEMASK" },                
 { GL_UNPACK_ALIGNMENT, "GL_UNPACK_ALIGNMENT" },               
 { GL_PACK_ALIGNMENT, "GL_PACK_ALIGNMENT" },                 
 { GL_MAX_TEXTURE_SIZE, "GL_MAX_TEXTURE_SIZE" },               
 { GL_MAX_VIEWPORT_DIMS, "GL_MAX_VIEWPORT_DIMS" },              
 { GL_SUBPIXEL_BITS, "GL_SUBPIXEL_BITS" },                  
 { GL_RED_BITS, "GL_RED_BITS" },                       
 { GL_GREEN_BITS, "GL_GREEN_BITS" },                     
 { GL_BLUE_BITS, "GL_BLUE_BITS" },                      
 { GL_ALPHA_BITS, "GL_ALPHA_BITS" },                     
 { GL_DEPTH_BITS, "GL_DEPTH_BITS" },                     
 { GL_STENCIL_BITS, "GL_STENCIL_BITS" },                   
 { GL_POLYGON_OFFSET_UNITS, "GL_POLYGON_OFFSET_UNITS" },           
/*      { GL_POLYGON_OFFSET_FILL, "GL_POLYGON_OFFSET_FILL" }, */
 { GL_POLYGON_OFFSET_FACTOR, "GL_POLYGON_OFFSET_FACTOR" },          
 { GL_TEXTURE_BINDING_2D, "GL_TEXTURE_BINDING_2D" },             
 { GL_SAMPLE_BUFFERS, "GL_SAMPLE_BUFFERS" },                 
 { GL_SAMPLES, "GL_SAMPLES" },                        
 { GL_SAMPLE_COVERAGE_VALUE, "GL_SAMPLE_COVERAGE_VALUE" },          
 { GL_SAMPLE_COVERAGE_INVERT, "GL_SAMPLE_COVERAGE_INVERT" },         

/* GetTextureParameter */
/*      { GL_TEXTURE_MAG_FILTER, "GL_TEXTURE_MAG_FILTER" }, */
/*      { GL_TEXTURE_MIN_FILTER, "GL_TEXTURE_MIN_FILTER" }, */
/*      { GL_TEXTURE_WRAP_S, "GL_TEXTURE_WRAP_S" }, */
/*      { GL_TEXTURE_WRAP_T, "GL_TEXTURE_WRAP_T" }, */

 { GL_NUM_COMPRESSED_TEXTURE_FORMATS, "GL_NUM_COMPRESSED_TEXTURE_FORMATS" }, 
 { GL_COMPRESSED_TEXTURE_FORMATS, "GL_COMPRESSED_TEXTURE_FORMATS" },     

/* HintMode */
 { GL_DONT_CARE, "GL_DONT_CARE" },                      
 { GL_FASTEST, "GL_FASTEST" },                        
 { GL_NICEST, "GL_NICEST" },                         

/* HintTarget */
 { GL_GENERATE_MIPMAP_HINT, "GL_GENERATE_MIPMAP_HINT" },            

/* DataType */
 { GL_BYTE, "GL_BYTE" },                           
 { GL_UNSIGNED_BYTE, "GL_UNSIGNED_BYTE" },                  
 { GL_SHORT, "GL_SHORT" },                          
 { GL_UNSIGNED_SHORT, "GL_UNSIGNED_SHORT" },                 
 { GL_INT, "GL_INT" },                            
 { GL_UNSIGNED_INT, "GL_UNSIGNED_INT" },                   
 { GL_FLOAT, "GL_FLOAT" },                          
 { GL_FIXED, "GL_FIXED" },                          

/* PixelFormat */
 { GL_DEPTH_COMPONENT, "GL_DEPTH_COMPONENT" },               
 {  GL_ALPHA, "GL_ALPHA" },                      
 { GL_RGB, "GL_RGB" },                            
 { GL_RGBA, "GL_RGBA" },                           
 { GL_LUMINANCE, "GL_LUMINANCE" },                      
 { GL_LUMINANCE_ALPHA, "GL_LUMINANCE_ALPHA" },                

/* PixelType */
/*      { GL_UNSIGNED_BYTE, "GL_UNSIGNED_BYTE" }, */
 { GL_UNSIGNED_SHORT_4_4_4_4, "GL_UNSIGNED_SHORT_4_4_4_4" },         
 { GL_UNSIGNED_SHORT_5_5_5_1, "GL_UNSIGNED_SHORT_5_5_5_1" },         
 { GL_UNSIGNED_SHORT_5_6_5, "GL_UNSIGNED_SHORT_5_6_5" },           

/* Shaders */
 { GL_FRAGMENT_SHADER, "GL_FRAGMENT_SHADER" },                  
 { GL_VERTEX_SHADER, "GL_VERTEX_SHADER" },                    
 { GL_MAX_VERTEX_ATTRIBS, "GL_MAX_VERTEX_ATTRIBS" },               
 { GL_MAX_VERTEX_UNIFORM_VECTORS, "GL_MAX_VERTEX_UNIFORM_VECTORS" },       
 { GL_MAX_VARYING_VECTORS, "GL_MAX_VARYING_VECTORS" },              
 { GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS" }, 
 { GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS" },   
 { GL_MAX_TEXTURE_IMAGE_UNITS, "GL_MAX_TEXTURE_IMAGE_UNITS" },          
 { GL_MAX_FRAGMENT_UNIFORM_VECTORS, "GL_MAX_FRAGMENT_UNIFORM_VECTORS" },     
 { GL_SHADER_TYPE, "GL_SHADER_TYPE" },                      
 { GL_DELETE_STATUS, "GL_DELETE_STATUS" },                    
 { GL_LINK_STATUS, "GL_LINK_STATUS" },                      
 { GL_VALIDATE_STATUS, "GL_VALIDATE_STATUS" },                  
 { GL_ATTACHED_SHADERS, "GL_ATTACHED_SHADERS" },                 
 { GL_ACTIVE_UNIFORMS, "GL_ACTIVE_UNIFORMS" },                  
 { GL_ACTIVE_UNIFORM_MAX_LENGTH, "GL_ACTIVE_UNIFORM_MAX_LENGTH" },        
 { GL_ACTIVE_ATTRIBUTES, "GL_ACTIVE_ATTRIBUTES" },                
 { GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH" },      
 { GL_SHADING_LANGUAGE_VERSION, "GL_SHADING_LANGUAGE_VERSION" },         
 { GL_CURRENT_PROGRAM, "GL_CURRENT_PROGRAM" },                  

/* StencilFunction */
 { GL_NEVER, "GL_NEVER" },                          
 { GL_LESS, "GL_LESS" },                           
 { GL_EQUAL, "GL_EQUAL" },                          
 { GL_LEQUAL, "GL_LEQUAL" },                         
 { GL_GREATER, "GL_GREATER" },                        
 { GL_NOTEQUAL, "GL_NOTEQUAL" },                       
 { GL_GEQUAL, "GL_GEQUAL" },                         
 { GL_ALWAYS, "GL_ALWAYS" },                         

/* StencilOp */
/*      { GL_ZERO, "GL_ZERO" }, */
 { GL_KEEP, "GL_KEEP" },                           
 { GL_REPLACE, "GL_REPLACE" },                        
 { GL_INCR, "GL_INCR" },                           
 { GL_DECR, "GL_DECR" },                           
 { GL_INVERT, "GL_INVERT" },                         
 { GL_INCR_WRAP, "GL_INCR_WRAP" },                      
 { GL_DECR_WRAP, "GL_DECR_WRAP" },                      

/* StringName */
 { GL_VENDOR, "GL_VENDOR" },                         
 { GL_RENDERER, "GL_RENDERER" },                       
 { GL_VERSION, "GL_VERSION" },                        
 { GL_EXTENSIONS, "GL_EXTENSIONS" },                     

/* TextureMagFilter */
 { GL_NEAREST, "GL_NEAREST" },                        
 { GL_LINEAR, "GL_LINEAR" },                         

/* TextureMinFilter */
/*      { GL_NEAREST, "GL_NEAREST" }, */
/*      { GL_LINEAR, "GL_LINEAR" }, */
 { GL_NEAREST_MIPMAP_NEAREST, "GL_NEAREST_MIPMAP_NEAREST" },         
 { GL_LINEAR_MIPMAP_NEAREST, "GL_LINEAR_MIPMAP_NEAREST" },          
 { GL_NEAREST_MIPMAP_LINEAR, "GL_NEAREST_MIPMAP_LINEAR" },          
 { GL_LINEAR_MIPMAP_LINEAR, "GL_LINEAR_MIPMAP_LINEAR" },           

/* TextureParameterName */
 { GL_TEXTURE_MAG_FILTER, "GL_TEXTURE_MAG_FILTER" },             
 { GL_TEXTURE_MIN_FILTER, "GL_TEXTURE_MIN_FILTER" },             
 { GL_TEXTURE_WRAP_S, "GL_TEXTURE_WRAP_S" },                 
 { GL_TEXTURE_WRAP_T, "GL_TEXTURE_WRAP_T" },                 

/* TextureTarget */
/*      { GL_TEXTURE_2D, "GL_TEXTURE_2D" }, */
 { GL_TEXTURE, "GL_TEXTURE" },                        

 { GL_TEXTURE_CUBE_MAP, "GL_TEXTURE_CUBE_MAP" },               
 { GL_TEXTURE_BINDING_CUBE_MAP, "GL_TEXTURE_BINDING_CUBE_MAP" },       
 { GL_TEXTURE_CUBE_MAP_POSITIVE_X, "GL_TEXTURE_CUBE_MAP_POSITIVE_X" },    
 { GL_TEXTURE_CUBE_MAP_NEGATIVE_X, "GL_TEXTURE_CUBE_MAP_NEGATIVE_X" },    
 { GL_TEXTURE_CUBE_MAP_POSITIVE_Y, "GL_TEXTURE_CUBE_MAP_POSITIVE_Y" },    
 { GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y" },    
 { GL_TEXTURE_CUBE_MAP_POSITIVE_Z, "GL_TEXTURE_CUBE_MAP_POSITIVE_Z" },    
 { GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z" },    
 { GL_MAX_CUBE_MAP_TEXTURE_SIZE, "GL_MAX_CUBE_MAP_TEXTURE_SIZE" },      

/* TextureUnit */
 { GL_TEXTURE0, "GL_TEXTURE0" },                       
 { GL_TEXTURE1, "GL_TEXTURE1" },                       
 { GL_TEXTURE2, "GL_TEXTURE2" },                       
 { GL_TEXTURE3, "GL_TEXTURE3" },                       
 { GL_TEXTURE4, "GL_TEXTURE4" },                       
 { GL_TEXTURE5, "GL_TEXTURE5" },                       
 { GL_TEXTURE6, "GL_TEXTURE6" },                       
 { GL_TEXTURE7, "GL_TEXTURE7" },                       
 { GL_TEXTURE8, "GL_TEXTURE8" },                       
 { GL_TEXTURE9, "GL_TEXTURE9" },                       
 { GL_TEXTURE10, "GL_TEXTURE10" },                      
 { GL_TEXTURE11, "GL_TEXTURE11" },                      
 { GL_TEXTURE12, "GL_TEXTURE12" },                      
 { GL_TEXTURE13, "GL_TEXTURE13" },                      
 { GL_TEXTURE14, "GL_TEXTURE14" },                      
 { GL_TEXTURE15, "GL_TEXTURE15" },                      
 { GL_TEXTURE16, "GL_TEXTURE16" },                      
 { GL_TEXTURE17, "GL_TEXTURE17" },                      
 { GL_TEXTURE18, "GL_TEXTURE18" },                      
 { GL_TEXTURE19, "GL_TEXTURE19" },                      
 { GL_TEXTURE20, "GL_TEXTURE20" },                      
 { GL_TEXTURE21, "GL_TEXTURE21" },                      
 { GL_TEXTURE22, "GL_TEXTURE22" },                      
 { GL_TEXTURE23, "GL_TEXTURE23" },                      
 { GL_TEXTURE24, "GL_TEXTURE24" },                      
 { GL_TEXTURE25, "GL_TEXTURE25" },                      
 { GL_TEXTURE26, "GL_TEXTURE26" },                      
 { GL_TEXTURE27, "GL_TEXTURE27" },                      
 { GL_TEXTURE28, "GL_TEXTURE28" },                      
 { GL_TEXTURE29, "GL_TEXTURE29" },                      
 { GL_TEXTURE30, "GL_TEXTURE30" },                      
 { GL_TEXTURE31, "GL_TEXTURE31" },                      
 { GL_ACTIVE_TEXTURE, "GL_ACTIVE_TEXTURE" },                 

/* TextureWrapMode */
 { GL_REPEAT, "GL_REPEAT" },                         
 { GL_CLAMP_TO_EDGE, "GL_CLAMP_TO_EDGE" },                  
 { GL_MIRRORED_REPEAT, "GL_MIRRORED_REPEAT" },                

/* Uniform Types */
 { GL_FLOAT_VEC2, "GL_FLOAT_VEC2" },                     
 { GL_FLOAT_VEC3, "GL_FLOAT_VEC3" },                     
 { GL_FLOAT_VEC4, "GL_FLOAT_VEC4" },                     
 { GL_INT_VEC2, "GL_INT_VEC2" },                       
 { GL_INT_VEC3, "GL_INT_VEC3" },                       
 { GL_INT_VEC4, "GL_INT_VEC4" },                       
 { GL_BOOL, "GL_BOOL" },                           
 { GL_BOOL_VEC2, "GL_BOOL_VEC2" },                      
 { GL_BOOL_VEC3, "GL_BOOL_VEC3" },                      
 { GL_BOOL_VEC4, "GL_BOOL_VEC4" },                      
 { GL_FLOAT_MAT2, "GL_FLOAT_MAT2" },                     
 { GL_FLOAT_MAT3, "GL_FLOAT_MAT3" },                     
 { GL_FLOAT_MAT4, "GL_FLOAT_MAT4" },                     
 { GL_SAMPLER_2D, "GL_SAMPLER_2D" },                     
 { GL_SAMPLER_CUBE, "GL_SAMPLER_CUBE" },                   

/* Vertex Arrays */
 { GL_VERTEX_ATTRIB_ARRAY_ENABLED, "GL_VERTEX_ATTRIB_ARRAY_ENABLED" },        
 { GL_VERTEX_ATTRIB_ARRAY_SIZE, "GL_VERTEX_ATTRIB_ARRAY_SIZE" },           
 { GL_VERTEX_ATTRIB_ARRAY_STRIDE, "GL_VERTEX_ATTRIB_ARRAY_STRIDE" },         
 { GL_VERTEX_ATTRIB_ARRAY_TYPE, "GL_VERTEX_ATTRIB_ARRAY_TYPE" },           
 { GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED" },     
 { GL_VERTEX_ATTRIB_ARRAY_POINTER, "GL_VERTEX_ATTRIB_ARRAY_POINTER" },        
 { GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING" }, 

/* Read Format */
 { GL_IMPLEMENTATION_COLOR_READ_TYPE, "GL_IMPLEMENTATION_COLOR_READ_TYPE" },   
 { GL_IMPLEMENTATION_COLOR_READ_FORMAT, "GL_IMPLEMENTATION_COLOR_READ_FORMAT" }, 

/* Shader Source */
 { GL_COMPILE_STATUS, "GL_COMPILE_STATUS" },                 
 { GL_INFO_LOG_LENGTH, "GL_INFO_LOG_LENGTH" },                
 { GL_SHADER_SOURCE_LENGTH, "GL_SHADER_SOURCE_LENGTH" },           
 { GL_SHADER_COMPILER, "GL_SHADER_COMPILER" },                

/* Shader Binary */
 { GL_SHADER_BINARY_FORMATS, "GL_SHADER_BINARY_FORMATS" },          
 { GL_NUM_SHADER_BINARY_FORMATS, "GL_NUM_SHADER_BINARY_FORMATS" },      

/* Shader Precision-Specified Types */
 { GL_LOW_FLOAT, "GL_LOW_FLOAT" },                      
 { GL_MEDIUM_FLOAT, "GL_MEDIUM_FLOAT" },                   
 { GL_HIGH_FLOAT, "GL_HIGH_FLOAT" },                     
 { GL_LOW_INT, "GL_LOW_INT" },                        
 { GL_MEDIUM_INT, "GL_MEDIUM_INT" },                     
 { GL_HIGH_INT, "GL_HIGH_INT" },                       

/* Framebuffer Object. */
 { GL_FRAMEBUFFER, "GL_FRAMEBUFFER" },                    
 { GL_RENDERBUFFER, "GL_RENDERBUFFER" },                   

 { GL_RGBA4, "GL_RGBA4" },                          
 { GL_RGB5_A1, "GL_RGB5_A1" },                        
 { GL_RGB565, "GL_RGB565" },                         
 { GL_DEPTH_COMPONENT16, "GL_DEPTH_COMPONENT16" },              
 { GL_STENCIL_INDEX, "GL_STENCIL_INDEX" },                  
 { GL_STENCIL_INDEX8, "GL_STENCIL_INDEX8" },                 

 { GL_RENDERBUFFER_WIDTH, "GL_RENDERBUFFER_WIDTH" },             
 { GL_RENDERBUFFER_HEIGHT, "GL_RENDERBUFFER_HEIGHT" },            
 { GL_RENDERBUFFER_INTERNAL_FORMAT, "GL_RENDERBUFFER_INTERNAL_FORMAT" },   
 { GL_RENDERBUFFER_RED_SIZE, "GL_RENDERBUFFER_RED_SIZE" },          
 { GL_RENDERBUFFER_GREEN_SIZE, "GL_RENDERBUFFER_GREEN_SIZE" },        
 { GL_RENDERBUFFER_BLUE_SIZE, "GL_RENDERBUFFER_BLUE_SIZE" },         
 { GL_RENDERBUFFER_ALPHA_SIZE, "GL_RENDERBUFFER_ALPHA_SIZE" },        
 { GL_RENDERBUFFER_DEPTH_SIZE, "GL_RENDERBUFFER_DEPTH_SIZE" },        
 { GL_RENDERBUFFER_STENCIL_SIZE, "GL_RENDERBUFFER_STENCIL_SIZE" },      

 { GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE, "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE" },           
 { GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME" },           
 { GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL" },         
 { GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE" }, 

 { GL_COLOR_ATTACHMENT0, "GL_COLOR_ATTACHMENT0" },              
 { GL_DEPTH_ATTACHMENT, "GL_DEPTH_ATTACHMENT" },               
 { GL_STENCIL_ATTACHMENT, "GL_STENCIL_ATTACHMENT" },             

 { GL_NONE, "GL_NONE" },                           

 { GL_FRAMEBUFFER_COMPLETE, "GL_FRAMEBUFFER_COMPLETE" },                      
 { GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT, "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT" },         
 { GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT, "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT" }, 
 { GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS, "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS" },         
 { GL_FRAMEBUFFER_UNSUPPORTED, "GL_FRAMEBUFFER_UNSUPPORTED" },                   

 { GL_FRAMEBUFFER_BINDING, "GL_FRAMEBUFFER_BINDING" },            
 { GL_RENDERBUFFER_BINDING, "GL_RENDERBUFFER_BINDING" },           
 { GL_MAX_RENDERBUFFER_SIZE, "GL_MAX_RENDERBUFFER_SIZE" },          

 { GL_INVALID_FRAMEBUFFER_OPERATION, "GL_INVALID_FRAMEBUFFER_OPERATION" },
 {0, "" }
 };




 void luagl_initconst(lua_State *L, const lualgesConst *gl_const)
{
  for (; gl_const->str; gl_const++) 
  {
    lua_pushstring(L, gl_const->str);
    lua_pushinteger(L, gl_const->value);
    lua_settable(L, -3);
  }
}

 /*
static int  luagles2_glActiveTexture(lua_State *L) { glActiveTexture (luaL_checkunsigned(L,1)); return 0; };
static int luagles2_glAttachShader(lua_State *L) { glAttachShader (luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); return 0;  }
static int luagles2_glBindAttribLocation(lua_State *L)  { glBindAttribLocation (luaL_checkunsigned(L,1), luaL_checkunsigned(L,2),luaL_checkstring(L,3)); return 0;  }
static int luagles2_glBindBuffer(lua_State *L) {  glBindBuffer (luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); return 0;  }
void luagles2_glBindFramebuffer(lua_State *L)  { glBindFramebuffer (luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); return 0; }
GL_APICALL void         GL_APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer);
GL_APICALL void         GL_APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer);
GL_APICALL void         GL_APIENTRY glBindTexture (GLenum target, GLuint texture);
GL_APICALL void         GL_APIENTRY glBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GL_APICALL void         GL_APIENTRY glBlendEquation ( GLenum mode );
GL_APICALL void         GL_APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
GL_APICALL void         GL_APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor);
GL_APICALL void         GL_APIENTRY glBlendFuncSeparate (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GL_APICALL void         GL_APIENTRY glBufferData (GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
GL_APICALL void         GL_APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
GL_APICALL GLenum       GL_APIENTRY glCheckFramebufferStatus (GLenum target);
GL_APICALL void         GL_APIENTRY glClear (GLbitfield mask);
GL_APICALL void         GL_APIENTRY glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GL_APICALL void         GL_APIENTRY glClearDepthf (GLclampf depth);
GL_APICALL void         GL_APIENTRY glClearStencil (GLint s);
GL_APICALL void         GL_APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GL_APICALL void         GL_APIENTRY glCompileShader (GLuint shader);
GL_APICALL void         GL_APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
GL_APICALL void         GL_APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
GL_APICALL void         GL_APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GL_APICALL void         GL_APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GL_APICALL GLuint       GL_APIENTRY glCreateProgram (void);
GL_APICALL GLuint       GL_APIENTRY glCreateShader (GLenum type);
GL_APICALL void         GL_APIENTRY glCullFace (GLenum mode);
GL_APICALL void         GL_APIENTRY glDeleteBuffers (GLsizei n, const GLuint* buffers);
GL_APICALL void         GL_APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint* framebuffers);
GL_APICALL void         GL_APIENTRY glDeleteProgram (GLuint program);
GL_APICALL void         GL_APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint* renderbuffers);
GL_APICALL void         GL_APIENTRY glDeleteShader (GLuint shader);
GL_APICALL void         GL_APIENTRY glDeleteTextures (GLsizei n, const GLuint* textures);
GL_APICALL void         GL_APIENTRY glDepthFunc (GLenum func);
GL_APICALL void         GL_APIENTRY glDepthMask (GLboolean flag);
GL_APICALL void         GL_APIENTRY glDepthRangef (GLclampf zNear, GLclampf zFar);
GL_APICALL void         GL_APIENTRY glDetachShader (GLuint program, GLuint shader);
GL_APICALL void         GL_APIENTRY glDisable (GLenum cap);
GL_APICALL void         GL_APIENTRY glDisableVertexAttribArray (GLuint index);
GL_APICALL void         GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count);
GL_APICALL void         GL_APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
GL_APICALL void         GL_APIENTRY glEnable (GLenum cap);
GL_APICALL void         GL_APIENTRY glEnableVertexAttribArray (GLuint index);
GL_APICALL void         GL_APIENTRY glFinish (void);
GL_APICALL void         GL_APIENTRY glFlush (void);
GL_APICALL void         GL_APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GL_APICALL void         GL_APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GL_APICALL void         GL_APIENTRY glFrontFace (GLenum mode);
GL_APICALL void         GL_APIENTRY glGenBuffers (GLsizei n, GLuint* buffers);
GL_APICALL void         GL_APIENTRY glGenerateMipmap (GLenum target);
GL_APICALL void         GL_APIENTRY glGenFramebuffers (GLsizei n, GLuint* framebuffers);
GL_APICALL void         GL_APIENTRY glGenRenderbuffers (GLsizei n, GLuint* renderbuffers);
GL_APICALL void         GL_APIENTRY glGenTextures (GLsizei n, GLuint* textures);
GL_APICALL void         GL_APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
GL_APICALL void         GL_APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
GL_APICALL void         GL_APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders);
GL_APICALL int          GL_APIENTRY glGetAttribLocation (GLuint program, const GLchar* name);
GL_APICALL void         GL_APIENTRY glGetBooleanv (GLenum pname, GLboolean* params);
GL_APICALL void         GL_APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint* params);
GL_APICALL GLenum       GL_APIENTRY glGetError (void);
GL_APICALL void         GL_APIENTRY glGetFloatv (GLenum pname, GLfloat* params);
GL_APICALL void         GL_APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint* params);
GL_APICALL void         GL_APIENTRY glGetIntegerv (GLenum pname, GLint* params);
GL_APICALL void         GL_APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint* params);
GL_APICALL void         GL_APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog);
GL_APICALL void         GL_APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint* params);
GL_APICALL void         GL_APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint* params);
GL_APICALL void         GL_APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog);
GL_APICALL void         GL_APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
GL_APICALL void         GL_APIENTRY glGetShaderSource (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source);
GL_APICALL const GLubyte* GL_APIENTRY glGetString (GLenum name);
GL_APICALL void         GL_APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat* params);
GL_APICALL void         GL_APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint* params);
GL_APICALL void         GL_APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat* params);
GL_APICALL void         GL_APIENTRY glGetUniformiv (GLuint program, GLint location, GLint* params);
GL_APICALL int          GL_APIENTRY glGetUniformLocation (GLuint program, const GLchar* name);
GL_APICALL void         GL_APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat* params);
GL_APICALL void         GL_APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint* params);
GL_APICALL void         GL_APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid** pointer);
GL_APICALL void         GL_APIENTRY glHint (GLenum target, GLenum mode);
GL_APICALL GLboolean    GL_APIENTRY glIsBuffer (GLuint buffer);
GL_APICALL GLboolean    GL_APIENTRY glIsEnabled (GLenum cap);
GL_APICALL GLboolean    GL_APIENTRY glIsFramebuffer (GLuint framebuffer);
GL_APICALL GLboolean    GL_APIENTRY glIsProgram (GLuint program);
GL_APICALL GLboolean    GL_APIENTRY glIsRenderbuffer (GLuint renderbuffer);
GL_APICALL GLboolean    GL_APIENTRY glIsShader (GLuint shader);
GL_APICALL GLboolean    GL_APIENTRY glIsTexture (GLuint texture);
GL_APICALL void         GL_APIENTRY glLineWidth (GLfloat width);
GL_APICALL void         GL_APIENTRY glLinkProgram (GLuint program);
GL_APICALL void         GL_APIENTRY glPixelStorei (GLenum pname, GLint param);
GL_APICALL void         GL_APIENTRY glPolygonOffset (GLfloat factor, GLfloat units);
GL_APICALL void         GL_APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
GL_APICALL void         GL_APIENTRY glReleaseShaderCompiler (void);
GL_APICALL void         GL_APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GL_APICALL void         GL_APIENTRY glSampleCoverage (GLclampf value, GLboolean invert);
GL_APICALL void         GL_APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
GL_APICALL void         GL_APIENTRY glShaderBinary (GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
GL_APICALL void         GL_APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
GL_APICALL void         GL_APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask);
GL_APICALL void         GL_APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
GL_APICALL void         GL_APIENTRY glStencilMask (GLuint mask);
GL_APICALL void         GL_APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask);
GL_APICALL void         GL_APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
GL_APICALL void         GL_APIENTRY glStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
GL_APICALL void         GL_APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GL_APICALL void         GL_APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param);
GL_APICALL void         GL_APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat* params);
GL_APICALL void         GL_APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param);
GL_APICALL void         GL_APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint* params);
GL_APICALL void         GL_APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
GL_APICALL void         GL_APIENTRY glUniform1f (GLint location, GLfloat x);
GL_APICALL void         GL_APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat* v);
GL_APICALL void         GL_APIENTRY glUniform1i (GLint location, GLint x);
GL_APICALL void         GL_APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint* v);
GL_APICALL void         GL_APIENTRY glUniform2f (GLint location, GLfloat x, GLfloat y);
GL_APICALL void         GL_APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat* v);
GL_APICALL void         GL_APIENTRY glUniform2i (GLint location, GLint x, GLint y);
GL_APICALL void         GL_APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint* v);
GL_APICALL void         GL_APIENTRY glUniform3f (GLint location, GLfloat x, GLfloat y, GLfloat z);
GL_APICALL void         GL_APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat* v);
GL_APICALL void         GL_APIENTRY glUniform3i (GLint location, GLint x, GLint y, GLint z);
GL_APICALL void         GL_APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint* v);
GL_APICALL void         GL_APIENTRY glUniform4f (GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GL_APICALL void         GL_APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat* v);
GL_APICALL void         GL_APIENTRY glUniform4i (GLint location, GLint x, GLint y, GLint z, GLint w);
GL_APICALL void         GL_APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint* v);
GL_APICALL void         GL_APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GL_APICALL void         GL_APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GL_APICALL void         GL_APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GL_APICALL void         GL_APIENTRY glUseProgram (GLuint program);
GL_APICALL void         GL_APIENTRY glValidateProgram (GLuint program);
GL_APICALL void         GL_APIENTRY glVertexAttrib1f (GLuint indx, GLfloat x);
GL_APICALL void         GL_APIENTRY glVertexAttrib1fv (GLuint indx, const GLfloat* values);
GL_APICALL void         GL_APIENTRY glVertexAttrib2f (GLuint indx, GLfloat x, GLfloat y);
GL_APICALL void         GL_APIENTRY glVertexAttrib2fv (GLuint indx, const GLfloat* values);
GL_APICALL void         GL_APIENTRY glVertexAttrib3f (GLuint indx, GLfloat x, GLfloat y, GLfloat z);
GL_APICALL void         GL_APIENTRY glVertexAttrib3fv (GLuint indx, const GLfloat* values);
GL_APICALL void         GL_APIENTRY glVertexAttrib4f (GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GL_APICALL void         GL_APIENTRY glVertexAttrib4fv (GLuint indx, const GLfloat* values);
GL_APICALL void         GL_APIENTRY glVertexAttribPointer (GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr);
GL_APICALL void         GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
*/
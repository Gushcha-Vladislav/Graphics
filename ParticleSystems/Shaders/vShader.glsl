attribute highp vec4 posAttr;
uniform highp mat4 matrix;
uniform highp float pointAttr;
uniform lowp vec4 colAttr;
varying lowp vec4 col;

void main()
{

    col = colAttr;
    gl_Position = matrix * posAttr;
    gl_PointSize=pointAttr;
}

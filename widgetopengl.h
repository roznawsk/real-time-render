#ifndef WIDGETOPENGL_H
#define WIDGETOPENGL_H

#include "model.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions_1_0>
#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>

#define MIN_OPENGL_VERSION "4.1"

class OpenGLVersionTest : public QOpenGLFunctions_4_1_Core
{
public:
    QString version()
    {
        initializeOpenGLFunctions();
        return (char *)glGetString(GL_VERSION);
    }
};

class WidgetOpenGL : public QOpenGLWidget, public QOpenGLFunctions_4_1_Core
{
public:
    WidgetOpenGL(QWidget *parent = 0) : QOpenGLWidget(parent) {}

    void v_transform(float rot_x, float rot_y, float rot_z, float zoom);

protected:
    bool init_ok;
    int triangles_cnt;

    QMatrix4x4 m_matrix, v_matrix, p_matrix;

    GLuint shaderProgram;
    GLuint VAO;
    Model model;

    GLuint loadShader(GLenum type, QString fname);
    QMatrix3x3 invertTranspose(const QMatrix4x4 &A); // !!!

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // WIDGETOPENGL_H

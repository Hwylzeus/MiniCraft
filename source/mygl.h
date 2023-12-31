#ifndef MYGL_H
#define MYGL_H

#include <glwidget.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/cube.h>
#include "camera.h"
#include <scene/scene.h>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class MyGL : public GLWidget
{
private:
    Cube geom_cube;// The instance of a unit cube we can use to render any cube. Should NOT be used in final version of your project.
    ShaderProgram prog_lambert;// A shader program that uses lambertian reflection
    ShaderProgram prog_flat;// A shader program that uses "flat" reflection (no shadowing at all)

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.
                // Don't worry too much about this. Just know it is necessary in order to render geometry.

    Camera gl_camera;
    Scene scene;

    /// Timer linked to timerUpdate(). Fires approx. 60 times per second
    QTimer timer;

    Camera gl_skyboxCamera;

    QPoint mouse_oldpos;
    bool mousemove;


public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void GLDrawScene();

protected:
    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent* event);

private slots:
    /// Slot that gets called ~60 times per second
    virtual void timerUpdate();
};


#endif // MYGL_H

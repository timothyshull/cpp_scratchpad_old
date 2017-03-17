#include "glwidget.h"
#include <QPainter>
#include <QTimer>

GLWidget::GLWidget(Helper* helper, QWidget* parent) : QOpenGLWidget{parent}, helper{helper} {
    elapsed = 0;
    setFixedSize(200, 200);
    setAutoFillBackground(false);
}

void GLWidget::animate() {
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}

void GLWidget::paintEvent(QPaintEvent* event) {
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event, elapsed);
    painter.end();
}

const QMetaObject* GLWidget::metaObject() const {
    return QOpenGLWidget::metaObject();
}

int GLWidget::qt_metacall(QMetaObject::Call call, int i, void** pVoid) {
    return QOpenGLWidget::qt_metacall(call, i, pVoid);
}

void* GLWidget::qt_metacast(const char* string) {
    return QOpenGLWidget::qt_metacast(string);
}


void GLWidget::qt_static_metacall(QObject* object, QMetaObject::Call call, int i, void** pVoid) {

}

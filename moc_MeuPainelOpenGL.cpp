/****************************************************************************
** Meta object code from reading C++ file 'MeuPainelOpenGL.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MeuPainelOpenGL.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeuPainelOpenGL.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MeuPainelOpenGL_t {
    QByteArrayData data[14];
    char stringdata[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeuPainelOpenGL_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeuPainelOpenGL_t qt_meta_stringdata_MeuPainelOpenGL = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MeuPainelOpenGL"
QT_MOC_LITERAL(1, 16, 13), // "updateSpinBox"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 20), // "updateCameraPosition"
QT_MOC_LITERAL(4, 52, 10), // "alterarCor"
QT_MOC_LITERAL(5, 63, 8), // "setColor"
QT_MOC_LITERAL(6, 72, 1), // "r"
QT_MOC_LITERAL(7, 74, 1), // "g"
QT_MOC_LITERAL(8, 76, 1), // "b"
QT_MOC_LITERAL(9, 78, 6), // "setRed"
QT_MOC_LITERAL(10, 85, 8), // "setGreen"
QT_MOC_LITERAL(11, 94, 7), // "setBlue"
QT_MOC_LITERAL(12, 102, 6), // "update"
QT_MOC_LITERAL(13, 109, 22) // "generateFakeMouseEvent"

    },
    "MeuPainelOpenGL\0updateSpinBox\0\0"
    "updateCameraPosition\0alterarCor\0"
    "setColor\0r\0g\0b\0setRed\0setGreen\0setBlue\0"
    "update\0generateFakeMouseEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeuPainelOpenGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       3,    3,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   73,    2, 0x0a /* Public */,
       5,    3,   74,    2, 0x0a /* Public */,
       9,    1,   81,    2, 0x0a /* Public */,
      10,    1,   84,    2, 0x0a /* Public */,
      11,    1,   87,    2, 0x0a /* Public */,
      12,    0,   90,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MeuPainelOpenGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeuPainelOpenGL *_t = static_cast<MeuPainelOpenGL *>(_o);
        switch (_id) {
        case 0: _t->updateSpinBox((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 1: _t->updateCameraPosition((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->alterarCor(); break;
        case 3: _t->setColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->setRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setGreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setBlue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->update(); break;
        case 8: _t->generateFakeMouseEvent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MeuPainelOpenGL::*_t)(float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeuPainelOpenGL::updateSpinBox)) {
                *result = 0;
            }
        }
        {
            typedef void (MeuPainelOpenGL::*_t)(float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeuPainelOpenGL::updateCameraPosition)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MeuPainelOpenGL::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MeuPainelOpenGL.data,
      qt_meta_data_MeuPainelOpenGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeuPainelOpenGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeuPainelOpenGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeuPainelOpenGL.stringdata))
        return static_cast<void*>(const_cast< MeuPainelOpenGL*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MeuPainelOpenGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MeuPainelOpenGL::updateSpinBox(float _t1, float _t2, float _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MeuPainelOpenGL::updateCameraPosition(float _t1, float _t2, float _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

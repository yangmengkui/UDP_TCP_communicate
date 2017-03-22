/****************************************************************************
** Meta object code from reading C++ file 'ServerStream.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ServerStream.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerStream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServerStream_t {
    QByteArrayData data[12];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerStream_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerStream_t qt_meta_stringdata_ServerStream = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ServerStream"
QT_MOC_LITERAL(1, 13, 9), // "idChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "getSocketImage"
QT_MOC_LITERAL(4, 39, 14), // "conEstablished"
QT_MOC_LITERAL(5, 54, 14), // "dealConnection"
QT_MOC_LITERAL(6, 69, 9), // "sendUDPIp"
QT_MOC_LITERAL(7, 79, 2), // "id"
QT_MOC_LITERAL(8, 82, 9), // "INDI_INFO"
QT_MOC_LITERAL(9, 92, 4), // "LEFT"
QT_MOC_LITERAL(10, 97, 5), // "RIGHT"
QT_MOC_LITERAL(11, 103, 11) // "SPEED_LIMIT"

    },
    "ServerStream\0idChanged\0\0getSocketImage\0"
    "conEstablished\0dealConnection\0sendUDPIp\0"
    "id\0INDI_INFO\0LEFT\0RIGHT\0SPEED_LIMIT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerStream[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   44, // properties
       1,   48, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, 0x80000000 | 8, 0x0049500b,

 // properties: notify_signal_id
       0,

 // enums: name, flags, count, data
       8, 0x0,    3,   52,

 // enum data: key, value
       9, uint(ServerStream::LEFT),
      10, uint(ServerStream::RIGHT),
      11, uint(ServerStream::SPEED_LIMIT),

       0        // eod
};

void ServerStream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerStream *_t = static_cast<ServerStream *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->getSocketImage(); break;
        case 2: _t->conEstablished(); break;
        case 3: _t->dealConnection(); break;
        case 4: _t->sendUDPIp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::idChanged)) {
                *result = 0;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ServerStream *_t = static_cast<ServerStream *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< INDI_INFO*>(_v) = _t->m_id; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ServerStream *_t = static_cast<ServerStream *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_id != *reinterpret_cast< INDI_INFO*>(_v)) {
                _t->m_id = *reinterpret_cast< INDI_INFO*>(_v);
                Q_EMIT _t->idChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject ServerStream::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ServerStream.data,
      qt_meta_data_ServerStream,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ServerStream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerStream::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ServerStream.stringdata0))
        return static_cast<void*>(const_cast< ServerStream*>(this));
    return QWidget::qt_metacast(_clname);
}

int ServerStream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ServerStream::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

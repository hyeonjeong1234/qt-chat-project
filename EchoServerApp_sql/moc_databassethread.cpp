/****************************************************************************
** Meta object code from reading C++ file 'databassethread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "databassethread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databassethread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataBasseThread_t {
    QByteArrayData data[15];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataBasseThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataBasseThread_t qt_meta_stringdata_DataBasseThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DataBasseThread"
QT_MOC_LITERAL(1, 16, 8), // "finished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "error"
QT_MOC_LITERAL(4, 32, 3), // "err"
QT_MOC_LITERAL(5, 36, 12), // "result_login"
QT_MOC_LITERAL(6, 49, 11), // "QTcpSocket*"
QT_MOC_LITERAL(7, 61, 14), // "return_friends"
QT_MOC_LITERAL(8, 76, 15), // "QList<QString>&"
QT_MOC_LITERAL(9, 92, 7), // "process"
QT_MOC_LITERAL(10, 100, 21), // "slot_search_loginInfo"
QT_MOC_LITERAL(11, 122, 15), // "get_friend_list"
QT_MOC_LITERAL(12, 138, 6), // "userId"
QT_MOC_LITERAL(13, 145, 19), // "slot_get_new_friend"
QT_MOC_LITERAL(14, 165, 18) // "receive_clientInfo"

    },
    "DataBasseThread\0finished\0\0error\0err\0"
    "result_login\0QTcpSocket*\0return_friends\0"
    "QList<QString>&\0process\0slot_search_loginInfo\0"
    "get_friend_list\0userId\0slot_get_new_friend\0"
    "receive_clientInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBasseThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    2,   63,    2, 0x06 /* Public */,
       7,    2,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   73,    2, 0x0a /* Public */,
      10,    3,   74,    2, 0x0a /* Public */,
      11,    2,   81,    2, 0x0a /* Public */,
      13,    2,   86,    2, 0x0a /* Public */,
      14,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 6,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,   12,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void DataBasseThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataBasseThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->result_login((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->return_friends((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        case 4: _t->process(); break;
        case 5: _t->slot_search_loginInfo((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->get_friend_list((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        case 7: _t->slot_get_new_friend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->receive_clientInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataBasseThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBasseThread::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataBasseThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBasseThread::error)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataBasseThread::*)(QTcpSocket * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBasseThread::result_login)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataBasseThread::*)(QList<QString> & , QTcpSocket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBasseThread::return_friends)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataBasseThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_DataBasseThread.data,
    qt_meta_data_DataBasseThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataBasseThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBasseThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataBasseThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int DataBasseThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DataBasseThread::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DataBasseThread::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataBasseThread::result_login(QTcpSocket * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataBasseThread::return_friends(QList<QString> & _t1, QTcpSocket * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

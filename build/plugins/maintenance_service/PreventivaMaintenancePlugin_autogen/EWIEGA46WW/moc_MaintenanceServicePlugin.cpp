/****************************************************************************
** Meta object code from reading C++ file 'MaintenanceServicePlugin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../plugins/maintenance_service/MaintenanceServicePlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MaintenanceServicePlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaintenanceServicePlugin_t {
    const uint offsetsAndSize[2];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MaintenanceServicePlugin_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MaintenanceServicePlugin_t qt_meta_stringdata_MaintenanceServicePlugin = {
    {
QT_MOC_LITERAL(0, 24) // "MaintenanceServicePlugin"

    },
    "MaintenanceServicePlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaintenanceServicePlugin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MaintenanceServicePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject MaintenanceServicePlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MaintenanceServicePlugin.offsetsAndSize,
    qt_meta_data_MaintenanceServicePlugin,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MaintenanceServicePlugin_t
, QtPrivate::TypeAndForceComplete<MaintenanceServicePlugin, std::true_type>



>,
    nullptr
} };


const QMetaObject *MaintenanceServicePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaintenanceServicePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaintenanceServicePlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Preventiva::IMaintenanceService"))
        return static_cast< Preventiva::IMaintenanceService*>(this);
    if (!strcmp(_clname, "br.sejaefi.preventiva.IMaintenanceService/1.0"))
        return static_cast< Preventiva::IMaintenanceService*>(this);
    return QObject::qt_metacast(_clname);
}

int MaintenanceServicePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData_MaintenanceServicePlugin[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x2d,  'b',  'r',  '.',  's',  'e', 
    'j',  'a',  'e',  'f',  'i',  '.',  'p',  'r', 
    'e',  'v',  'e',  'n',  't',  'i',  'v',  'a', 
    '.',  'I',  'M',  'a',  'i',  'n',  't',  'e', 
    'n',  'a',  'n',  'c',  'e',  'S',  'e',  'r', 
    'v',  'i',  'c',  'e',  '/',  '1',  '.',  '0', 
    // "className"
    0x03,  0x78,  0x18,  'M',  'a',  'i',  'n',  't', 
    'e',  'n',  'a',  'n',  'c',  'e',  'S',  'e', 
    'r',  'v',  'i',  'c',  'e',  'P',  'l',  'u', 
    'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xa5,  0x63,  'I',  'I',  'D',  0x78,  0x2d, 
    'b',  'r',  '.',  's',  'e',  'j',  'a',  'e', 
    'f',  'i',  '.',  'p',  'r',  'e',  'v',  'e', 
    'n',  't',  'i',  'v',  'a',  '.',  'I',  'M', 
    'a',  'i',  'n',  't',  'e',  'n',  'a',  'n', 
    'c',  'e',  'S',  'e',  'r',  'v',  'i',  'c', 
    'e',  '/',  '1',  '.',  '0',  0x69,  'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x78, 
    0x18,  'M',  'a',  'i',  'n',  't',  'e',  'n', 
    'a',  'n',  'c',  'e',  'S',  'e',  'r',  'v', 
    'i',  'c',  'e',  'P',  'l',  'u',  'g',  'i', 
    'n',  0x6b,  'd',  'e',  's',  'c',  'r',  'i', 
    'p',  't',  'i',  'o',  'n',  0x78,  0x2f,  'S', 
    'e',  'r',  'v',  'i',  uchar('\xc3'), uchar('\xa7'), 'o',  ' ', 
    'd',  'e',  ' ',  'm',  'a',  'n',  'u',  't', 
    'e',  'n',  uchar('\xc3'), uchar('\xa7'), uchar('\xc3'), uchar('\xa3'), 'o',  ' ', 
    'p',  'r',  'e',  'v',  'e',  'n',  't',  'i', 
    'v',  'a',  ' ',  'v',  'i',  'a',  ' ',  'p', 
    'l',  'u',  'g',  'i',  'n',  '.',  0x66,  'v', 
    'e',  'n',  'd',  'o',  'r',  0x69,  'E',  'f', 
    uchar('\xc3'), uchar('\xad'), ' ',  'D',  'e',  'm',  'o',  0x67, 
    'v',  'e',  'r',  's',  'i',  'o',  'n',  0x63, 
    '1',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(MaintenanceServicePlugin, MaintenanceServicePlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE

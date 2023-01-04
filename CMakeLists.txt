cmake_minimum_required(VERSION 3.9)
project(QtC)

#====== Global Configurations ==================#

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Export ALL DLLs symbols on Windows without __declspec(xxxx) annotations.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

#=============== Target Configurations ============#
set(QTC_INCLUDE_DIR
    "header"
)
include_directories(${QTC_INCLUDE_DIR})
set(SRC
	"src/qabstractbutton.cpp"
	"src/qaction.cpp"
	"src/qlayout.cpp"
	"src/qobject.cpp"
	"src/qstackedwidget.cpp"
	"src/qtoolbutton.cpp"
	"src/qabstractscrollarea.cpp"
	"src/qapplication.cpp"
	"src/qmdiarea.cpp"
	"src/qprogressbar.cpp"
	"src/qstring.cpp"
	"src/qwidget.cpp"
	"src/qabstractslider.cpp"
	"src/qdial.cpp"
	"src/qmdisubwindow.cpp"
	"src/qpushbutton.cpp"
	"src/qt.cpp"              
	"src/qabstractspinbox.cpp"
	"src/qlabel.cpp"
	"src/qmenubar.cpp"
	"src/qsizegrip.cpp"
	"src/qtoolbar.cpp"
)
# --------------------------------------------------#
add_library( qtc SHARED ${SRC} ${QTC_INCLUDE_DIR})
target_link_libraries( qtc PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets )      

add_executable( hello_world  "examples/Hello_world/test.c" )
target_include_directories(hello_world PRIVATE ${QTC_INCLUDE_DIR})
target_link_libraries( hello_world  qtc )      

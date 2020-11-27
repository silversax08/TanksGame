
cmake_minimum_required(VERSION 3.4)
project(Tanks)

FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer osgText)
FIND_PACKAGE(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${OPENSCENEGRAPH_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

set( MYRESOURCES icons/icons.qrc)

add_library(ProjectileMotion STATIC
    ProjectileMotion.hpp
    ProjectileMotion.cpp
    ProjectileMotionEquations.hpp
    ProjectileMotionEquations.cpp
  )

add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindowform.ui
    TankL.h
    TankL.cpp
    TankR.h
    TankR.cpp
    Bullet.h
    Bullet.cpp
    BarrelL.h
    BarrelL.cpp
    BarrelR.h
    BarrelR.cpp
    Game.h
    Game.cpp
    startscreen.h
    startscreen.cpp
    startscreen.ui
    gamevisual.h
    gamevisual.cpp
    gamevisual.ui
    ${MYRESOURCES}
)

target_link_libraries(${PROJECT_NAME}
    ${OPENSCENEGRAPH_LIBRARIES}
    Qt5::Widgets
    Qt5::Gui
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    ProjectileMotion
)

add_executable(Unit_Tests
    calculate_new_velocity.cpp
    calculate_new_position.cpp
    calculate_vector_velocity.cpp
    )

target_link_libraries(Unit_Tests
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    ProjectileMotion
)


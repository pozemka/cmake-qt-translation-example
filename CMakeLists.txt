cmake_minimum_required(VERSION 3.17)
project(translation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

set(TS_FILES
        ${CMAKE_SOURCE_DIR}/lang/ru.ts
        ${CMAKE_SOURCE_DIR}/lang/fr.ts)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} LinguistTools REQUIRED)

configure_file(translations.qrc ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

qt5_create_translation(QM_FILES ${CMAKE_CURRENT_SOURCE_DIR} ${TS_FILES})

add_executable(${PROJECT_NAME} main.cpp ${TS_FILES} ${QM_FILES} ${CMAKE_CURRENT_BINARY_DIR}/translations.qrc)

message(${QM_FILES})

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

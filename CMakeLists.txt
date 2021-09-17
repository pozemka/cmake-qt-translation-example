cmake_minimum_required(VERSION 3.17)
project(translation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

# Files with translation sources. You should run lupdate manually when needed to regenerate them
set(TS_FILES
        ${CMAKE_SOURCE_DIR}/lang/ru.ts
        ${CMAKE_SOURCE_DIR}/lang/fr.ts)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lang)  # create directory for lrelease output (it does not created autmatically by lrelease)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} LinguistTools REQUIRED) # finding LinguistTools

configure_file(translations.qrc ${CMAKE_CURRENT_BINARY_DIR} COPYONLY) # copy translations.qrc file to buld directory. It is needed because rcc searches resources in path relative to .qrc file

#qt5_create_translation(QM_FILES ${CMAKE_CURRENT_SOURCE_DIR} ${TS_FILES}) # this should regenerate .ts files automatically but currently will remove old one when asking for rebuild. Which is undesirable. See QTBUG-96549 and https://forum.qt.io/topic/130308

set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION "lang") # set qm files output directory
qt5_add_translation(QM_FILES ${TS_FILES})   # generate qm files

add_executable(${PROJECT_NAME} main.cpp ${TS_FILES} ${QM_FILES} ${CMAKE_CURRENT_BINARY_DIR}/translations.qrc) # note that ${QM_FILES} should be included as sources to be generated.

message(${QM_FILES})

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

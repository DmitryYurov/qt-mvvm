set(library_name mvvm)

target_sources(${library_name} PRIVATE
    booleditor.cpp
    booleditor.h
    coloreditor.cpp
    coloreditor.h
    combopropertyeditor.cpp
    combopropertyeditor.h
    customeditor.cpp
    customeditor.h
    customeventfilters.cpp
    customeventfilters.h
    defaulteditorfactory.cpp
    defaulteditorfactory.h
    doubleeditor.cpp
    doubleeditor.h
    editorbuilders.cpp
    editorbuilders.h
    editorfactoryinterface.h
    externalpropertyeditor.cpp
    externalpropertyeditor.h
    integereditor.cpp
    integereditor.h
    scientificdoubleeditor.cpp
    scientificdoubleeditor.h
    scientificspinboxeditor.cpp
    scientificspinboxeditor.h
    styleutils.cpp
    styleutils.h
)

target_include_directories(${library_name}
    PUBLIC
        $<INSTALL_INTERFACE:public>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)

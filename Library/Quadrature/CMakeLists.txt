
ADD_LIBRARY(
    Quadrature
    QAG.cpp
    Workspace.cpp
    GaussKronrod.cpp
)

INSTALL(TARGETS Quadrature
        LIBRARY DESTINATION "lib/libGLCD")

INSTALL(DIRECTORY "."
        DESTINATION "include/libGLCD/Quadrature"
        FILES_MATCHING PATTERN "*.h")


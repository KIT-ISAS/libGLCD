
ADD_LIBRARY(
    Optimization
    QuasiNewton.cpp
    BFGS.cpp
    LBFGS.cpp
    LineSearchNocedal.cpp
)

INSTALL(TARGETS Optimization
        LIBRARY DESTINATION "lib/libGLCD")

INSTALL(DIRECTORY "."
        DESTINATION "include/libGLCD/Optimization"
        FILES_MATCHING PATTERN "*.h")


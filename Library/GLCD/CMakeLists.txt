
ADD_LIBRARY(
    GLCD
    MCvMDistance.cpp
    MCvMDistanceAsym.cpp
    MCvMDistanceSym.cpp
    MCvMDistanceSymEven.cpp
    MCvMDistanceSymOdd.cpp
    MCvMDistanceOptimizer.cpp
    Misc.cpp
    ExpInt.cpp
    Computation.cpp
    GLCD_C_Wrapper.cpp
)

set(GLCD_LINK_LIBRARIES Quadrature Optimization)

if(OpenMP_CXX_FOUND)
    set(GLCD_LINK_LIBRARIES ${GLCD_LINK_LIBRARIES} OpenMP::OpenMP_CXX)
endif()

target_compile_features(GLCD PUBLIC cxx_std_14)
target_link_libraries(GLCD PUBLIC ${GLCD_LINK_LIBRARIES})

INSTALL(TARGETS GLCD
        LIBRARY DESTINATION "lib/libGLCD")

INSTALL(DIRECTORY "."
        DESTINATION "include/libGLCD/GLCD"
        FILES_MATCHING PATTERN "*.h")


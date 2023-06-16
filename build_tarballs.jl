# Note that this script can accept some limited command-line arguments, run
# `julia build_tarballs.jl --help` to see a usage message.
using BinaryBuilder, Pkg

name = "libGLCD"
version = v"1.0.0"

# Collection of sources required to complete build
sources = [
    GitSource("https://github.com/KIT-ISAS/libGLCD.git", "d818348732ff6bf5b544cfef2602d6f70954a834")
]

# Bash recipe for building across all platforms
script = raw"""
cd $WORKSPACE/srcdir
cmake -DCMAKE_INSTALL_PREFIX=$prefix -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TARGET_TOOLCHAIN} -DCMAKE_BUILD_TYPE=Release libGLCD
make install
install_license libGLCD/LICENSE
"""

# These are the platforms we will build for by default, unless further
# platforms are passed in on the command line
platforms = [
    Platform("x86_64", "windows"; ),
    Platform("x86_64", "linux"; libc = "glibc")
]
platforms = expand_cxxstring_abis(platforms)

# The products that we will ensure are always built
products = [
    LibraryProduct("libGLCD", :lib_glcd, "lib/libGLCD"),
    LibraryProduct("libQuadrature", :lib_quad, "lib/libGLCD"),
    LibraryProduct("libOptimization", :lib_opt, "lib/libGLCD")
]

# Dependencies that must be installed before this package can be built
dependencies = [
    Dependency(PackageSpec(name="CompilerSupportLibraries_jll", uuid="e66e0078-7015-5450-92f7-15fbd957f2ae"))
    Dependency(PackageSpec(name="Eigen_jll", uuid="bc6bbf8a-a594-5541-9c57-10b0d0312c70"))
]

# Build the tarballs, and possibly a `build.jl` as well.
build_tarballs(ARGS, name, version, sources, script, platforms, products, dependencies; julia_compat="1.6", preferred_gcc_version = v"7.1.0")

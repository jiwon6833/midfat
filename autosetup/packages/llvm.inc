echo "building LLVM"
cd "$PATHAUTOPACKSRC"
[ -d llvm/.git ] || run git clone http://github.com/jeffy1009/riscv-llvm llvm
[ -d llvm/tools/clang/.git ] || run git clone https://github.com/jeffy1009/riscv-clang  llvm/tools/clang
[ -d llvm/projects/compiler-rt/.svn ] || run svn co -r"$VERSIONLLVM" http://llvm.org/svn/llvm-project/compiler-rt/trunk llvm/projects/compiler-rt
cd "$PATHAUTOPACKSRC/llvm"
run mkdir -p "$PATHAUTOPACKSRC/llvm/obj"
cd "$PATHAUTOPACKSRC/llvm/obj"
[ -f Makefile ] || run cmake -DCMAKE_BUILD_TYPE="Release" -DLLVM_ENABLE_ASSERTIONS=ON -DLLVM_TARGETS_TO_BUILD="RISCV;host" -DLLVM_PARALLEL_COMPILE_JOBS="8" -DLLVM_PARALLEL_LINK_JOBS="1" -DLLVM_OPTIMIZED_TABLEGEN="ON" -DLLVM_BINUTILS_INCDIR="$PATHBINUTILS/include" -DCMAKE_INSTALL_PREFIX="$PATHAUTOPREFIX" -GNinja ..

ninja clang
ninja llvm-lto
ninja install

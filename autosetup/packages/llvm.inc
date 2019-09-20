echo "building LLVM"
cd "$PATHAUTOPACKSRC"
[ -d llvm/.git ] || run git clone http://github.com/jeffy1009/riscv-llvm llvm
[ -d llvm/tools/clang/.git ] || run git clone https://github.com/jeffy1009/riscv-clang  llvm/tools/clang
[ -d llvm/projects/compiler-rt/.git ] || run git clone -b release_80 --depth=1 https://git.llvm.org/git/compiler-rt.git/ llvm/projects/compiler-rt
cd "$PATHAUTOPACKSRC/llvm"
run mkdir -p "$PATHAUTOPACKSRC/llvm/obj"
cd "$PATHAUTOPACKSRC/llvm/obj"
[ -f Makefile ] || run cmake -DLLVM_PARALLEL_COMPILE_JOBS="8" -DLLVM_PARALLEL_LINK_JOBS="1" -DLLVM_OPTIMIZED_TABLEGEN="ON" -GNinja -DCMAKE_INSTALL_PREFIX="$PATHAUTOPREFIX" -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_ASSERTIONS=ON -DLLVM_BINUTILS_INCDIR="$PATHBINUTILS/include" "$PATHAUTOPACKSRC/llvm"
run ninja clang LLVMgold
run ninja install

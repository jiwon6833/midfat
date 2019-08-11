echo "building LLVM"
cd "$PATHAUTOPACKSRC"
[ -d llvm/.git ] || run git clone git@github.com:jiwon6833/MTE_llvm8.git llvm
[ -d llvm/tools/clang/.git ] || run git clone -b release_80 --depth=1 https://git.llvm.org/git/clang.git/ llvm/tools/clang
[ -d llvm/projects/compiler-rt/.git ] || run git clone -b release_80 --depth=1 https://git.llvm.org/git/compiler-rt.git/ llvm/projects/compiler-rt
cd "$PATHAUTOPACKSRC/llvm"
run mkdir -p "$PATHAUTOPACKSRC/llvm/obj"
cd "$PATHAUTOPACKSRC/llvm/obj"
[ -f Makefile ] || run /usr/bin/cmake -DCMAKE_INSTALL_PREFIX="$PATHAUTOPREFIX" -DLLVM_TARGETS_TO_BUILD="host;AArch64;RISCV" -DLLVM_PARALLEL_LINK_JOBS="1" -DLLVM_OPTIMIZED_TABLEGEN="ON" -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD="RISCV" -DLLVM_BUILD_LLVM_DYLIB=ON -DBUILD_SHARED_LIBS=ON -GNinja  -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_ASSERTIONS=ON -DLLVM_BINUTILS_INCDIR="$PATHBINUTILS/include" "$PATHAUTOPACKSRC/llvm"
run ninja -j"$JOBS"
run ninja install

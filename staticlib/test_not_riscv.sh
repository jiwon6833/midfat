mkdir -p ./obj
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu11 -g -O0 -fno-inline -MMD -o obj/metaset.o metaset.c
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu11 -g -O0 -fno-inline -MMD -o obj/metacheck.o metacheck.c
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu11 -g -O0 -fno-inline -MMD -o obj/globalinit.o globalinit.c
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu11 -g -O0 -fno-inline -MMD -o obj/argvcopy.o argvcopy.c
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu11 -g -O0 -fno-inline -MMD -o obj/compat.o compat.c
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu11 -g -O0 -fno-inline -MMD -o obj/metaget.o metaget.c
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu11 -g -O0 -fno-inline -MMD -o obj/stackinit.o stackinit.c
clang -I. -I../metapagetable -I/home/jwseo/workspace/MTE/midfat/staticlib/sanitizer_common -c -Werror -Wall -flto -fPIC -std=gnu++11 -fno-inline -g -O0 -MMD -o obj/metastack.o metastack.cc
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu++11 -fno-inline -g -O0 -MMD -o obj/metaglobal.o metaglobal.cc
clang -I. -I../metapagetable -c -Werror -Wall -flto -fPIC -std=gnu++11 -fno-inline -g -O0 -MMD -o obj/metautils.o metautils.cc
llvm-ar crv obj/libmetadata.a ./obj/metaset.o ./obj/metacheck.o ./obj/globalinit.o ./obj/argvcopy.o ./obj/compat.o ./obj/metaget.o ./obj/stackinit.o ./obj/metastack.o ./obj/metaglobal.o ./obj/metautils.o
llvm-ranlib obj/libmetadata.a
cp obj/*.o /home/jwseo/workspace/MTE/midfat/autosetup.dir/framework/obj/staticlib-dummy
ls -al /home/jwseo/workspace/MTE/midfat/autosetup.dir/framework/obj/staticlib-dummy/libmetadata.a

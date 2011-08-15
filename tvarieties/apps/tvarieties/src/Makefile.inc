ExtraCXXFLAGS+=-I${SingularPath}/include
LDFLAGS+=-L${SingularPath}/lib -Wl,-rpath,${SingularPath}/lib
LIBS+=-lsingular


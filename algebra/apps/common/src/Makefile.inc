
ifdef SingularPath
   ExtraCXXFLAGS+=-I${SingularPath}/include
   LDFLAGS+=-L${SingularPath}/lib -Wl,-rpath,${SingularPath}/lib
   LIBS+=-lsingular
else
# FIXME disable compilation
# singular$O : 
endif


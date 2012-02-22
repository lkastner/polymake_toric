
ifdef SingularPath
  singular$O : ExtraCXXFLAGS = -I${SingularPath}/include
  LDFLAGS += -L${SingularPath}/lib -Wl,-rpath,${SingularPath}/lib
  LIBS += -lsingular
else
  SharedModules := NONE
#  IgnoredModules := singular FIXME: change to this when supported
endif


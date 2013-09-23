#http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/
#
#
LIBCONFIGREAD_PROGRAM = libconfigread

LIBCONFIGREAD_SOURCES = src/libConfigReader.cc

# Temporary files
LIBCONFIGREAD_OBJS = $(LIBCONFIGREAD_SOURCES:.cc=.o)
LIBCONFIGREAD_DEPS = $(LIBCONFIGREAD_SOURCES:.cc=.P)

CXXFLAGS = -Wall #-Wno-unused-but-set-variable
RELEASE_FLAGS = -O9 -march=native
DEBUG_FLAGS = -ggdb -O0 -DDEBUG
CXX = g++
LD = g++
CTAGS=ctags --c++-kinds=+p --fields=+iaS --extra=+q
LDFLAGS = -lconfig++
RM = rm
MAKEFILE = Makefile

# Dependency generation macro for *.P files
#   Taken from http://make.mad-scientist.net/autodep.html
MAKEDEPEND = $(CXX) -MM $(CXXFLAGS) -o $*.d $<; \
				cp $*.d $*.P; \
				sed -e 's/\#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
				  -e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
				rm -f $*.d


.PHONY: all
all: release

.PHONY: main
main: $(LIBCONFIGREAD_PROGRAM) tags

.PHONY: release
release: CXXFLAGS += $(RELEASE_FLAGS)
release: main

.PHONY: debug
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: main

tags: $(SCWR_SOURCES) $(CLCI_SOURCES)
	${CTAGS} -R .

.PHONY: clean
clean:
	$(RM) -f $(LIBCONFIGREAD_OBJS) $(LIBCONFIGREAD_PROGRAM) $(LIBCONFIGREAD_DEPS) $(LIBCONFIGREAD_SOURCES:.cc=.d)
	$(RM) -f tags

$(LIBCONFIGREAD_PROGRAM): $(LIBCONFIGREAD_OBJS) $(MAKEFILE)
	$(LD) $(LIBCONFIGREAD_OBJS) $(LDFLAGS) $(CXXFLAGS) -o $@


# Object file creation and dependency file (*.P) creation
src/%.o: %.cc $(MAKEFILE)
	@$(MAKEDEPEND)
	$(CXX) $(CXXFLAGS) -c $<


# Include dependencies
-include $(LIBCONFIGREAD_DEPS)

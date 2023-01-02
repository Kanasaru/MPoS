define colorecho
	@tput setaf $1
	@echo $2
	@tput sgr0
endef

LIBNAME = libmpos
VERSION = 1.0.0
CC      = clang
LINKER  = clang

INCDIR  = include
SRCDIR  = src
OBJDIR  = obj
BINDIR  = lib
LIBINC  = /usr/local/include/MPOS
LIBLIB  = /usr/local/lib/$(LIBNAME).a
LIBDYN  = /usr/local/lib/$(LIBNAME)-$(VERSION).dylib

UNAME_S := $(shell uname -s)
OSMAC   = Darwin

CFLAGS  = -I$(INCDIR) -Wall -fPIC
LFLAGS  = -dynamiclib -lSDL2-2.0.0 -lSDL2_image-2.0.0 -lSDL2_ttf-2.0.0 -lSDL2_mixer-2.0.0
VFLAGS  = -current_version $(VERSION) -compatibility_version $(VERSION)

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(BINDIR): $(OBJECTS)
	@ar r $(BINDIR)/$(LIBNAME).a $(OBJECTS)
	@$(LINKER) $(SOURCES) $(LFLAGS) $(VFLAGS) -o $(BINDIR)/$(LIBNAME)-$(VERSION).dylib
	$(call colorecho,6,"Linking complete!")

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c | createdir
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call colorecho,6,"Compiled "$<" successfully!")

createdir:
	$(call colorecho,6,"Create directories...")
	@mkdir -p $(BINDIR)
	@mkdir -p $(OBJDIR)

.PHONY: deploy
deploy:
ifeq ($(UNAME_S),$(OSMAC))
	@rm -f $(LIBLIB)
	@rm -f $(LIBDYN)
	@rm -R $(LIBINC)
	@cp $(BINDIR)/$(LIBNAME).a $(LIBLIB)
	@cp $(BINDIR)/$(LIBNAME)-$(VERSION).dylib $(LIBDYN)
	@cp -R $(INCDIR) $(LIBINC)
	$(call colorecho,6,"Library deployed!")
endif

.PHONY: clean
clean:
	@rm -f $(OBJECTS)
	$(call colorecho,6,"Cleanup complete!")

.PHONY: remove
remove:
	@rm -R $(BINDIR)
	@rm -R $(OBJDIR)
	$(call colorecho,6,"Data removed!")

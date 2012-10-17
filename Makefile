######
##  Default configuration
##
## Modify this configuration by creating a local.config file and resetting the
## variables there. See local.config.sample for an example and a description
## of all used variables.

MODE = RELEASE

AR = ar
ARFLAGS = rcs

CPP = g++
CPPFLAGS += -Iinclude -O3

LD = g++
LDFLAGS = -Lbin

BIN = bin
SRC = src
INC = include
BUILD = build

-include ./local.config

SRC_FILES = $(wildcard $(SRC)/*.cpp)
LIB_FILES = $(wildcard $(LIB)/*.cpp)

SRC_DEPS = $(pathsubst $(SRC)/%.cpp,$(BUILD)/%.d,$(SRC_FILES))
LIB_DEPS = $(pathsubst $(LIB)/%.cpp,$(BUILD)/%.d,$(LIB_FILES))

ALL_DEPS = $(SRC_DEPS) $(LIB_DEPS)

SRC_OBJS = $(pathsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SRC_FILES))
LIB_OBJS = $(pathsubst $(LIB)/%.cpp,$(BUILD)/%.o,$(LIB_FILES))

ALL_OBJS = $(SRC_OBJS) $(LIB_OBJS)

TARGETS = $(pathsubst $(SRC)/%.cpp,$(BIN)/%,$(SRC_FILES))

all: Harmonylib $(TARGETS)

Harmonylib: $(BIN)/libHarmony.a

help:
	@echo Use 'make' to create all programs
	@echo Use 'make boclib' to create the libboc.a
	@echo Special targets:
	@echo "  list           - List all targets"
	@echo "  mkinfo         - List makefile itnernals"
	@echo "  help           - Show this help message"

#Dep file creation
$(BUILD)/%.d: $(SRC)/%.cpp
	@$(CPP) $(CPPFLAGS) -MM -MT $(pathsubst $(SRC)/%.cpp,$(BUILD)/%.o,$<) $< > $@

$(BUILD)/%.d: $(LIB)/%.cpp
	@$(CPP) $(CPPFLAGS) -MM -MT $(pathsubst $(LIB)/%.cpp,$(BUILD)/%.o,$<) $< > $@

#Obj creation
$(BUILD)/%.o:
	@echo Compiling $@
	@$(CPP) $(CPPFLAGS) -c $< -o $@

#Target
$(BIN)%: $(BUILD)/%.o $(LIB_OBJS)
	@echo Linking $@
	@$(LD) -o $@ $(LDFLAGS) $(LIBS) $(LIB_OBJS) $<

$(BIN)/libHarmony.a: $(LIB_OBJS)
	@echo Creating $@
	@$(AR) $(ARFLAGS) $@ $(LIB_OBJS)

-include $(ALL_DEPS)

clean:
	@$(RM) $(ALL_OBJS) $(ALL_DEPS) $(TARGETS) $(BIN)/libboc.a

list:
	@echo Target List
	@echo ----------
	@echo $(TARGETS)

.PHONY: clean distclean mkinfo help
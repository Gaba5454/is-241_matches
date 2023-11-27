CC = gcc

APP_NAME = matchesgame
APP_NAME_TEST = matchestest
LIB_NAME = libmatches
MAT_NAME = matches
RULES_NAME = commonrules
PVP_NAME = gamepvp
CHOOSE_NAME = choosegame
DIFF_NAME = difficulty
CHECK_NAME = checktruth
PVBE_NAME = gamepvbe
PVBH_NAME = gamepvbh

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
CPPFLAGS_TEST = -I thirdparty -I src -MP -MMD
LDFLAGS = 
LDLIBS = 

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH_TEST = $(BIN_DIR)/$(APP_NAME_TEST)
APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = c

APP_SOURCES = $(wildcard $(SRC_DIR)/$(MAT_NAME)/*.c)
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

APP_SOURCES_TEST = $(wildcard $(TEST_DIR)/*.$(SRC_EXT))
APP_OBJECTS_TEST = $(APP_SOURCES_TEST:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.c)
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)
DEPS_TEST = $(APP_OBJECTS_TEST:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
 $(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
 ar rcs $@ $^

$(OBJ_DIR)/$(SRC_DIR)/$(MAT_NAME)/%.o: $(SRC_DIR)/$(MAT_NAME)/%.c
 $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 

$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/%.o: $(SRC_DIR)/$(LIB_NAME)/%.c
 $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 

.PHONY: clean
clean:
 $(RM) $(APP_PATH) $(LIB_PATH) $(APP_PATH_TEST)
 find $(OBJ_DIR) -name '*.o' -exec $(RM) {} +
 find $(OBJ_DIR) -name '*.d' -exec $(RM) {} +

.PHONY: test
test: $(APP_PATH_TEST)

-include $(DEPS_TEST)

$(APP_PATH_TEST): $(APP_OBJECTS_TEST) $(LIB_PATH)
 $(CC) $(CFLAGS) $(CPPFLAGS_TEST) $^ -o $@

# Makefile for Minitalk project

# --- Names ---
CLIENT_NAME	:= client
SERVER_NAME	:= server

# --- Directories ---
SRCDIR      := src
OBJDIR      := obj
INCDIR      := includes
LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

# --- Source Files ---
# Mandatory source files (relative to SRCDIR)
SRC_C_FILES := client.c
SRC_S_FILES := server.c

# For now, assuming bonus logic is within the same files using conditional compilation
SRC_C_BONUS_FILES := client.c # Or client.c client_specific_bonus.c
SRC_S_BONUS_FILES := server.c # Or server.c server_specific_bonus.c

# --- Tools ---
CC          := cc
RM          := rm -f # Shorter alias
MKDIR       := mkdir -p

# --- Flags ---
CFLAGS      := -Wall -Wextra -Werror
# Include flags (for project headers and libft headers)
CPPFLAGS    := -I$(INCDIR) -I$(LIBFT_DIR)/includes -MD # -MD for dependency generation
# Linker flags (to tell linker where to find libft.a)
LDFLAGS     := -L$(LIBFT_DIR)
# Libraries to link (libft and any other system libraries if needed)
LDLIBS      := -lft


# Debugging support (optional: make DEBUG=1)
ifeq ($(DEBUG), 1)
    CFLAGS += -g3 -fsanitize=address
    LDFLAGS += -fsanitize=address
endif


# --- Generate Object File Lists ---
# Mandatory objects
CLIENT_OBJS := $(patsubst %.c, $(OBJDIR)/%.o, $(SRC_C_FILES))
SERVER_OBJS := $(patsubst %.c, $(OBJDIR)/%.o, $(SRC_S_FILES))

# Bonus objects (if bonus sources are different or compiled with different flags)
# These will map to the same .o names if SRC_C_BONUS_FILES is same as SRC_C_FILES
# but will be recompiled with bonus flags if needed.
CLIENT_BONUS_OBJS := $(patsubst %.c, $(OBJDIR)/%.o, $(SRC_C_BONUS_FILES))
SERVER_BONUS_OBJS := $(patsubst %.c, $(OBJDIR)/%.o, $(SRC_S_BONUS_FILES))

# --- Dependency Files ---
# Collect all potential .d files
DEPS := $(CLIENT_OBJS:.o=.d) $(SERVER_OBJS:.o=.d)
# If bonus objects could have different .d files (e.g. different source files)
# add them too. If same .o files, this is covered.
# DEPS += $(CLIENT_BONUS_OBJS:.o=.d) $(SERVER_BONUS_OBJS:.o=.d)
-include $(DEPS)

# --- Build Targets ---
.DEFAULT_GOAL := all

# Mandatory Part
all: $(CLIENT_NAME) $(SERVER_NAME)

# Rule to build Libft
$(LIBFT_A):
	@echo "Compiling Libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# Rule to build the client
$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT_A)
	@echo "Linking $(CLIENT_NAME)..."
	$(CC) $(LDFLAGS) $(CLIENT_OBJS) -o $@ $(LDLIBS)
	@echo "$(CLIENT_NAME) compiled successfully."

# Rule to build the server
$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT_A)
	@echo "Linking $(SERVER_NAME)..."
	$(CC) $(LDFLAGS) $(SERVER_OBJS) -o $@ $(LDLIBS)
	@echo "$(SERVER_NAME) compiled successfully."

# Generic rule to compile .c files from SRCDIR to .o files in OBJDIR
# The $(OBJDIR) after | is an order-only prerequisite, ensuring directory is created first.
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "Compiling $< -> $@"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJDIR):
	$(MKDIR) $@

# Bonus Part
# This rule will recompile client and server with bonus features.
# It first cleans, then calls `make all` with an additional BONUSB CFLAG.
# BONUSB is used to avoid conflict if Libft's Makefile also has a BONUS flag.
bonus: fclean
	@echo "Compiling Minitalk with Bonus Features..."
	@$(MAKE) all CPPFLAGS="$(CPPFLAGS) -DBONUSB=1" CFLAGS="$(CFLAGS) -DBONUSB=1"

# --- Cleaning Rules ---
clean:
	@echo "Cleaning Minitalk object files..."
	$(RM) -r $(OBJDIR)
	@echo "Cleaning Libft..."
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "Clean complete."

fclean: clean
	@echo "Cleaning Minitalk executables..."
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@echo "Fcleaning Libft..."
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "Fclean complete."

re: fclean all

# Recompile bonus version
rebonus: fclean bonus

# --- Phony Targets ---
.PHONY: all clean fclean re bonus rebonus libft

# Prevent .d files from being removed by intermediate rule processing if objects are remade
.SECONDARY: $(DEPS) $(CLIENT_OBJS) $(SERVER_OBJS)
# Delete targets if their recipe fails
.DELETE_ON_ERROR:

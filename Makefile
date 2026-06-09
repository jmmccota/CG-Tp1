SRC_DIR  := CG-Tp1
BIN_DIR  := CG-Tp1
OBJ_DIR  := build

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# ── Windows (cross-compile or native MinGW) ───────────────────────────────────
ifeq ($(OS),Windows_NT)
    TARGET   := $(BIN_DIR)/CG-Tp1.exe
    CXX      := g++
    CXXFLAGS := -std=c++14 -Wall -O2 -DWIN32
    INC      := -I$(SRC_DIR) -Ifreeglut/include -Ifmod/inc
    LDFLAGS  := -Lfreeglut/lib -Lfmod/lib \
                -lfreeglut -lopengl32 -lglu32 \
                -lfmodex_vc
    RM       := del /Q
    MKDIR    := mkdir
else
# ── Linux ─────────────────────────────────────────────────────────────────────
    TARGET   := $(BIN_DIR)/CG-Tp1
    CXX      := g++
    CXXFLAGS := -std=c++14 -Wall -O2
    INC      := -I$(SRC_DIR) -Ifmod/inc
    LDFLAGS  := -lGL -lGLU -lglut
    RM       := rm -f
    MKDIR    := mkdir -p
endif

# ── Rules ─────────────────────────────────────────────────────────────────────
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)/*.o $(TARGET)

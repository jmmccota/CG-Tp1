# CG-Tp1

Agradecimento aos colaboradores, sem eles esse trabalho não seria magnífico como foi:

* [André](https://github.com/andrmalta);

* [Daniel](https://github.com/daniel22390);

* [Elias](https://github.com/EliasLuiz);

* [Henrique](https://github.com/henriqfc);

* [João](https://github.com/jmmccota).

***

## Build

### Linux

**Dependencies:**
```bash
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev libgl1-mesa-dev
```

**Build + copy libs:**
```bash
./build.sh
```

Binary output: `CG-Tp1/CG-Tp1`

---

### Windows (MinGW)

**Dependencies:** MinGW-w64 with `g++` in PATH.

The bundled `freeglut/` and `fmod/` directories are already included in the repo.

**Build + copy DLLs:**
```bat
build.bat
```

Binary output: `CG-Tp1\CG-Tp1.exe`

---

### Clean
```bash
make clean
```

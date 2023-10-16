# vtk2geogram : .vtk to .geogram mesh file conversion

## Motivation

[AlgoHex](https://github.com/cgg-bern/AlgoHex) is a hex-meshing algorithm that can leverage the `CELL_DATA` section of VTK files for feature-aware meshing.

A typical input dataset is [HexMe](https://www.algohex.eu/publications/hex-me-if-you-can/), which uses [a Gmsh Python script](https://github.com/cgg-bern/hex-me-if-you-can/blob/main/scripts/tetme.py) to generate such VTK files.

In order to explore this representation and to develop feature-aware meshing algorithms, I wanted to convert CAD-related data to [Geogram attributes](https://github.com/BrunoLevy/geogram/wiki/Mesh#attributes).

## Limits

- expects a tetrahedral mesh
- writes 4 files, maybe it's possible to bundle everything in a single file
- you have to import the 4 files into [Graphite](https://github.com/brunolevy/GraphiteThree), switch the painting mode into "ATTRIBUTE". A Lua script could do the job for you
- export all mesh components (points, lines, triangles, tetrahedral) even if they don't have CAD features associated

## Requirements

- a C++ 17 compiler
- [CMake](https://cmake.org/)
- [UltiMaille](https://github.com/ssloy/ultimaille) (included as submodule)
- [Graphite](https://github.com/BrunoLevy/GraphiteThree) or [Vorpaview](https://github.com/BrunoLevy/geogram/wiki/Vorpaview), to visualize the output `.geogram` files

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Run

```bash
./vtk2geogram ../data/S0.vtk
```

will create 4 files:
- `../data/S0.vtk.point_set.geogram`
- `../data/S0.vtk.polyline.geogram`
- `../data/S0.vtk.triangles.geogram`
- `../data/S0.vtk.tetrahedra.geogram`

that you can open with [Graphite](https://github.com/brunolevy/GraphiteThree).
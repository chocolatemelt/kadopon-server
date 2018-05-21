カドポン村
==========

Server implementation for web-based board game [kadopon-village](https://github.com/parkt2/kadopon-village).

## Setup

Requires [Boost](https://www.boost.org/), [OpenSSL](https://www.openssl.org/)
and [CMake](https://cmake.org/) > 3.0. For those unfamiliar with setting up
Boost, check out the [installation guide](https://theboostcpplibraries.com/introduction-installation)
and point CMake to the Boost root.

Note: CMake relies on FindBoost, which is generally compatible with only very
specific versions of Boost and lower. At the time of writing, I would highly
advise against using Boost 1.67.0 unless you plan on using the latest *build* of
CMake (not the current release version, 3.11.2). If you have issues with Boost,
you likely need to upgrade CMake or downgrade Boost.

OSX: OpenSSL is included in High Sierra (and possibly lower versions, though
I'm not sure). You don't have to do anything since it should be included by
CMake by default.

### Building

```sh
mkdir build && cd build
cmake ..
make
```

### Running

The executable by default gets stored in the `bin` directory.

```sh
./bin/kadopon
```

### Tests

The kadopon tests are in the `tests` directory, but you should run them through
the catch binary. Adding tests is simple; just make sure you add any new files
to the `CMakeLists.txt` in `tests`.

```sh
./bin/kadotest
```

## More info
See [kadopon/docs](https://github.com/parkt2/kadopon-village/wiki).

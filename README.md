カドポン村
==========

Server implementation for web-based board game [kadopon-village](https://github.com/parkt2/kadopon-village).

## Setup

Requires [Boost](https://www.boost.org/) and [CMake](https://cmake.org/) > 3.0. For those unfamiliar with setting up Boost, check out the [installation guide](https://theboostcpplibraries.com/introduction-installation) and point CMake to the Boost root.

Note: CMake relies on FindBoost, which is generally compatible with only very specific versions of Boost and lower. At the time of writing, I would highly advise against using Boost 1.67.0 unless you plan on using the latest *build* of CMake (not the current release version, 3.11.2). If you have issues with Boost, you likely need to upgrade CMake or downgrade Boost.

### Building

```sh
mkdir build && cd build
cmake ..
```

### Running

### Tests

## More info
See [kadopon/docs](https://github.com/parkt2/kadopon-village/wiki).

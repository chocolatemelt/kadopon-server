/**
 * Internal Kadopon engine-scope API interface.
 */
#pragma once

namespace Kadopon {
  class KadoponAPI {
  public:
    KadoponAPI() {}
    virtual ~KadoponAPI() {}

    virtual void init() = 0;
    virtual void deinit() = 0;
  };
}

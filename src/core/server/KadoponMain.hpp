/**
 * The Kadopon server authoritatively handles game instances and provides an entrypoint to starting,
 * reloading, and cleaning up games.
 */
#pragma once

namespace Kadopon {
  class KadoponMain {
  public:
    static int runner();
  };
}

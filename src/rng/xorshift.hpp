/**
 * Simple shift-and-xor random number generator. This
 * implementation provides an optimal period for its storage size,
 * passes most empirical tests, and is faster and smaller than
 * more popular approaches like MT.
 *
 * However, it is insecure. Don't use it as a source of
 * cryptographic randomness.
 *
 * See www.jstatsoft.org/v08/i14/paper for the algorithm, and
 * www.open-std.org/jtc1/sc22/wg21/docs/papers/2003/n1452.html
 * for the structure.
 */
#pragma once

#include <cstdint>

class xorshift {
public:
  typedef std::uint32_t result_type;

  struct state_type {
    result_type x;
    result_type y;
    result_type z;
    result_type w;
  };

  xorshift(void);
  explicit xorshift(result_type r);
  explicit xorshift(const state_type &seed);

  void seed(void);
  void seed(result_type r);
  void seed(const state_type &state);

  // Generate a uniformly-distributed random integer of
  // result_type.
  result_type operator()(void);

  // Discard the next z random values.
  void discard(unsigned long long z);

  // Get or set the entire state. This can be used to store
  // and later re-load the state in any format.
  const state_type &state(void) const;
  void state(const state_type &state);

  // Random number bounds. Used by random distributions; you
  // probably don't need to call these directly.
  static result_type min(void);
  static result_type max(void);

private:
  state_type state_;
};

// Two engines compare as equal if their states are
// bitwise-identical, i.e. if they would generate the same
// numbers forever.
bool operator==(const xorshift &lhs, const xorshift &rhs);
bool operator!=(const xorshift &lhs, const xorshift &rhs);

#pragma once

/*
 * cubic Lagrange implementation will work and may even show better SNR measurements
 * in some cases, but the Hermite approach provides more musically acceptable results
 * due to its superior handling of aliasing and smoother spectral behavior. For
 * professional audio applications, the consensus strongly favors Hermite-based methods.
 */

class Sampler
{
  public:
};
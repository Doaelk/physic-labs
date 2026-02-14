#pragma once

namespace pl 
{
inline float calcRes(const float U, const float I){ return U/I; }
inline float calcPow(const float I, const float R){ return I*I/R; }
}

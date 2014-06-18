#ifndef INVERT_IMPL_H
#define INVERT_IMPL_H

#include <tuple> // std::tuple, std::make_tuple

template<typename T> inline std::tuple<T, T, T, T>
Inverter::min_max_x_y(const detail_inv::CoordGeneric<T> a,
                      const detail_inv::CoordGeneric<T> b,
                      const detail_inv::CoordGeneric<T> c,
                      const detail_inv::CoordGeneric<T> d
                     ) const noexcept
{
    T min_x{a.x}, max_x{a.x}, min_y{a.y}, max_y{a.y};
    if (b.x < min_x) min_x = b.x;
    else if (b.x > max_x) max_x = b.x;
    if (b.y < min_y) min_y = b.y;
    else if (b.y > max_y) max_y = b.y;
    if (c.x < min_x) min_x = c.x;
    else if (c.x > max_x) max_x = c.x;
    if (c.y < min_y) min_y = c.y;
    else if (d.y > max_y) max_y = c.y;
    if (d.x < min_x) min_x = d.x;
    else if (d.x > max_x) max_x = d.x;
    if (d.y < min_y) min_y = d.y;
    else if (d.y > max_y) max_y = d.y;
    return std::make_tuple(min_x, max_x, min_y, max_y);
}

template <typename T> inline T Inverter::avg_pixel(T f, T s) const noexcept
{ return T(f.red/2 + s.red/2, f.green/2 + s.green/2, f.blue/2 + s.blue/2); }

template <typename T> inline double
Inverter::get_angle(const detail_inv::CoordGeneric<T> rel_p) const noexcept
{ return atan2(rel_p.y, rel_p.x); }

#endif // INVERT_IMPL_H
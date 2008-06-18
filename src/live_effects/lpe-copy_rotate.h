#ifndef INKSCAPE_LPE_COPY_ROTATE_H
#define INKSCAPE_LPE_COPY_ROTATE_H

/** \file
 * LPE <copy_rotate> implementation, see lpe-copy_rotate.cpp.
 */

/*
 * Authors:
 *   Johan Engelen
 *
 * Copyright (C) Johan Engelen 2007 <j.b.c.engelen@utwente.nl>
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#include "live_effects/effect.h"
#include "live_effects/parameter/point.h"

namespace Inkscape {
namespace LivePathEffect {

namespace CR {
  // we need a separate namespace to avoid clashes with LPEPerpBisector
  class KnotHolderEntityAngle;
}

class LPECopyRotate : public Effect {
public:
    LPECopyRotate(LivePathEffectObject *lpeobject);
    virtual ~LPECopyRotate();

    virtual void doOnApply (SPLPEItem *lpeitem);

    virtual Geom::Piecewise<Geom::D2<Geom::SBasis> > doEffect_pwd2 (Geom::Piecewise<Geom::D2<Geom::SBasis> > const & pwd2_in);

    /* the knotholder entity classes must be declared friends */
    friend class CR::KnotHolderEntityAngle;

private:
    ScalarParam angle;
    ScalarParam num_copies;

    PointParam origin;
    BoolParam include_original;

    Geom::Point A;
    Geom::Point B;
    Geom::Point dir;
    double dist_angle_handle;

    LPECopyRotate(const LPECopyRotate&);
    LPECopyRotate& operator=(const LPECopyRotate&);
};

} //namespace LivePathEffect
} //namespace Inkscape

#endif

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4 :
